#include "../include/Lightbar.hpp"

namespace xz_rm
{
    Lightbar::Lightbar(const cv::RotatedRect &rotated_rect, std::size_t id)
    {
        //  std::cout << "灯条初始化" << std::endl;
        std::vector<cv::Point2f> corners(4);
        rotated_rect.points(&corners[0]);

        std::sort(corners.begin(), corners.end(), [](const cv::Point2f &a, const cv::Point2f &b)
                  { return a.y < b.y; });
        /*排序后，corners[0]和corners[1]是y坐标较小的两个点（即矩形的上边两个角点），corners[2]和corners[3]是y坐标较大的两个点（即矩形的下边两个角点）。*/

        center = rotated_rect.center;
        top_median = (corners[0] + corners[1]) / 2;
        bottom_median = (corners[2] + corners[3]) / 2;
        top2bottom = bottom_median - top_median;

        points.emplace_back(top_median);
        points.emplace_back(bottom_median);

        length = cv::norm(top2bottom);             // 长
        width = cv::norm(corners[0] - corners[1]); // 宽
        ratio = length / width;

        angle = std::atan2(top2bottom.y, top2bottom.x);
        angle_error = std::abs(angle - CV_PI / 2);
    }
}