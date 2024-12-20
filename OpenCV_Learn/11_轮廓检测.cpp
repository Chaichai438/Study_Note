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
        // drawContours()
        // 第一个参数：图像
        // 第二个参数：轮廓的向量
        // 第三个参数：轮廓的索引
        // 第四个参数：轮廓的颜色
        // 第五个参数：轮廓的宽度
        // 第六个参数：线条类型
        drawContours(img, contours, t, Scalar(255, 0, 0), 2, 8); // 绘制轮廓
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

void test04()
{
    Mat img = imread("../test08.jpg");
    Mat img1, img2;
    img.copyTo(img1);
    img.copyTo(img2);
    imshow("img", img);

    // 去噪声和二值化
    Mat canny; // 作用是边缘检测
    // Canny()
    //  第一个参数：输入图像
    //  第二个参数：输出图像
    //  第三个参数：低阈值    一般取80
    //  第四个参数：高阈值    一般取160
    //  第五个参数：apertureSize  孔径大小，一般取3
    //  第六个参数：L2gradient   是否使用L2范数计算梯度，一般取false
    Canny(img, canny, 80, 160, 3, false);
    imshow("", canny);

    // 膨胀运算，将细小缝隙填补
    Mat kernel = getStructuringElement(0, Size(3, 3));
    dilate(canny, canny, kernel);

    // 轮廓的发现和绘制
    vector<vector<Point>> contours; // 存放轮廓点的向量
    findContours(canny, contours, 0, 2, Point());

    // 寻找轮廓的外接矩形
    for (int n = 0; n < contours.size(); n++)
    {
        // 最大外接矩形
        //boundingRect()作用是计算矩形的边界框
        Rect rect = boundingRect(contours[n]);
        
        rectangle(img1, rect, Scalar(0, 0, 255), 2, 8, 0);

        // 最小外接矩形
        RotatedRect rrect = minAreaRect(contours[n]);//RotatedRect类型:返回的有矩形的中心位置、宽高、旋转角度
        Point2f points[4];
        rrect.points(points);
        Point2f cpt = rrect.center;

        // 绘制旋转矩形与中心位置
        for (int i = 0; i < 4; i++)
        {
            if (i == 3)
            {
                line(img2, points[i], points[0], Scalar(0, 255, 0), 2, 8, 0);
                break;
            }
            line(img2, points[i], points[i + 1], Scalar(0, 255, 0), 2, 8, 0);
        }
        circle(img, cpt, 2, Scalar(255, 0, 0), 2, 8, 0);
    }
    // 输出绘制的外接矩形的结果
    imshow("max", img1);
    imshow("min", img2);
    waitKey(0);
}

int main()
{
    // test01();

    // test02();

    // test03();

    test04();
    return 0;
}