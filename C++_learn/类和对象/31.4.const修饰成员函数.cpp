#include <iostream>
using namespace std;

class Person
{
public:
    // this指针的本质： 是指针常量 指针的指向不可以修改
    // const Person *const this
    // 在成员函数后面加const，修饰的是this指向,让指针指向的值也不可修改
    void showPerson() const // 常函数
    {
        this->B = 100;
        // this->A  = 100; //去掉const，（ Person *const this）this指针可以修改指针指向的值
        // this = NULL;    //this指针不可修改指针的指向      本质（Person *const this）
    }
    void func() {}
    int A;
    mutable int B; // 特殊变量，即使在常函数中也可以修改这个值
};

void test01()
{
    Person p;
    p.showPerson();
}

// 常对象
void test02()
{
    const Person p; // 在对象前加const，变为常对象
    p.A = 100;      // 也不能改
    p.B = 200;      // B是特殊值，在常对象下也可以修改

    // 常对象只能调用常函数
    p.showPerson();
    // p.func();   常对象 不可以调用普通成员函数，因为普通成员函数可以修改属性
}

int main()
{
    test01();
    test02();
    return 0;
}