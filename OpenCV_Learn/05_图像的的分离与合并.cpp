#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>

using namespace cv;
using namespace std;

int main()
{
    Mat img = imread("/home/chaichai/project/All_study/OpenCV_Learn/test01.jpg");
    if (img.empty())
    {
        cout << "请确认图像路径是否正确！" << endl;
        return -1;
    }

    Mat HSV;
    cvtColor(img, HSV, COLOR_BGR2HSV); // 将img的RGB颜色模型转换为HSV颜色模型
    Mat imgs0, imgs1, imgs2;           // 分离后的三个通道
    Mat imgv0, imgv1, imgv2;           // 分离后的三个通道
    Mat result0, result1, result2;     // 合并后的三个通道

    // 输入数组参数的多通道分离与合并
    Mat imgs[3];      // 定义一个Mat数组，用来存放分离后的三个通道
    split(img, imgs); // 将多通道img分离为三个通道，存入imgs数组中

    imgs0 = imgs[0];
    imgs1 = imgs[1];
    imgs2 = imgs[2];

    imshow("RGB-B通道", imgs0);
    imshow("RGB-G通道", imgs1);
    imshow("RGB-R通道", imgs2);

    merge(imgs, 3, result0);
    imshow("合并后的GB", result0);

    Mat zero = Mat::zeros(img.rows, img.cols, CV_8UC1); // 定义一个全0单通道的Mat

    imgs[0] = zero;
    imgs[2] = zero;
    merge(imgs, 3, result1); // 合并图像结果为绿色通道
    imshow("合并后的GR", result1);

    // 输入vector参数的多通道分离与合并
    vector<Mat> imgv;
    split(HSV, imgv);
    imgv0 = imgv.at(0);
    imgv1 = imgv.at(1);
    imgv2 = imgv.at(2);
    imshow("HSV-H通道", imgv0);
    imshow("HSV-S通道", imgv1);
    imshow("HSV-V通道", imgv2);

    merge(imgv, result2); // 合并图像
    // 注意：merge函数的最后一个参数是输出图像的通道数，如果输入图像的通道数与输出图像的通道数不一致，则会自动进行通道扩展。
    imshow("合并后的HSV", result2);

    waitKey(0);
    return 0;
}