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
};  // 定义一个颜色（枚举类型）
const std::vector<std::string> COLORS = {
  "red", "blue", "purple"};  // 用一个字符串类型的vector容器存储

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
  sentry,    // 哨兵
  outpost,   // 前哨基地
  base,      // 基地
  not_armor  // 无装甲板
};
const std::vector<std::string> ARMOR_NAMES = {"one",    "two",     "three", "four",     "five",
                                              "sentry", "outpost", "base",  "not_armor"};

enum ArmorPriority
{
  first = 1,  // first 被显式地赋值为 1
  second,     // 隐式地依次被赋值为 2、3、4 和 5
  third,
  fourth,
  fifth
};

struct Lightbar  // 灯带
{
  std::size_t id;                               // size_t的数据类型是 unsigned long
  Color color;                                  // 灯带颜色
  cv::Point2f center, top, bottom, top2bottom;  // 灯带的中心，上顶点，下顶点，
  std::vector<cv::Point2f> points;
  double angle, angle_error, length, ratio;

  Lightbar(const cv::RotatedRect & rotated_rect, std::size_t id)
  {
    std::vector<cv::Point2f> corners(4);
    rotated_rect.points(&corners[0]);  // 将旋转矩形的四个角点填充到corners向量的起始位置
    std::sort(corners.begin(), corners.end(), [](const cv::Point2f & a, const cv::Point2f & b) {
      return a.y < b.y;
    });

    center = rotated_rect.center;
    top = (corners[0] + corners[1]) / 2;
    bottom = (corners[2] + corners[3]) / 2;
    top2bottom = bottom - top;

    points.emplace_back(top);
    points.emplace_back(bottom);

    auto width = cv::norm(corners[0] - corners[1]);  // 用opencv提供的API计算向量的模
    angle = std::atan2(top2bottom.y, top2bottom.x);  // 计算角度
    angle_error = std::abs(angle - CV_PI / 2);       // 计算角误差
    length = cv::norm(top2bottom);
    ratio = length / width;  // 长宽之比
  };
};

struct Armor
{
  Color color;                 // 装甲板颜色
  const Lightbar left, right;  // 左灯带、右灯带
  cv::Point2f center;          // 不是对角线交点，不能作为实际中心！
  cv::Point2f center_norm;     // 归一化坐标
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

  Armor(const Lightbar & left, const Lightbar & right) : left(left), right(right)
  {
    //task8 根据参数获得颜色、中心、装甲板四个点的points、宽度、最大灯条长度、最小灯条长度、以及宽度与最大等条长度比值、最大和最小长度的比值的初始化（所有结构体中未出现的值皆用auto修饰）
    color = left.color;
    center = (left.center + right.center) / 2;

    points.emplace_back(left.top);
    points.emplace_back(right.top);
    points.emplace_back(right.bottom);
    points.emplace_back(left.bottom);

    auto left2right = right.center - left.center;
    auto width = cv::norm(left2right);
    auto max_lightbar_length = std::max(left.length, right.length);
    auto min_lightbar_length = std::min(left.length, right.length);
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