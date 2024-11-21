#include <iostream>
using namespace std;

// 拷贝构造函数的调用时机

class Person
{
public:
    Person()
    {
        cout << "Person默认构造函数的调用" << endl;
    }
    Person(int a)
    {
        age = a;
        cout << "Person有参构造函数的调用" << endl;
    }
    Person(const Person &p)
    {
        age = p.age;
        cout << "Person拷贝构造函数的调用" << endl;
    }
    ~Person()
    {
        cout << "Person析构函数的调用" << endl;
    }

    int age;
};
// 1.使用一个已经创建了的对象来初始化一个新的对象
void test01()
{
    Person p1(20);
    Person p2(p1);

    cout << "p2的年龄为：" << p2.age << endl;
}
// 2.值传递的方式给函数参数传值
void doWork(Person p)
{
}
void test02()
{
    Person p;
    doWork(p);
}
Person doWork2()
{
    Person p1;
    cout << (int *)&p1 << endl;
    return p1; // 会按照这个对象拷贝出一个新的对象返回给外面
}
// 3.值方式返回局部对象
void test03()
{
    Person p = doWork2();
    cout << (int *)&p << endl;
}

int main()
{
    // test01();
    // test02();
    test03();

    return 0;
}