#include <iostream>
#include <opencv2/opencv.hpp>
#include <vector>

using namespace cv;
using namespace std;

int main()
{
  // 初始化卡尔曼滤波器
  int stateSize = 4;        // 状态向量维度 [x, y, vx, vy]
  int measurementSize = 2;  // 测量向量维度 [x, y]
  int controlSize = 0;      // 无控制输入
  KalmanFilter kf(stateSize, measurementSize, controlSize, CV_32F);

  // 设置状态转移矩阵 A
  Mat transitionMatrix = (Mat_<float>(4, 4) << 1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1);
  kf.transitionMatrix = transitionMatrix;

  // 设置观测矩阵 H
  Mat measurementMatrix = (Mat_<float>(2, 4) << 1, 0, 0, 0, 0, 1, 0, 0);
  kf.measurementMatrix = measurementMatrix;

  // 设置过程噪声协方差矩阵 Q
  Mat processNoiseCov =
    (Mat_<float>(4, 4) << 1e-2, 0, 0, 0, 0, 1e-2, 0, 0, 0, 0, 1e-2, 0, 0, 0, 0, 1e-2);
  kf.processNoiseCov = processNoiseCov;

  // 设置观测噪声协方差矩阵 R
  Mat measurementNoiseCov = (Mat_<float>(2, 2) << 1e-1, 0, 0, 1e-1);
  kf.measurementNoiseCov = measurementNoiseCov;

  // 初始化状态向量 x
  Mat statePost = (Mat_<float>(4, 1) << 0, 0, 0, 0);
  kf.statePost = statePost;

  // 模拟观测数据
  vector<Point2f> measurements = {{100, 100}, {105, 105}, {110, 110}, {115, 115}, {120, 120},
                                  {125, 125}, {130, 130}, {135, 135}, {140, 140}, {145, 145}};

  // 创建窗口
  namedWindow("Kalman Filter", WINDOW_AUTOSIZE);

  for (size_t i = 0; i < measurements.size(); i++) {
    // 预测状态
    Mat prediction = kf.predict();

    // 获取预测位置
    Point2f predictPt(prediction.at<float>(0), prediction.at<float>(1));

    // 获取测量位置
    Point2f measurementPt(measurements[i].x, measurements[i].y);

    // 更新状态
    Mat measurement = (Mat_<float>(2, 1) << measurementPt.x, measurementPt.y);
    Mat estimated = kf.correct(measurement);

    // 获取估计位置
    Point2f estimatedPt(estimated.at<float>(0), estimated.at<float>(1));

    // 可视化
    Mat img = Mat::zeros(500, 500, CV_8UC3);
    circle(img, measurementPt, 5, Scalar(0, 0, 255), FILLED);     // 测量点（红色）
    circle(img, predictPt, 5, Scalar(255, 0, 0), FILLED);         // 预测点（蓝色）
    circle(img, estimatedPt, 5, Scalar(0, 255, 0), FILLED);       // 估计点（绿色）
    line(img, estimatedPt, predictPt, Scalar(255, 255, 255), 1);  // 预测轨迹（白色）

    imshow("Kalman Filter", img);
    waitKey(500);
  }

  return 0;
}