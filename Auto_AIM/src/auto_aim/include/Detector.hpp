#ifndef DETECTOR_HPP_
#define DETECTOR_HPP_

#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "Armor.hpp"
#include <list>
#include <cmath>
#include <vector>

namespace xz_rm
{
    class Detector
    {
    public:
        void start_detector();

    private:
        std::list<Armor> detect(const cv::Mat &bgr_img);
        bool check_geometry(const Lightbar &Lightbar);
        bool check_geometry(const Armor &armor);
        bool check_name(const Armor &armor);

        Color get_color(const cv::Mat &bgr_img, const std::vector<cv::Point> &contour);
        cv::Mat get_ROI(const cv::Mat &bgr_img, const Armor &armor);

        void classify(Armor &armor);
    };
}

#endif