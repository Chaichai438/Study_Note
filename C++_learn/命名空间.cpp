#include <iostream>
#include <string>
using namespace std;
// 命名空间
// 作用
// 以附加信息来区分不同的类，函数和变量
// 例子：在班上有两个都叫王嘉怡的同学，我们只能根据他们的特征来区分他们
// 有一个年龄大我们叫她大王，另一个就叫小王

namespace Older
{
    // 变量
    string name = "王嘉怡";

    // 函数
    void func()
    {
        cout << "Older内函数的调用" << endl;
    }

    // 类
    class Person
    {
    public:
        int age = 18;
    };
};

namespace Younger
{
    // 变量
    string name = "王嘉怡";

    // 函数
    void func()
    {
        cout << "Youger内函数的调用" << endl;
    }

    // 类
    class Person
    {
    public:
        int age = 17;
    };
};

void test01()
{
    cout << "这是大" << Older::name << endl;
    cout << "这是小" << Younger::name << endl;
}

void test02()
{
    Older::func();
    Younger::func();
}

void test03()
{
    Older::Person p1;
    Younger::Person p2;

    cout << "大王的年龄：" << p1.age << "岁" << endl;
    cout << "小王的年龄：" << p2.age << "岁" << endl;
}

int main()
{
    test01();
    test02();
    test03();

    return 0;
}