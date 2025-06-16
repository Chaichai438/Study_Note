#ifndef TOOLS__IMG_TOOLS_HPP_
#define TOOLS__IMG_TOOLS_HPP_

#include <opencv2/opencv.hpp>

namespace img_tools
{
    // 绘图函数，依次传入：图像、点
    inline void draw_points(
        cv::Mat &img, const std::vector<cv::Point> &points,
        const cv::Scalar &color = cv::Scalar(0, 0, 255), int thickness = 2)
    {
        std::vector<std::vector<cv::Point>> contours;
        contours.emplace_back(points);
        cv::drawContours(img, contours, -1, color, thickness);
    }

    inline void draw_points(
        cv::Mat &img, const std::vector<cv::Point2f> &points,
        const cv::Scalar &color = cv::Scalar(0, 0, 255), int thickness = 2)
    {
        std::vector<cv::Point> int_points(points.begin(), points.end());
        draw_points(img, int_points, color, thickness);
    }
    // 绘图函数，依次传入：图像、字符串、显示位置
    inline void draw_text(
        cv::Mat &img, const std::string &text, const cv::Point &point, double font_scale = 1.0,
        const cv::Scalar &color = cv::Scalar(0, 255, 255), int thickness = 2)
    {
        cv::putText(img, text, point, cv::FONT_HERSHEY_SIMPLEX, font_scale, color, thickness);
    }
}

#endif