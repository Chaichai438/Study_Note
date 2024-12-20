#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void test01()
{
    Mat img = Mat::zeros(Size(512, 512), CV_8UC3);

    // 绘制直线
    // line()
    // 第一个参数：图像
    // 第二个参数：起点
    // 第三个参数：终点
    // 第四个参数：颜色
    // 第五个参数：线宽
    // 第六个参数：线型
    // 第七个参数：端点样式
    line(img, Point(100, 100), Point(200, 100), Scalar(255, 255, 255), 2, LINE_4, 0);

    // 绘制圆形
    // circle()
    // 第一个参数：图像
    // 第二个参数：圆心
    // 第三个参数：半径
    // 第四个参数：颜色
    // 第五个参数：线宽
    // 第六个参数：线型
    circle(img, Point(50, 50), 25, Scalar(255, 255, 255), -1);
    circle(img, Point(100, 50), 20, Scalar(255, 255, 255), 4);

    // 绘制椭圆
    // ellipse()
    // 第一个参数：图像
    // 第二个参数：中心点
    // 第三个参数：长轴和短轴
    // 第四个参数：旋转角度
    // 第五个参数：开始角度
    // 第六个参数：结束角度
    // 第七个参数：颜色
    // 第八个参数：线宽
    ellipse(img, Point(300, 255), Size(100, 70), 0, 0, 100, Scalar(255, 255, 255), -1);
    ellipse(img, RotatedRect(Point(150, 100), Size2f(30, 20), 0), Scalar(0, 0, 255), 2);

    vector<Point> points;
    // 用一些点来近似一个椭圆
    ellipse2Poly(Point(200, 400), Size(100, 70), 0, 0, 360, 2, points);
    for (int i = 0; i < points.size() - 1; i++)
    {
        if (i == points.size() - 1)
        {
            line(img, points[i], points[0], Scalar(255, 255, 255), 2);
            break;
        }
        line(img, points[i], points[i + 1], Scalar(255, 255, 255), 2);
    }

    // 绘制矩形
    // rectangle()
    // 第一个参数：图像
    // 第二个参数：左上角
    // 第三个参数：右下角
    // 第四个参数：颜色
    // 第五个参数：线宽
    // 第六个参数：线型

    rectangle(img, Point(50, 400), Point(100, 450), Scalar(125, 125, 125), -1);
    rectangle(img, Rect(400, 450, 60, 50), Scalar(0, 125, 125), 2);
    // 绘制多边形
    Point pp[2][6];
    pp[0][0] = Point(72, 200);
    pp[0][1] = Point(142, 204);
    pp[0][2] = Point(226, 263);
    pp[0][3] = Point(172, 310);
    pp[0][4] = Point(117, 319);
    pp[0][5] = Point(15, 260);
    pp[1][0] = Point(359, 339);
    pp[1][1] = Point(447, 351);
    pp[1][2] = Point(504, 349);
    pp[1][3] = Point(484, 433);
    pp[1][4] = Point(418, 449);
    pp[1][5] = Point(354, 402);
    Point pp2[5];
    pp2[0] = Point(350, 83);
    pp2[1] = Point(463, 90);
    pp2[2] = Point(500, 171);
    pp2[3] = Point(421, 194);
    pp2[4] = Point(338, 141);

    const Point *pts[3] = {pp[0], pp[1], pp2};
    int npts[3] = {6, 6, 5};
    // fillPoly()
    //  第一个参数：图像
    //  第二个参数：多边形的顶点数组
    //  第三个参数：每个多边形的顶点数
    //  第四个参数：绘制多边形的数量
    //  第五个参数：颜色
    //  第六个参数：线宽
    fillPoly(img, pts, npts, 3, Scalar(125, 125, 125), 8);

    // 绘制文字
    // putText()
    // 第一个参数：图像
    // 第二个参数：文字内容
    // 第三个参数：文字左上角
    // 第四个参数：字体大小
    // 第五个参数：字体
    // 第六个参数：颜色
    putText(img, "Learn OpenCV 4", Point(100, 400), 2, 1, Scalar(255, 255, 255));
    imshow("Draw", img);

    waitKey(0);
}

int main()
{
    test01();
    return 0;
}