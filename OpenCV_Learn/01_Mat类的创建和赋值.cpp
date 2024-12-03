#include <iostream>
#include <opencv4/opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
    // Mat 类的声明
    // 利用矩阵尺寸和类型参数来创建 Mat 类
    Mat a(3, 3, CV_8UC1);

    // 用Size()来创造 Mat 类
    Mat b(Size(4, 4), CV_8UC1); // size(a,b)，a代表列，b代表行

    // Mat 类的赋值
    Mat c0(5, 5, CV_8UC1, Scalar(4, 5, 6));
    Mat c1(5, 5, CV_8UC2, Scalar(4, 5, 6));
    Mat c2(5, 5, CV_8UC3, Scalar(4, 5, 6));

    // 枚举法赋值
    Mat d = (Mat_<int>(1, 5) << 1, 2, 3, 4, 5);
    Mat e = (Mat_<double>(1, 5) << 1.0, 2.0, 3.1, 4.2, 5.3);

    // 类方法赋值
    Mat f = Mat::eye(3, 3, CV_8UC1); // 单位矩阵
    Mat h = Mat::diag(d);            // 对角矩阵，参数一定是 Mat 类的一维变量

    // 从子类中进行赋值
    Mat i = Mat(h, Range(0, 2), Range(0, 2)); // 此时矩阵第一行第一列的数为(0,0)类似于索引

    cout << a << endl;
    cout << b << endl;
    cout << c0 << endl;
    cout << c1 << endl;
    cout << c2 << endl;
    cout << d << endl;
    cout << e << endl;
    cout << f << endl;
    cout << h << endl;
    cout << i << endl;

        return 0;
}