#include <iostream>
using namespace std;

// 加号运算符重载
class Person
{
public:
    // 1、成员函数重载加号
    // 只能在当前类中使用
    /*Person operator+(Person &p)
    {
        Person temp;
        temp.A = this->A + p.A;
        temp.B = this->B + p.B;
        return temp;
    }*/
    int A;
    int B;
};

// 2、全局函数重载加号
// 可以在所有类中使用
Person operator+(Person &p1, Person &p2)
{
    Person temp;
    temp.A = p1.A + p2.A;
    temp.B = p2.B + p2.B;
    return temp;
};
// 函数重载的版本
Person operator+(Person &p1, int num)
{
    Person temp;
    temp.A = p1.A + num;
    temp.B = p1.B + num;
    return temp;
};

void test01()
{
    Person p1;
    p1.A = 10;
    p1.B = 10;
    Person p2;
    p2.A = 10;
    p2.B = 10;

    // 成员函数重载本质调用
    // Person p3+p1.operate+(p2)

    // 全局函数重载本质调用
    // Person p3 = operator+(p1, p2)
    Person p3 = p1 + p2;
    // 运算符重载 也可以发生函数重载

    Person p4 = p1 + 10; // Person + int

    cout << "p3.A=" << p3.A << endl;
    cout << "p3.B=" << p3.B << endl;

    cout << "p4.A=" << p4.A << endl;
    cout << "p4.B=" << p4.B << endl;
}

int main()
{
    test01();

    return 0;
}