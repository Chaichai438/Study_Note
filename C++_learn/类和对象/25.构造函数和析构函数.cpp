#include <iostream>
using namespace std;

// 对象的初始化和清理
// 1、构造函数 进行初始化操作
class Person
{
    // 1.1、构造函数
    // 没有返回值 不用写void
    // 函数名与类名相同
    // 构造函数可以有参数，可以发生重载(后面学习)
    // 创建对象的时候，构造函数会自动调用，而且只会调用一次
public:
    Person()
    {
        cout << "构造函数的调用" << endl;
    }
    // 2.析构函数 进行清理的操作
    // 没有返回值 不用写void
    // 函数名与类名相同 在名称前面加~
    // 不可以有参数，不能发生重载
    // 对象销毁前 会自动调用析构函数，而且只会调用一次
    ~Person()
    {
        cout << "析构函数的调用" << endl;
    }
};
void test01()
{
    Person p;
}

int main()
{
    test01();

    return 0;
}