#include <iostream>
using namespace std;

// 构造函数的调用规则
// 1.创建一个类，C++编译器会给每个类都添加至少三个函数
// 默认构造(空实现)
// 析构函数(空实现)
// 拷贝构造(值拷贝)

// 2.如果我们写了有参构造函数，编译器就不再提供默认构造，依然提供默认拷贝构造
// 3.如果我们提供拷贝构造，那么编译器不会提供其他函数了;

// WARNINGS:很不建议参考下面的代码了（因为有的要注释很麻烦），只需要明白上面三个知识点就好了,如果想学习的话建议观看黑马的视频p109
class Person
{
public:
    /*Person()
    {
        cout << "默认构造函数的调用" << endl;
    }*/
    Person(int a)
    {
        cout << "有参构造函数的调用" << endl;
        age = a;
    }

    ~Person()
    {
        cout << "析构函数的调用" << endl;
    }
    /*Person(const Person &p)
    {
        cout << "拷贝构造函数的调用" << endl;
        age = p.age;
    }*/
    // 当把拷贝函数注释调后，运行程序发现终端中并没有出现"拷贝构造函数的调用"，这是因为编译器为我们又提供了一个新的拷贝构造函数，里面有类似于30行这句代码，所以才会出现有两行“析构函数的调用”

    int age;
};

/*void test01()
{
    Person p1;
    p1.age = 18;
    // 拷贝构造函数
    Person p2(p1);
    cout << "p2年龄为：" << p2.age << endl;
}*/

void test02()
{
    // Person p; // 当我们注释class中的默认构造函数时,我们会发现程序报错

    Person p1(28);
    Person p2(p1);
    cout << "p2年龄为：" << p2.age << endl;
}

int main()
{
    // test01();         //建议一个案例一个案例来运行代码
    test02();

    return 0;
}