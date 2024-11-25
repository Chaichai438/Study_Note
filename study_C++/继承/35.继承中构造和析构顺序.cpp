#include <iostream>
using namespace std;

class Base
{
public:
    Base()
    {
        cout << "Base的构造函数" << endl;
    }
    ~Base()
    {
        cout << "Base的析构函数" << endl;
    }
};

class Son : public Base
{
public:
    Son()
    {
        cout << "Son的构造函数" << endl;
    }
    ~Son()
    {
        cout << "Son的析构函数" << endl;
    }
};

void test01()
{
    Base B;
    // 继承中的构造和析构顺序如下:
    // 先构造父类，在构造子类    先析构子类，再析构父类
    Son s;
}

int main()
{
    test01();

    return 0;
}