#include "../include/Armor.hpp"

namespace xz_rm
{
    Armor::Armor(const Lightbar &left, const Lightbar &right) : left_lightbar(left), right_lightbar(right)
    {
        // std::cout << "装甲板初始化" << std::endl;

        color = left_lightbar.color;
        center = (left_lightbar.center + right_lightbar.center) / 2;

        points.emplace_back(right_lightbar.top_median);
        points.emplace_back(left_lightbar.top_median);
        points.emplace_back(left_lightbar.bottom_median);
        points.emplace_back(right_lightbar.bottom_median);

        auto left2right = right_lightbar.center - left_lightbar.center;
        auto width = cv::norm(left2right);

        auto max_lightbar_length = std::max(left_lightbar.length, right_lightbar.length);
        auto min_lightbar_length = std::min(left_lightbar.length, right_lightbar.length);

        ratio = width / max_lightbar_length;
        side_ratio = max_lightbar_length / min_lightbar_length;

        auto roll = std::atan2(left2right.y, left2right.x);
        auto left_rectangular_error = std::abs(left_lightbar.angle - roll - CV_PI / 2);
        auto right_rectangular_error = std::abs(right_lightbar.angle - roll - CV_PI / 2);
        rectangular_error = std::max(left_rectangular_error, right_rectangular_error);
    };
};