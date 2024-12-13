#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void channel_split()
{
    Mat img = imread("/home/chaichai/project/All_study/OpenCV_Learn/OpenCV.jpg");
    if (img.empty())
    {
        cout << "请检查图片路径是否正确！" << endl;
        return;
    }

    Mat imgs01, imgs02, imgs03; // 定义三个Mat变量分别存储三个通道

    Mat imgs[3];
    split(img, imgs);
    imgs01 = imgs[0];
    imgs02 = imgs[1];
    imgs03 = imgs[2];

    imshow("原图", img);
    imshow("RBG-R通道图像", imgs01);
    imshow("RBG-G通道图像", imgs02);
    imshow("RBG-B通道图像", imgs03);
    waitKey(0);
}

int main()
{
    channel_split();
    return 0;
}