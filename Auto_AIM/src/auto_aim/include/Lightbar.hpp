#ifndef LIGHTBAR_HPP_
#define LIGHTBAR_HPP_

#include "Important_Params.hpp"

#include <iostream>
#include <opencv2/opencv.hpp>
#include <vector>

namespace xz_rm
{

    class Lightbar
    {
    public:
        std::size_t id;
        Color color;
        cv::Point2f center, top_median, bottom_median, top2bottom;

        std::vector<cv::Point2f> points;
        double angle, angle_error, length, width, ratio;

        Lightbar(const cv::RotatedRect &rotated_rect, std::size_t id);
    };
};

#endif