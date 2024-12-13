#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>

using namespace cv;
using namespace std;

// 轮廓的检测和绘制
void test01()
{
    Mat img = imread("../test03.jpg");
    if (img.empty())
    {
        cout << "请确认图片路径是否正确" << endl;
        return;
    }
    imshow("原图", img);

    // 图像预处理
    Mat gray, binary;
    cvtColor(img, gray, COLOR_BGR2GRAY);                            // 灰度化
    GaussianBlur(gray, gray, Size(13, 13), 4, 4);                   // 高斯滤波
    threshold(gray, binary, 170, 255, THRESH_BINARY | THRESH_OTSU); // 自适应二值化

    // 轮廓的发现与绘制
    vector<vector<Point>> contours; // 存放轮廓点的向量
    vector<Vec4i> hierarchy;        // 存放轮廓的层次结构
    findContours(binary, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE, Point());

    // 绘制轮廓
    for (int t = 0; t < contours.size(); t++)
    {
        drawContours(img, contours, t, Scalar(0, 0, 255), 2, 8); // 绘制轮廓
    }

    // 输出轮廓结构描述
    for (int i = 0; i < hierarchy.size(); i++)
    {
        cout << hierarchy[i] << endl;
    }

    // 显示结果
    imshow("轮廓检测", img);
    waitKey(0);
}

// 计算轮廓面积
void test02()
{
    vector<Point> contour; // 存放轮廓点的向量
    contour.push_back(Point2f(0, 0));
    contour.push_back(Point2f(10, 0));
    contour.push_back(Point2f(10, 10));
    contour.push_back(Point2f(5, 5));
    double area = contourArea(contour);
    cout << "轮廓面积为：" << area << endl;

    Mat img = imread("../test04.jpg");
    if (img.empty())
    {
        cout << "请确认图片路径是否正确" << endl;
        return;
    }
    imshow("原图", img);

    Mat gray, binary;
    cvtColor(img, gray, COLOR_BGR2GRAY);                            // 灰度化
    GaussianBlur(gray, gray, Size(9, 9), 2, 2);                     // 高斯滤波
    threshold(gray, binary, 170, 255, THRESH_BINARY | THRESH_OTSU); // 自适应二值化

    // 轮廓检测
    vector<vector<Point>> contours; // 存放轮廓点的向量
    vector<Vec4i> hierarchy;        // 存放轮廓的层次结构
    findContours(binary, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE, Point());

    // 输出轮廓面积
    for (int t = 0; t < contours.size(); t++)
    {
        double area = contourArea(contours[t]);
        cout << "轮廓" << t << "的面积为：" << area << endl;
    }

    // 绘制轮廓
    for (int t = 0; t < contours.size(); t++)
    {
        drawContours(img, contours, t, Scalar(0, 0, 255), 2, 8); // 绘制轮廓
    }

    // 输出轮廓结构描述
    for (int i = 0; i < hierarchy.size(); i++)
    {
        cout << hierarchy[i] << endl;
    }

    // 显示结果
    imshow("轮廓检测", img);

    waitKey(0);
}

// 轮廓长度
void test03()
{
    vector<Point> contour; // 存放轮廓点的向量
    contour.push_back(Point2f(0, 0));
    contour.push_back(Point2f(10, 0));
    contour.push_back(Point2f(10, 10));
    contour.push_back(Point2f(5, 5));

    double length0 = arcLength(contour, true);
    double length1 = arcLength(contour, false);
    cout << "轮廓长度为：" << length0 << endl;
    cout << "轮廓长度（不闭合）为：" << length1 << endl;

    Mat img = imread("../test04.jpg");
    if (img.empty())
    {
        cout << "请确认图片路径是否正确" << endl;
        return;
    }
    imshow("原图", img);

    Mat gray, binary;
    cvtColor(img, gray, COLOR_BGR2GRAY);                            // 灰度化
    GaussianBlur(gray, gray, Size(9, 9), 2, 2);                     // 高斯滤波
    threshold(gray, binary, 170, 255, THRESH_BINARY | THRESH_OTSU); // 自适应二值化

    // 轮廓检测
    vector<vector<Point>> contours; // 存放轮廓点的向量
    vector<Vec4i> hierarchy;        // 存放轮廓的层次结构
    findContours(binary, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE, Point());

    // 输出轮廓长度
    for (int t = 0; t < contours.size(); t++)
    {
        double length = arcLength(contours[t], true);
        cout << "轮廓" << t << "的长度为：" << length << endl;
    }

    waitKey(0);
}

int main()
{
    // test01();

    // test02();

    test03();
    return 0;
}