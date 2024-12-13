#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

// resize()函数用于图像尺寸的缩放，可以指定缩放的尺寸，也可以指定缩放的比例。
// resize(src, dst, Size(width, height), fx, fy, interpolation)
// src: 输入图像
// dst: 输出图像
// Size(width, height): 输出图像的尺寸
// fx: 缩放的比例，fx和fy可以同时指定，也可以只指定一个，如果只指定一个，另一个会根据输入图像的尺寸和输出图像的尺寸计算出一个值
// fy: 缩放的比例
// interpolation: 插值方法 默认值为INTER_LINEAR 可选值有INTER_NEAREST、INTER_LINEAR、INTER_AREA、INTER_CUBIC、INTER_LANCZOS4

// 图像尺寸变换
void test01()
{
    Mat gray = imread("../test05.png", IMREAD_GRAYSCALE);
    if (gray.empty())
    {
        cout << "请检查图片路径是否正确！" << endl;
        return;
    }
    else
    {
        cout << "图片的尺寸为：" << gray.cols << "x" << gray.rows << endl;
        namedWindow("原图", WINDOW_NORMAL);
        imshow("原图", gray);
    }

    Mat smallImg, bigImg0, bigImg1, bigImg2;

    resize(gray, smallImg, Size(500, 700), 0, 0, INTER_AREA);
    resize(smallImg, bigImg0, Size(800, 1000), 0, 0, INTER_NEAREST); // 最近邻插值
    resize(smallImg, bigImg1, Size(800, 1000), 0, 0, INTER_LINEAR);  // 双线性插值
    resize(smallImg, bigImg2, Size(800, 1000), 0, 0, INTER_CUBIC);   // 双三次插值

    namedWindow("smallImg", WINDOW_NORMAL);
    imshow("smallImg", smallImg);

    namedWindow("bigImg0", WINDOW_NORMAL);
    imshow("bigImg0", bigImg0);

    namedWindow("bigImg1", WINDOW_NORMAL);
    imshow("bigImg1", bigImg1);

    namedWindow("bigImg2", WINDOW_NORMAL);
    imshow("bigImg2", bigImg2);

    waitKey(0);
}

// flip()函数用于图像的翻转，可以指定翻转的方向，0为水平翻转，1为垂直翻转，-1为水平垂直翻转。
//  flip(src, dst, flipCode)
//  src: 输入图像
//  dst: 输出图像
//  flipCode: 翻转方向，0为水平翻转，1为垂直翻转，-1为水平垂直翻转

// 图像翻转变换
void test02()
{
    Mat img = imread("../test01.jpg");
    if (img.empty())
    {
        cout << "请检查图片路径是否正确！" << endl;
        return;
    }

    Mat img_x, img_y, img_xy;
    flip(img, img_x, 0);   // 以x轴为对称轴翻转
    flip(img, img_y, 1);   // 以y轴为对称轴翻转
    flip(img, img_xy, -1); // 以x轴和y轴为对称轴翻转

    imshow("原图", img);
    imshow("x翻转", img_x);
    imshow("y翻转", img_y);
    imshow("xy翻转", img_xy);

    waitKey(0);
}

int main()
{
    // test01();
    test02();
    return 0;
}