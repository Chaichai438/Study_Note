#include <opencv4/opencv2/opencv.hpp>

#include "fmt/format.h"
#include "include/armor.hpp"
#include "include/img_tools.hpp"
#include "iostream"
#include "tasks/detector.hpp"

using namespace cv;
using namespace auto_aim;
using namespace std;
using namespace tools;

static const double LIGHTBAR_LENGTH = 0.056;  // 灯条长度    单位：米
static const double ARMOR_WIDTH = 0.135;      // 装甲板宽度  单位：米

int main()
{
  Detector detector;
  // Plotter plotter;
  list<Armor> armors;
  VideoCapture video("/home/chaichai/project/All_study/同济大学代码研究/imgs/8radps.avi");

  while (1) {
    Mat bgr_img;
    video.read(bgr_img);
    armors = detector.detect(bgr_img);
    //nlohmann::json data;
    // data[0] = armors.front().center.x;
    // data[1] = armors.front().center.y;
    // plotter.plot(data);

    Mat draw_armor = bgr_img.clone();

    for (const auto & armor : armors) {
      draw_points(draw_armor, armor.points);
      draw_text(
        draw_armor,
        fmt::format("{},{}{:.2f}", COLORS[armor.color], ARMOR_NAMES[armor.name], armor.confidence),
        armor.left.top);
    }
    imshow("draw_armor", draw_armor);
    auto key = waitKey(25);
    if (key == 'q') {
      break;
    }
  }
  return 0;
}