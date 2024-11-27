#include <iostream>
using namespace std;

// 静态成员变量
class Person
{
public:
    // 1.所有对象都共享同一份数据
    // 2.编译阶段就分配内存
    // 3.类内声明，类外初始化操作
    static int A;
    // 静态成员也是由访问权限的
private:
    static int B;
};

int Person::A = 100;
int Person::B = 200;

void test01()
{
    Person p1;
    cout << p1.A << endl;

    Person p2;
    p2.A = 200;
    cout << p1.A << endl;
}

void test02()
{
    // 静态成员变量 不属于某个对象上 ，所有对象都共享同一份数据
    // 因此；静态成员变量有两种访问方式

    // 1、通过对象进行访问
    Person p1;
    cout << p1.A << endl;

    // 2、通过类名进行访问
    cout << Person::A << endl;
    // cout << Person::B << endl;
}

int main()
{
    test01();

    return 0;
}