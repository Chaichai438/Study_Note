#include <iostream>
using namespace std;

// 成员变量 和 成员函数 分开存储的

class Person
{
public:
    int A;        // 非静态成员变量 属于内的对象上，其他都不属于
    static int B; // 静态成员变量

    void func() {}         // 非静态成员函数
    static void func2() {} // 静态成员函数
};

void test01()
{
    Person p;
    // 占对象占用的内存空间 : 1
    // C++编译器会给每个空对象也分配一个字节空间，是为了区分空对象占内存的位置
    // 每个空对象也应该有一个独一无二的内存地址
    cout << "size of p = " << sizeof(p) << endl;
}

void test02()
{
    Person p;
    cout << "size of p = " << sizeof(p) << endl;
}

int main()
{
    // test01();
    test02();

    return 0;
}