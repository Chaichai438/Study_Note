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
    return p1; // （会按照这个对象拷贝出一个新的对象返回给外面）,虽然视频是这么讲的，但是我自己得到的结果却是内存地址相同，并没有调用拷贝构造函数（原因在最下方）
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
    // KIMI解释:
    // 关于你的注释中提到的内存地址问题，你提到的结果是正确的。
    // 在大多数现代C++编译器中，对于返回局部对象的情况，编译器会使用返回值优化（Return Value Optimization, RVO）或者命名返回值优化（Named Return Value Optimization, NRVO）。
    // 这些优化技术可以消除临时对象的创建，直接在目标位置构造对象，从而避免额外的拷贝构造调用。
    // 这就是为什么你看到的内存地址相同，因为实际上并没有发生拷贝构造。
}   