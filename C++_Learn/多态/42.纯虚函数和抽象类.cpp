#include <iostream>
using namespace std;

// 纯虚函数和抽象类
// 通常父类中虚函数是毫无意义的，主要都是调用子类中重写的内容，因此可以将虚函数改为纯虚函数，该类也叫做抽象类

class Base
{
public:
    // 纯虚函数
    // 只要有一个纯虚函数，这个类称为抽象函数
    // 抽象类特点：
    // 1、无法实例化对象
    // 2、抽象类的子类 必须要重写父类中的纯虚函数 否则也属于抽象类
    virtual void func() = 0;
};

class Son : public Base
{
public:
    virtual void func()
    {
        cout << "func()函数的调用" << endl;
    }
};

void test01()
{
    // Base b;   // 抽象类是无法实例化对象
    // new Base; // 抽象类是无法实例化对象

    // Son s;    //子类必须要重写父类中的纯虚函数 否则也无法实例化对象

    Base *base = new Son;
    base->func();
}

int main()
{
    test01();
    return 0;
}