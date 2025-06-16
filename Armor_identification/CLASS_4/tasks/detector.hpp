#ifndef AUTO_AIM__DETECTOR_HPP
#define AUTO_AIM__DETECTOR_HPP

#include <list>
#include <opencv2/opencv.hpp>

#include "armor.hpp"

namespace auto_aim
{
class Detector
{
public:
  std::list<Armor> detect(const cv::Mat & bgr_img);

private:
  bool check_geometry(const Lightbar & lightbar);  //灯条匹配条件
  bool check_geometry(const Armor & armor);        //装甲板匹配条件
  bool check_name(const Armor & armor);            //id匹配条件

  Color get_color(const cv::Mat & bgr_img, const std::vector<cv::Point> & contour);  //获取灯条颜色
  cv::Mat get_pattern(const cv::Mat & bgr_img, const Armor & armor);  //获得装甲板角点

  void classify(Armor & armor);

};  // namespace auto_aim
}  // namespace auto_aim
#endif
