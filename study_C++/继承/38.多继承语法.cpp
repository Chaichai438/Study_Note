#include <iostream>
using namespace std;

class Base1
{
public:
    Base1()
    {
        A = 100;
    }
    int A;
};

class Base2
{
public:
    Base2()
    {
        A = 200;
    }
    int A;
};

// 子类 需要继承Base1和Base2
// 语法：class 子类: 继承方式 父类1, 继承方式 父类2,......
class Son : public Base1, public Base2
{
public:
    Son()
    {
        C = 300;
        D = 400;
    }
    int C;
    int D;
};

void test01()
{
    Son s;

    cout << "sizeof Son = " << sizeof(s) << endl;

    // 当父类中出现同名成员，需要加作用域区分
    // 实际开发中不建议用多继承
    cout << "Base1  A = " << s.Base1::A << endl;
    cout << "Base2  A = " << s.Base2::A << endl;
}

int main()
{
    test01();

    return 0;
}