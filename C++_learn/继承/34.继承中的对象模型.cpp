#include <iostream>
using namespace std;

// 继承中的对象模型

class Base
{
public:
    int A;

private:
    int B;

protected:
    int C;
};

class Son : public Base
{
public:
    int D;
};

void test01()
{
    // 16
    // 父类中所有非静态成员属性都会被子类继承下去
    // 父类中私有成员属性 被编译器给隐藏了 因此访问不到 但是也被继承下去了
    cout << "size of Son = " << sizeof(Son) << endl;
}

int main()
{
    test01();
    return 0;
}