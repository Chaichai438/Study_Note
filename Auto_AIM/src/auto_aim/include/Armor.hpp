#ifndef ARMOR_HPP_
#define ARMOR_HPP_

#include "Lightbar.hpp"

#include <iostream>
#include <opencv4/opencv2/opencv.hpp>

namespace xz_rm
{
    class Armor
    {
    public:
        Color color;
        const Lightbar left_lightbar, right_lightbar;
        cv::Point2f center;      // 不是对角线交点
        cv::Point2f center_norm; // 归一化坐标
        std::vector<cv::Point2f> points;

        double ratio;             // 两灯条的中点连线与长灯条的长度之比
        double side_ratio;        // 长灯条与短灯条的长度之比
        double rectangular_error; // 灯条和中点连线所成夹角与π/2的差值

        ArmorType type;
        ArmorName name;
        ArmorPriority priority;
        cv::Mat ROI;
        double confidence; // 可信度
        bool duplicated;

        double yaw_raw;

        Armor(const Lightbar &left, const Lightbar &right);
    };
}

#endif