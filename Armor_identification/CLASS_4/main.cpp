#include <opencv2/ml.hpp>
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
using namespace cv::ml;

static const double LIGHTBAR_LENGTH = 0.056;  // 灯条长度    单位：米
static const double ARMOR_WIDTH = 0.135;      // 装甲板宽度  单位：米

// 相机内参
cv::Mat CAMERA_MATRIX =
  (Mat_<double>(3, 3) << 1.272839738190869e+03, 0, 3.459885430731165e+02, 0, 1.272339252547457e+03,
   2.519683753050819e+02, 0, 0, 1);
// 畸变系数
cv::Mat DISTORTION_COEFF = (Mat_<double>(4, 1) << -0.103600289802457, 0.222426187179441, 0, 0);

static const std::vector<cv::Point3f> object_points{
  {-ARMOR_WIDTH / 2, -LIGHTBAR_LENGTH / 2, 0},  // 点 1
  {+ARMOR_WIDTH / 2, -LIGHTBAR_LENGTH / 2, 0},  // 点 2
  {+ARMOR_WIDTH / 2, +LIGHTBAR_LENGTH / 2, 0},  // 点 3
  {-ARMOR_WIDTH / 2, +LIGHTBAR_LENGTH / 2, 0}   // 点 4
};

// 初始化卡尔曼滤波器
KalmanFilter initKalmanFilter(double dt)
{
  int stateSize = 6;        // 状态向量维度 [x, y, vx, vy, ax, ay]
  int measurementSize = 2;  // 测量向量维度 [x, y]
  int controlSize = 0;      // 无控制输入
  KalmanFilter kf(stateSize, measurementSize, controlSize, CV_32F);

  // 设置状态转移矩阵 A
  Mat transitionMatrix =
    (Mat_<float>(6, 6) << 1, 0, dt, 0, 0.5 * dt * dt, 0, 0, 1, 0, dt, 0, 0.5 * dt * dt, 0, 0, 1, 0,
     dt, 0, 0, 0, 0, 1, 0, dt, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1);
  kf.transitionMatrix = transitionMatrix;

  // 设置观测矩阵 H
  Mat measurementMatrix = (Mat_<float>(2, 6) << 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0);
  kf.measurementMatrix = measurementMatrix;

  // 设置过程噪声协方差矩阵 Q
  Mat processNoiseCov = Mat::eye(6, 6, CV_32F) * 1e-3;
  kf.processNoiseCov = processNoiseCov;

  // 设置观测噪声协方差矩阵 R
  Mat measurementNoiseCov = Mat::eye(2, 2, CV_32F) * 1e-1;
  kf.measurementNoiseCov = measurementNoiseCov;

  // 初始化状态向量 x 和协方差矩阵 P
  Mat statePost = Mat::zeros(6, 1, CV_32F);
  Mat errorCovPost = Mat::eye(6, 6, CV_32F) * 10;  // 增大初始协方差以加快收敛
  kf.statePost = statePost;
  kf.errorCovPost = errorCovPost;

  return kf;
}

// 加载SVM模型
// Ptr<SVM> loadSVMModel(const string & model_path)
// {
//   Ptr<SVM> svm = SVM::load(model_path);
//   if (!svm) {
//     cerr << "Error: Unable to load SVM model from " << model_path << endl;
//     exit(1);
//   }
//   return svm;
// }

// 提取数字区域并进行识别
// string recognizeNumber(const Mat & image, const Armor & armor, Ptr<SVM> svm)
// {
//   // 提取数字区域（假设数字区域在装甲板中心附近）
//   Rect number_rect(
//     armor.left.top.x, armor.left.top.y, armor.right.bottom.x - armor.left.top.x,
//     armor.right.bottom.y - armor.left.top.y);
//   Mat number_region = image(number_rect);

//   将数字区域转换为灰度图并二值化
//   Mat gray, binary;
//   cvtColor(number_region, gray, COLOR_BGR2GRAY);
//   threshold(gray, binary, 128, 255, THRESH_BINARY_INV);

//   将图像转换为一维特征向量
//   Mat feature_vector = binary.reshape(1, 1);
//   feature_vector.convertTo(feature_vector, CV_32F);

//   // 使用SVM进行预测
//   int result = svm->predict(feature_vector);
//   return to_string(result);
// }

int main()
{
  Detector detector;
  list<Armor> armors;
  VideoCapture video(
    "/home/chaichai/project/Study_Note/Armor_identification/CLASS_4/imgs/8radps.avi");

  double fps = video.get(CAP_PROP_FPS);
  cout << "原始帧率: " << fps << " fps" << endl;
  double dt = 1.0 / fps;  // 时间步长

  // 初始化卡尔曼滤波器
  KalmanFilter kf = initKalmanFilter(dt);

  // 加载SVM模型
  //Ptr<SVM> svm =loadSVMModel("/home/chaichai/project/Study_Note/Armor_identification/CLASS_4/svm_model.xml");

  // cout << "加载完毕" << endl;

  while (1) {
    Mat bgr_img;
    video.read(bgr_img);
    if (bgr_img.empty()) break;

    armors = detector.detect(bgr_img);
    Mat draw_armor = bgr_img.clone();

    for (const auto & armor : armors) {
      draw_points(draw_armor, armor.points);

      draw_text(
        draw_armor,
        fmt::format("{} {} {:.2f}", COLORS[armor.color], ARMOR_NAMES[armor.name], armor.confidence),
        armor.left.top);

      std::vector<Point2f> imgs_points{
        armor.left.top, armor.right.top, armor.right.bottom, armor.left.bottom};

      cv::Mat rvec, tvec;
      cv::solvePnP(
        object_points, imgs_points, CAMERA_MATRIX, DISTORTION_COEFF, rvec, tvec);  // PnP解算

      tools::draw_text(
        draw_armor, fmt::format("Distance: {: .2f} m", cv::norm(tvec)), cv::Point2f(10, 60), 1,
        cv::Scalar(0, 0, 255), 2);

      // 计算中心点
      Point2f armor_center =
        (armor.left.top + armor.right.top + armor.right.bottom + armor.left.bottom) / 4.0;
      cv::circle(draw_armor, armor_center, 3, cv::Scalar(0, 0, 255), 1);  // 绘制红色中心点

      // 卡尔曼滤波预测
      // 将中心点作为测量值输入卡尔曼滤波器
      Mat measurement = (Mat_<float>(2, 1) << armor_center.x, armor_center.y);
      Mat prediction = kf.predict();            // 预测下一时刻的位置
      Mat estimated = kf.correct(measurement);  // 根据测量值更新状态

      // 获取预测和估计的位置
      Point2f predictPt(prediction.at<float>(0), prediction.at<float>(1));
      Point2f estimatedPt(estimated.at<float>(0), estimated.at<float>(1));

      // 绘制预测和估计的位置
      cv::circle(draw_armor, predictPt, 3, cv::Scalar(0, 255, 0), 1);  // 预测点
      //cv::circle(draw_armor, estimatedPt, 3, cv::Scalar(0, 255, 0), -1);  // 估计点

      //string number = recognizeNumber(bgr_img, armor, svm);
      // draw_text(draw_armor, fmt::format("Number: {}", number), armor_center, 1, cv::Scalar(255, 0, 0), 2);
    }

    imshow("draw_armor", draw_armor);
    auto key = waitKey(25);
    if (key == 'q') {
      break;
    }
  }

  return 0;
}
