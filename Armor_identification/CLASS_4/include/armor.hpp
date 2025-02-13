#ifndef AUTO_AIM__ARMOR_HPP
#define AUTO_AIM__ARMOR_HPP

#include <opencv2/opencv.hpp>
#include <string>
#include <vector>

namespace auto_aim
{
enum Color
{
  red,
  blue,
  purple
};
const std::vector<std::string> COLORS = {"red", "blue", "purple"};

enum ArmorType
{
  big,
  small
};
const std::vector<std::string> ARMOR_TYPES = {"big", "small"};

enum ArmorName
{
  one,
  two,
  three,
  four,
  five,
  sentry,
  outpost,
  base,
  not_armor
};
const std::vector<std::string> ARMOR_NAMES = {"one",    "two",     "three", "four",     "five",
                                              "sentry", "outpost", "base",  "not_armor"};

enum ArmorPriority
{
  first = 1,
  second,
  third,
  forth,
  fifth
};

struct Lightbar
{
  std::size_t id;
  Color color;
  cv::Point2f center, top, bottom, top2bottom;
  std::vector<cv::Point2f> points;
  double angle, angle_error, length, ratio;

  Lightbar(const cv::RotatedRect & rotated_rect, std::size_t id)  //获取灯条的特征
  {
    //task9 根据形参获得 灯条旋转矩形的四个点，并按高度由大到小排序、获得等条中心、顶点、底点、顶点到底点的向量点、宽度、倾斜角、长度、长宽比ratio初始化（所有结构体中未出现的值皆用auto修饰）
    std::vector<cv::Point2f> corners(4);
    rotated_rect.points(&corners[0]);

    std::sort(corners.begin(), corners.begin(), [](const cv::Point2f & p1, const cv::Point2f & p2) {
      return p1.y < p2.y;
    });  //排序

    center = rotated_rect.center;
    top = (corners[0] + corners[1]) / 2;
    bottom = (corners[2] + corners[3]) / 2;
    top2bottom = bottom - top;

    points.emplace_back(top);
    points.emplace_back(bottom);

    auto width = cv::norm(corners[0] - corners[1]);  //宽度
    length = cv::norm(top2bottom);                   //长度
    ratio = length / width;                          //长宽之比

    angle = std::atan2(top2bottom.y, top2bottom.x);  //计算角度
    angle_error = std::abs(angle - CV_PI / 2);       // 计算角误差

    //
  };
};

struct Armor
{
  Color color;
  const Lightbar left, right;
  cv::Point2f center;       // 不是对角线交点，不能作为实际中心！
  cv::Point2f center_norm;  // 归一化坐标
  std::vector<cv::Point2f> points;

  double ratio;              // 两灯条的中点连线与长灯条的长度之比
  double side_ratio;         // 长灯条与短灯条的长度之比
  double rectangular_error;  // 灯条和中点连线所成夹角与π/2的差值

  ArmorType type;
  ArmorName name;
  ArmorPriority priority;
  cv::Mat pattern;
  double confidence;
  bool duplicated;

  double yaw_raw;  // rad

  //获得装甲板的参数
  Armor(const Lightbar & left, const Lightbar & right) : left(left), right(right)
  {
    //task8 根据参数获得颜色、中心、装甲板四个点的points、宽度、最大灯条长度、最小灯条长度、以及宽度与最大等条长度比值、最大和最小长度的比值的初始化（所有结构体中未出现的值皆用auto修饰）
    color = left.color;                         //颜色
    center = (left.center + right.center) / 2;  //中心点

    points.emplace_back(left.top);
    points.emplace_back(right.top);
    points.emplace_back(left.bottom);
    points.emplace_back(right.bottom);  //装甲板四个点

    auto left2right = right.center - left.center;                    //两灯条的中点连线
    auto width = cv::norm(left2right);                               //宽度
    auto max_lightbar_length = std::max(left.length, right.length);  //最大灯条长度
    auto min_lightbar_length = std::min(left.length, right.length);  //最小灯条长度
    ratio = width / max_lightbar_length;
    side_ratio = max_lightbar_length / min_lightbar_length;

    auto roll = std::atan2(left2right.y, left2right.x);
    auto left_rectangular_error = std::abs(left.angle - roll - CV_PI / 2);
    auto right_rectangular_error = std::abs(right.angle - roll - CV_PI / 2);
    rectangular_error = std::max(left_rectangular_error, right_rectangular_error);
  };
};

}  // namespace auto_aim

#endif  // AUTO_AIM__ARMOR_HPP