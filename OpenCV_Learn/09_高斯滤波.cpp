#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
    Mat img = imread("../test03.jpg", IMREAD_ANYDEPTH);
    if (img.empty())
    {
        cout << "请确认图像路径是否正确" << endl;
        return -1;
    }

    Mat result_5gauss, result_9gauss;
    // 调用高斯滤波函数进行滤波
    GaussianBlur(img, result_5gauss, Size(5, 5), 10, 20);
    GaussianBlur(img, result_9gauss, Size(9, 9), 10, 20);

    imshow("img", img);
    imshow("result_5gauss", result_5gauss);
    imshow("result_9gauss", result_9gauss);

    waitKey(0);

    return 0;
}