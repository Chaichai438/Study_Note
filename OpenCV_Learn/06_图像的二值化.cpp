#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>

using namespace cv;
using namespace std;

// 图像的二值化的作用：将图像的灰度值映射到0或1，从而使得图像变得更加清晰、简单。
// 1、在机器视觉中，二值化图像常用于识别和定位物体。
// 2、二值化图像常用于模式识别任务，如手写数字识别、字符识别等
// 3、在文档扫描中，二值化可以将文档转换为清晰的黑白图像，便于存储和打印
// 4、在自动驾驶车辆和机器人导航中，二值化图像有助于识别道路标记、障碍物等
//....

void test01()
{
    Mat img = imread("../test02.jpg");
    if (img.empty())
    {
        cout << "请检查图片路径是否正确！" << endl;
        return;
    }

    Mat gray;
    cvtColor(img, gray, COLOR_BGR2GRAY); // 将img的BGR彩色模型转换为灰度模型

    // threshold(src, dst, thresh, maxval, type)  阈值处理 将图像的像素值划分为两个或多个类别
    // src:输入图像
    // dst:输出图像
    // thresh:阈值
    // maxval:最大值
    // type:二值化方法

    Mat img_B, img_B_V, gray_B, gray_B_V, gray_T, gray_T_V, gray_TRUNC;

    // 彩色图像二值化
    threshold(img, img_B, 125, 255, THRESH_BINARY);
    threshold(img, img_B_V, 125, 255, THRESH_BINARY_INV);
    imshow("img_B", img_B);
    imshow("img_B_V", img_B_V);

    // 灰度图像二值化
    threshold(gray, gray_B, 125, 255, THRESH_BINARY);       // 二值化阈值处理
    threshold(gray, gray_B_V, 125, 255, THRESH_BINARY_INV); // 二值化反转阈值处理
    imshow("gray_B", gray_B);
    imshow("gray_B_V", gray_B_V);

    // 灰度图像TOZERO变换
    threshold(gray, gray_T, 125, 255, THRESH_TOZERO);       // 置零阈值处理
    threshold(gray, gray_T_V, 125, 255, THRESH_TOZERO_INV); // 反转置零阈值处理
    imshow("gray_T", gray_T);
    imshow("gray_T_V", gray_T_V);

    // 灰度图像TRUNC变换
    threshold(gray, gray_TRUNC, 125, 255, THRESH_TRUNC); // 截断阈值化处理
    imshow("gray_TRUNC", gray_TRUNC);

    waitKey(0);
}

// adaptiveThreshold(src, dst, maxValue, adaptiveMethod, thresholdType, blockSize, C)
// src:输入图像
// dst:输出图像
// maxValue:最大值
// adaptiveMethod:自适应阈值化方法
// thresholdType:阈值化方法
// blockSize:邻域大小
// C:常数值

void test02()
{
    // 灰度图像大津法和三角形法二值化
    Mat img_Thr = imread("../test01.jpg", IMREAD_GRAYSCALE); // 读取图像文件，并将其转换为灰度图像
    Mat img_Thr_O, img_Thr_T;
    threshold(img_Thr, img_Thr_O, 100, 255, THRESH_BINARY | THRESH_OTSU);     // 大津阈值处理
    threshold(img_Thr, img_Thr_T, 125, 255, THRESH_BINARY | THRESH_TRIANGLE); // 三角形法阈值处理
    imshow("img_Thr_O", img_Thr_O);
    imshow("img_Thr_T", img_Thr_T);

    // 灰度图像自适应二值化
    Mat adaptive_mean, adaptive_gauss;
    adaptiveThreshold(img_Thr, adaptive_mean, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 55, 0);      // 自适应均值减去常数阈值
    adaptiveThreshold(img_Thr, adaptive_gauss, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY, 55, 0); // 自适应高斯阈值常数
    imshow("adaptive_mean", adaptive_mean);
    imshow("adaptive_gauss", adaptive_gauss);

    waitKey(0);
}

int main()
{
    // test01();
    test02();
    return 0;
}