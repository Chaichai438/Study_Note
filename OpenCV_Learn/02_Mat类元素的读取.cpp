#include <iostream>
#include <opencv4/opencv2/opencv.hpp>

using namespace cv;
using namespace std;

void test01()
{
    // Mat 类矩阵常用的类型
    Mat a(3, 4, CV_32FC1, Scalar(1, 2, 3));

    cout << a << endl;

    // 列数
    cout << a.cols << endl; // 4

    // 行数
    cout << a.rows << endl; // 3

    // 以字节为单位的矩阵的有效宽度
    cout << a.channels() << endl; // 3

    // 总共的元素
    cout << a.total() << endl; // 12

    // 通道数
    cout << a.channels() << endl; // 3

    // 每个元素字节数
    cout << a.elemSize() << endl; // 12
}

void test02()
{
    // at方法读取单通道矩阵元素at(int row,int col)
    Mat b(3, 3, CV_8UC1, Scalar(1));

    // 循环法赋值
    Mat C = Mat_<int>(3, 3);
    for (int i = 0; i < C.rows; i++)
    {
        for (int j = 0; j < C.cols; j++)
        {
            C.at<int>(i, j) = i + j;
        }
    }

    cout << C << endl;
    int value = C.at<int>(0, 0);
    cout << value << endl;
}

void test03()
{
    // 通过at读取多通道矩阵元素
    Mat b(3, 4, CV_8UC3, Scalar(1, 2, 3));

    cout << b << endl;
    Vec3b v3 = b.at<Vec3b>(0, 0); // 第一个通道的数据

    int a1, a2, a3, a4, a5, a6, a7, a8;
    a1 = v3.val[0];
    a2 = v3.val[1];
    a3 = v3.val[2];

    cout << a1 << endl;
    cout << a2 << endl;
    cout << a3 << endl;
}

void test04()
{
    // 利用ptr读取矩阵的元素
    Mat b(3, 4, CV_8UC3, Scalar(0, 0, 1));
    for (int i = 0; i < b.rows; i++)
    {
        uchar *ptr = b.ptr<uchar>(i); // 获取第i行的指针
        for (int j = 0; j < b.cols * b.channels(); j++)
        {
            cout << (int)ptr[j] << " ";
        }
        cout << "\n";
    }
}

void test05()
{
    // 通过迭代器访问矩阵元素
    Mat a(3, 4, CV_8UC3, Scalar(0, 0, 1));

    MatIterator_<Vec3b> it_end = a.end<Vec3b>();

    for (MatIterator_<Vec3b> it = a.begin<Vec3b>(); it != it_end; it++)
    {
        int i = 0;
        cout << *it << " ";

        if ((++i % a.cols) == 0)
        {
            cout << endl;
        }
    }
}

void test06()
{
    Mat a(3, 4, CV_8UC3, Scalar(0, 0, 1));
    cout << (int)(*(a.data + a.step[0] * a.rows + a.step[1] * a.cols + a.channels)) << endl;
}

int main()
{
    // test01();

    // test02();

    // test03();

    test04();

    cout << "----------------------------" << endl;

    test05();

    cout << "----------------------------" << endl;

    test06();

    return 0;
}