#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>

using namespace std;
using namespace cv;

void test01()
{
    Mat img = imread("../test05.png");
    if (img.empty())
    {
        cout << "请确认图片路径是否正确" << endl;
        return;
    }

    Mat gray;
    cvtColor(img, gray, COLOR_BGR2GRAY);
    GaussianBlur(gray, gray, Size(5, 5), 10, 20);

    vector<Point2f> imgPoints;
    Size boardSize = Size(9, 6);

    bool found = findChessboardCorners(gray, boardSize, imgPoints);

    if (!found || imgPoints.empty())
    {
        cout << "棋盘格角点检测失败，请检查图像质量和棋盘格大小" << endl;
        return;
    }
    find4QuadCornerSubpix(gray, imgPoints, Size(5, 5));

    Size squareSize = Size(10, 10);
    vector<Point3f> PointSets;
    for (int j = 0; j < boardSize.height; j++)
    {
        for (int k = 0; k < boardSize.width; k++)
        {
            Point3f realPoint;
            realPoint.x = j * squareSize.width;
            realPoint.y = k * squareSize.height;
            realPoint.z = 0;
            PointSets.push_back(realPoint);
        }
    }

    Mat cameraMatrix = (Mat_<float>(3, 3) << 532.016297, 0, 332.172519, 0, 531.565159, 233.388075, 0, 0, 1);

    Mat distCoeffs = (Mat_<float>(1, 5) << -0.285188, 0.080097, 0.001274, -0.002415, 0.106579);

    Mat rvec, tvec;
    solvePnP(PointSets, imgPoints, cameraMatrix, distCoeffs, rvec, tvec);
    cout << "世界坐标系变换到相机坐标系的旋转向量: " << rvec << endl;
    // 旋转向量转换成旋转矩阵
    Mat R;
    Rodrigues(rvec, R);
    cout << "旋转向量转换成旋转矩阵: " << endl
         << R << endl;

    // 用PnP+RANSAC算法计算旋转向量和平移向量
    Mat rvecRansac, tvecRansac;
    solvePnPRansac(PointSets, imgPoints, cameraMatrix, distCoeffs, rvecRansac, tvecRansac);
    Mat RRansac;
    Rodrigues(rvecRansac, RRansac);
    cout << "旋转向量转换成旋转矩阵: " << endl
         << RRansac << endl;
    waitKey(0);
}

int main()
{
    test01();
    return 0;
}