#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>

using namespace cv;
using namespace std;

// 图像腐蚀
void test01()
{
    // 生成用于腐蚀的原图

    Mat src = (Mat_<uchar>(6, 6) << 0, 0, 0, 0, 255, 0,
               0, 255, 255, 255, 255, 255,
               0, 255, 255, 255, 255, 0,
               0, 255, 255, 255, 255, 0,
               0, 255, 255, 255, 255, 0,
               0, 0, 0, 0, 0, 0); // 生成一个6*6的黑白图像，其中有两个白色区域，一个黑色区域

    Mat struct1, struct2; // 创建结构元素
    // getStructuringElement()
    // 第一个参数：MORPH_RECT(0)或MORPH_CROSS，表示矩形或十字形结构元素(1)
    // 第二个参数：结构元素的大小，Size(3,3)表示3x3的结构元素
    // 第三个参数：默认值Point(-1,-1)，表示结构元素中心位置，-1表示自动计算
    struct1 = getStructuringElement(0, Size(3, 3)); // 矩形结构元素
    struct2 = getStructuringElement(1, Size(3, 3)); // 十字形结构元素

    Mat erodeSrc; // 腐蚀后的原图
    // erode()
    //  第一个参数：原图
    //  第二个参数：腐蚀后的原图
    //  第三个参数：结构元素

    erode(src, erodeSrc, struct2);
    namedWindow("src", WINDOW_GUI_NORMAL);
    namedWindow("erodeSrc", WINDOW_GUI_NORMAL);
    imshow("src", src);
    imshow("erodeSrc", erodeSrc);

    Mat LearnCV_black = imread("../test06.jpg", IMREAD_ANYCOLOR);
    Mat LearnCV_white = imread("../test07.jpg", IMREAD_ANYCOLOR);

    Mat erode_black1, erode_black2, erode_white1, erode_white2;

    // 黑色背景腐蚀
    erode(LearnCV_black, erode_black1, struct1);
    erode(LearnCV_black, erode_black2, struct2);
    imshow("LearnCV_black", LearnCV_black);
    imshow("erode_black1", erode_black1);
    imshow("erode_black2", erode_black2);

    // 白色背景腐蚀
    erode(LearnCV_white, erode_white1, struct1);
    erode(LearnCV_white, erode_white2, struct2);
    imshow("LearnCV_white", LearnCV_white);
    imshow("erode_white1", erode_white1);
    imshow("erode_white2", erode_white2);

    waitKey(0);
}

// 图像膨胀
void test02()
{
    Mat src = (Mat_<uchar>(6, 6) << 0, 0, 0, 0, 255, 0,
               0, 255, 255, 255, 255, 255,
               0, 255, 255, 255, 255, 0,
               0, 255, 255, 255, 255, 0,
               0, 255, 255, 255, 255, 0,
               0, 0, 0, 0, 0, 0);

    Mat struct1, struct2;
    struct1 = getStructuringElement(0, Size(3, 3)); // 矩形结构元素
    struct2 = getStructuringElement(1, Size(3, 3)); // 十字形结构元素

    Mat dilateSrc;
    // dilate()
    //  第一个参数：原图
    //  第二个参数：膨胀后的原图
    //  第三个参数：结构元素

    dilate(src, dilateSrc, struct2);
    namedWindow("src", WINDOW_GUI_NORMAL);
    namedWindow("dilateSrc", WINDOW_GUI_NORMAL);
    imshow("src", src);
    imshow("dilateSrc", dilateSrc);

    Mat background_black = imread("../test06.jpg", IMREAD_ANYCOLOR);
    Mat background_white = imread("../test07.jpg", IMREAD_ANYCOLOR);
    if (background_black.empty() && background_white.empty())
    {
        cout << "请检查图片路径是否正确" << endl;
        return;
    }

    Mat dilate_black1, dilate_black2, dilate_white1, dilate_white2;
    // 黑色背景膨胀
    dilate(background_black, dilate_black1, struct1);
    dilate(background_black, dilate_black2, struct2);
    imshow("background_black", background_black);
    imshow("dilate_black1", dilate_black1);
    imshow("dilate_black2", dilate_black2);

    // 白色背景膨胀
    dilate(background_white, dilate_white1, struct1);
    dilate(background_white, dilate_white2, struct2);
    imshow("background_white", background_white);
    imshow("dilate_white1", dilate_white1);
    imshow("dilate_white2", dilate_white2);

    waitKey(0);
}

int main()
{
    test01();
    // test02();
    return 0;
}