#include "../include/Detector.hpp"
#include "../include/img_tools.hpp"
#include <fmt/format.h>

namespace xz_rm
{
    void Detector::start_detector()
    {
        std::cout << "识别已启动" << std::endl;

        Detector detector_01;
        std::list<Armor> armors;

        cv::VideoCapture video;
        video.open(0);
        if (!video.isOpened())
        {
            std::cerr << "无法打开摄像头！" << std::endl;
            exit(0);
        }

        while (1)
        {
            cv::Mat bgr_img;
            video.read(bgr_img);
            armors = detector_01.detect(bgr_img);

            cv::Mat draw_armor = bgr_img.clone();

            // std::cout << " 这是before绘图函数" << std::endl;
            for (const auto &armor : armors)
            {
                std::cout << " 这是绘图函数" << std::endl;
                img_tools::draw_points(draw_armor, armor.points);
                img_tools::draw_text(
                    draw_armor,
                    fmt::format("{},{}{:.2f}", COLORS[armor.color], ARMOR_NAMES[armor.name], armor.confidence),
                    armor.left_lightbar.top_median);
            }
            imshow("draw_armor", draw_armor);

            auto key = cv::waitKey(25);
            if (key == 'q')
            {
                break;
            }
        }
    }

    std::list<Armor> Detector::detect(const cv::Mat &bgr_img)
    {
        // std::cout << "开始检测装甲板" << std::endl;
        cv::Mat gray_img;
        cv::cvtColor(bgr_img, gray_img, cv::COLOR_BGR2GRAY);

        cv::Mat binary_img;
        cv::threshold(gray_img, binary_img, 165, 255, cv::THRESH_BINARY);

        cv::namedWindow("img", cv::WINDOW_AUTOSIZE);
        cv::imshow("img", binary_img);

        std::vector<std::vector<cv::Point>> contours;
        cv::findContours(binary_img, contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_NONE);

        std::size_t lightbar_id = 0;
        std::list<Lightbar> lightbars;
        for (const auto &contour : contours)
        {
            auto rotated_rect = cv::minAreaRect(contour);
            auto lightbar = Lightbar(rotated_rect, lightbar_id);

            if (!check_geometry(lightbar))
                continue;

            lightbar.color = get_color(bgr_img, contour);
            lightbars.emplace_back(lightbar);
            lightbar_id += 1;
        }

        lightbars.sort([](const Lightbar &lib_1, const Lightbar &lib_2)
                       { return lib_1.center.x < lib_2.center.x; });

        std::list<Armor> armors;

        for (auto left = lightbars.begin(); left != lightbars.end(); left++)
        {
            for (auto right = std::next(left); right != lightbars.end(); right++)
            {
                if (left->color != right->color)
                    continue;

                auto armor = Armor(*left, *right);
                if (!check_geometry(armor))
                    continue;

                armor.ROI = get_ROI(bgr_img, armor);

                classify(armor);
                if (!check_name(armor))
                    continue;

                armors.emplace_back(armor);
            }
        }

        return armors;
    }

    bool Detector::check_geometry(const Lightbar &lightbar)
    {
        // std::cout << "check_geometry1" << std::endl;
        auto angle_ok = (lightbar.angle_error * 57.3) < 45; // degree
        auto ratio_ok = lightbar.ratio > 1.5 && lightbar.ratio < 20;
        auto length_ok = lightbar.length > 8;
        return angle_ok && ratio_ok && length_ok;
    }

    bool Detector::check_geometry(const Armor &armor)
    {
        // std::cout << "check_geometry2" << std::endl;
        auto ratio_ok = armor.ratio > 1 && armor.ratio < 5;
        auto side_ratio_ok = armor.side_ratio < 1.5;
        auto rectangular_error_ok = (armor.rectangular_error * 57.3) < 25;
        return ratio_ok && side_ratio_ok && rectangular_error_ok;
    }

    bool Detector::check_name(const Armor &armor)
    {
        // std::cout << "check_name" << std::endl;
        bool name = armor.name != ArmorName::Unknow;
        bool confidence = armor.confidence > 0.8;

        return name && confidence;
    }

    Color Detector::get_color(const cv::Mat &bgr_img, const std::vector<cv::Point> &contour)
    {
        // std::cout << "get_color" << std::endl;
        int red_sum = 0;
        int blue_sum = 0;

        for (const auto &point : contour)
        {
            red_sum += bgr_img.at<cv::Vec3b>(point)[2];
            blue_sum += bgr_img.at<cv::Vec3b>(point)[0];
        }

        return blue_sum > red_sum ? Color::Blue : Color::Red;
    }

    cv::Mat Detector::get_ROI(const cv::Mat &bgr_img, const Armor &armor)
    {
        // std::cout << "get_ROI" << std::endl;
        auto top_left = armor.left_lightbar.center - armor.left_lightbar.top2bottom * 1.125;
        auto bottom_left = armor.left_lightbar.center + armor.left_lightbar.top2bottom * 1.125;
        auto top_right = armor.right_lightbar.center - armor.right_lightbar.top2bottom * 1.125;
        auto bottom_right = armor.right_lightbar.center - armor.right_lightbar.center * 1.125;

        auto roi_left = std::max<int>(std::min(top_left.x, bottom_left.x), 0);
        auto roi_right = std::min<int>(std::max(top_right.x, bottom_right.x), bgr_img.cols);
        auto roi_top = std::max<int>(std::min(top_left.y, top_right.y), 0);
        auto roi_bottom = std::max<int>(std::min(bottom_left.y, bottom_right.y), bgr_img.rows);

        auto roi_top_left = cv::Point(roi_left, roi_top);
        auto roi_bottom_right = cv::Point(roi_right, roi_bottom);

        auto ROI = cv::Rect(roi_top_left, roi_bottom_right);

        return bgr_img(ROI);
    }

    void Detector::classify(Armor &armor)
    {
        // std::cout << "classify" << std::endl;
        cv::dnn::Net net = cv::dnn::readNetFromONNX("/home/chaichai/project/Study_Note/Auto_AIM/src/auto_aim/tiny_resnet.onnx");
        std::cout << "数字识别模型加载成功" << std::endl;

        if (net.empty())
        {
            std::cerr << ("数字识别模型加载出错") << std::endl;
        }

        cv::Mat gray;
        cv::cvtColor(armor.ROI, gray, cv::COLOR_BGR2GRAY);

        auto input = cv::Mat(32, 32, CV_8UC1, cv::Scalar(0));

        auto x_scale = static_cast<double>(32) / gray.cols;
        auto y_scale = static_cast<double>(32) / gray.rows;
        auto scale = std::min(x_scale, y_scale);

        auto height = static_cast<int>(gray.rows * scale);
        auto width = static_cast<int>(gray.cols * scale);
        auto roi = cv::Rect(0, 0, width, height);
        cv::resize(gray, input(roi), cv::Size(width, height));

        cv::namedWindow("输入", cv::WINDOW_AUTOSIZE);
        imshow("输入", input);

        auto blob = cv::dnn::blobFromImage(input, 1.0 / 255.0, cv::Size(), cv::Scalar());

        net.setInput(blob);
        cv::Mat outputs = net.forward();

        // Softmax
        // 用于将模型的输出转化为概率分布

        float max = *std::max_element(outputs.begin<float>(), outputs.end<float>());
        cv::exp(outputs - max, outputs);
        float sum = cv::sum(outputs)[0];
        outputs /= sum;

        double confidence;
        cv::Point label_point;
        cv::minMaxLoc(outputs.reshape(1, 1), nullptr, &confidence, nullptr, &label_point);
        int label_id = label_point.x;

        armor.confidence = confidence;

        if (confidence > 0.5 && confidence < 1.0)
            std::cout << confidence << std::endl;

        armor.name = static_cast<ArmorName>(label_id);
    }
}