#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
    // 读取图像
    Mat img = imread("/home/chaichai/project/All_study/OpenCV_Learn/test02.jpg");
    // 判断图像是否读取成功
    if (img.empty())
    {
        cout << "请确认图像路径是否正确！" << endl;
        return -1;
    }

    Mat GRAY, HSV, YUV, Lab, img32;
    img.convertTo(img32, CV_32F, 1.0 / 255.0); // 将图像转换为32位浮点型 因为32位浮点型的像素是0-1的范围
    // img.convertTo(img,CV_8U,225); //将图像转换为8位无符号型 因为8位无符号型的像素是0-255的范围

    cvtColor(img32, HSV, COLOR_BGR2HSV);
    cvtColor(img32, YUV, COLOR_BGR2YUV);
    cvtColor(img32, Lab, COLOR_BGR2Lab);
    cvtColor(img32, GRAY, COLOR_BGR2GRAY);

    imshow("原图", img32);
    imshow("HSV", HSV);
    imshow("YUV", YUV);
    imshow("Lab", Lab);
    imshow("GRAY", GRAY);
    waitKey(0);

    return 0;
}