#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

void test01()
{
    Mat img;
    img = imread("/home/chaichai/project/All_study/OpenCV_Learn/test01.jpg", IMREAD_COLOR);

    if (img.empty())
    {
        cout << "图片不存在或者已经损坏" << endl;
        return;
    }

    namedWindow("test01", WINDOW_AUTOSIZE);

    imshow("test01", img);
}

void test02()
{
    // 视频文件读取
    // system("color F0");
    VideoCapture video("/home/chaichai/project/All_study/OpenCV_Learn/KaKa.mp4");
    if (video.isOpened())
    {
        cout << "视频中图像的宽度：" << video.get(CAP_PROP_FRAME_WIDTH) << endl;
        cout << "视频中图像的高度：" << video.get(CAP_PROP_FRAME_HEIGHT) << endl;
        cout << "视频中帧数：" << video.get(CAP_PROP_FPS) << endl;
        cout << "视频中总帧数：" << video.get(CAP_PROP_FRAME_COUNT) << endl;
    }
    else
    {
        cout << "视频文件出错，请检查是否文件正确" << endl;
        return;
    }
    while (1)
    {
        Mat frame;
        video >> frame;
        if (frame.empty())
        {
            break;
        }
        namedWindow("KaKa", WINDOW_GUI_EXPANDED);
        imshow("KaKa", frame);
        int key = waitKey(1000 / video.get(CAP_PROP_FPS));
        if (key == 27)
        {
            break;
        }
    }
}

void test03()
{
    VideoCapture video(0);
    if (video.isOpened())
    {
        cout << "视频中图像的宽度：" << video.get(CAP_PROP_FRAME_WIDTH) << endl;
        cout << "视频中图像的高度：" << video.get(CAP_PROP_FRAME_HEIGHT) << endl;
        cout << "视频中帧数：" << video.get(CAP_PROP_FPS) << endl;
        cout << "视频中总帧数：" << video.get(CAP_PROP_FRAME_COUNT) << endl;
    }
    else
    {
        cout << "视频文件出错，请检查是否文件正确" << endl;
        return;
    }
    while (1)
    {
        Mat frame, resizedFrame;
        namedWindow("TouKui", WINDOW_NORMAL);
        video >> frame;
        if (frame.empty())
        {
            break;
        }
        resize(frame, resizedFrame, Size(1500, 1000));
        imshow("TouKui", resizedFrame);
        int key = waitKey(1000 / video.get(CAP_PROP_FPS));
        if (key == 27) // 按下ESC即可结束视频
        {
            break;
        }
    }
}

int main()
{
    // test01();

    // test02();

    test03();

    return 0;
}