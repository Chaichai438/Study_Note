#include <iostream>
using namespace std;

class Person
{
public:
    // 静态成员函数
    static void func()
    {
        A = 100; // 静态成员函数 可以访问 静态成员变量
        // B = 200;//静态成员函数 不可以访问 非静态成员变量，无法区分到底是哪个对象的
        cout << "static void func的调用" << endl;
    }

    static int A; // 静态成员变量

    int B; // 非静态成员变量

    // 静态成员函数也是有访问权限的
private:
    static void func2()
    {
        cout << "static void func2的调用" << endl;
    }
};

int Person::A = 100;

void test01()
{
    // 1、通过对象访问
    Person p;
    p.func;
    // 2、通过类名访问
    Person::func();

   // Person::func2();类外访问不到私有静态成员函数
}

int main()
{
    test01();

    return 0;
}