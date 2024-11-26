#include <iostream>
using namespace std;
// 继承中同名静态成员的处理方法

class Base
{
public:
    static void func()
    {
        cout << "Base下的 static func()调用" << endl;
    }

    static int A; // 静态成员属性特点：1、所有成员共享同一份数据 2、编译阶段就分配内存 3、类内声明类外初始化
    static void func(int a)
    {
        cout << "Base下的 static func(int a)调用" << endl;
    }
}; // 静态成员函数：1、只能访问静态成员变量，不能访问非静态成员变量

int Base::A = 100;

class Son : public Base
{
public:
    static void func()
    {
        cout << "Son下的 static func()调用" << endl;
    }

    static int A;

    static void func(int a)
    {
        cout << "Son下的 static func(int a)调用" << endl;
    }
};

int Son::A = 200;

// 同名静态成员属性
void test01()
{
    // 1、通过对象访问
    Son s;
    cout << "通过对象访问: " << endl;
    cout << "Son下  A = " << s.A << endl;
    cout << "Base下  A = " << s.Base::A << endl;

    // 2、通过类名访问
    cout << "通过类名访问: " << endl;
    cout << "Son下  A = " << Son::A << endl;
    // 第一个：：代表通过类名方式访问   第二个：：代表访问父类作用域下
    cout << "Base下  A = " << Son ::Base ::A << endl;
}

// 同名静态成员函数
void test02()
{
    // 1、通过对象访问
    Son s;
    cout << "通过对象访问: " << endl;
    s.func();
    s.Base::func();
    s.func(100);
    s.Base::func(100);

    // 2、通过类名访问
    cout << "通过类名访问: " << endl;
    Son::func();
    Son::Base::func();

    Son::func(200);
    // 如果子类中出现和父类中同名的成员函数，子类的同名成员会隐藏父类中所有同名成员函数
    // 如果项访问父类中被隐藏的同名函数成员，需要加作用域
    Son::Base::func(200);
}

int main()
{
    test01();
    cout << "--------------------------" << endl;
    test02();

    return 0;
}