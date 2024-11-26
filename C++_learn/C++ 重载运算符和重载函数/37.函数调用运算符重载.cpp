#include <iostream>
#include <string>
using namespace std;

class MyPrint
{
public:
    // 重载函数调用运算符
    void operator()(string test)
    {
        cout << test << endl;
    }
};

void myprint02(string test)
{
    cout << test << endl;
}

void test01()
{
    MyPrint myprint;

    myprint("Hello World!!"); // 由于使用起来非常像函数，因此称为仿函数

    myprint02("Hello World!!");
}

// 仿函数非常灵活，没有固定的写法
// 加法类
class Myadd
{
public:
    int operator()(int n1, int n2)
    {
        return n1 + n2;
    }
};

void test02()
{
    Myadd myadd;
    int res = myadd(98, 2);

    cout << "res1 = " << res << endl;

    // 匿名函数对象
    cout << "res2 =" << Myadd()(100, 100) << endl;
}

int main()
{
    test01();

    test02();
    return 0;
}