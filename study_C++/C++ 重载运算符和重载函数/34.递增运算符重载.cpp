#include <iostream>
using namespace std;

// 重载递增运算符

// 自定义的整型
class MyInteger
{
    friend ostream &operator<<(ostream &cout, MyInteger myint);

public:
    // 默认构造函数
    MyInteger()
    {
        num = 0;
    }

    // 重载前置++运算符
    MyInteger &operator++() // 返回引用是为了对一个数据进行操作
    {
        // 先进行++运算操作
        num++;
        // 后返回他的本身
        return *this;
    }
    // 重载后置++运算符
    MyInteger operator++(int) // int 代表占为参数，可以用于区分前置和后置
    {
        // 先 记录当时结果
        MyInteger temp = *this;
        // 后 递增
        num++;
        // 最后将记录结果返回
        return temp;
    }

private:
    int num;
};

// 重载<<
ostream &operator<<(ostream &cout, MyInteger myint)
{
    cout << myint.num;
    return cout;
}

void test01()
{
    MyInteger myint;
    cout << myint << endl;
}

void test02()
{
    MyInteger myint;

    cout << myint++ << endl;
    cout << myint << endl;
}

int main()
{
    test01();

    test02();

    return 0;
}
