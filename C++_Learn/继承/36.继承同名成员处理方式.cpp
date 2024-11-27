#include <iostream>
using namespace std;

class Base
{
public:
    Base()
    {
        A = 100;
    }

    void func()
    {
        cout << "Base下的 func()调用" << endl;
    }

    void func(int a)
    {
        cout << "Base下的 func(int a)调用" << endl;
    }
    int A;
};

class Son : public Base
{
public:
    Son()
    {
        A = 200;
    }

    void func()
    {
        cout << "Son下的 func()调用" << endl;
    }
    int A;
};

// 同名成员属性处理
void test01()
{
    Son s;
    cout << "Son下的 A = " << s.A << endl;
    // 如果通过子类对象访问到父类中的同名成员，需要加作用域
    cout << "Base下的 A = " << s.Base::A << endl;
}

// 同名成员函数处理
void test02()
{
    Son s;
    s.func(); // 直接调用 调用是子类中的同名成员

    // 调用父类的需要加作用域
    s.Base ::func();

    // 如果子类中出现和父类中同名的成员函数，子类的同名成员会隐藏父类中所有同名成员函数
    //  s.func(100);

    // 如果项访问父类中被隐藏的同名函数成员，需要加作用域
    s.Base::func(99);
}

int main()
{
    test01();
    test02();

    return 0;
}