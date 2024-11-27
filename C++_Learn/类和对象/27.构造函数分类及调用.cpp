#include <iostream>
using namespace std;
// 1.构造函数分类及调用
// 分类
// 按照参数分类
// 无参数构造（系统默认构造）    有参数构造

// 按照类型分类
// 普通构造    拷贝构造函数
class Person
{
public:
    // 构造函数
    Person()
    {
        cout << "Person的无参构造函数调用" << endl;
    }
    Person(int a)
    {
        age = a;
        cout << "Person的有参构造函数调用" << endl;
    }
    // 拷贝构造函数
    Person(const Person &p)
    {
        // 将传入的人身上的所有属性，拷贝到当前对象身上
        age = p.age;
        cout << "Person的拷贝构造函数调用" << endl;
    }
    ~Person()
    {
        cout << "Person的析构函数调用" << endl;
    }
    int age;
};

// 调用
void test01()

{
    // 1.括号法
    // Person p1;     // 默认构造函数        建议每行代码单独运行一遍
    // Person p2(10); // 调用有参构造函数
    // 调用拷贝构造函数
    // Person p3(p2);
    // cout << "p2的年龄为：" << p2.age << endl;
    // cout << "p3的年龄为：" << p3.age << endl;

    // 注意事项1
    // 调用默认构造函数的时候，不要加(),因为Person()这句代码，编译器会认为是一个函数的声明,不会认为在创建对象
    cout << "--------------------------------" << endl;
    // 2.显示法
    Person p1;
    Person p2 = Person(10); // 有参构造
    Person p3 = Person(p2); // 拷贝构造

    // Person(10);  //匿名对象 特点：当前行执行结束后，系统会立即回收匿名对象，可以将前面的代码注释调再运行这行代码，体会一下
    // cout <<"aaaaa"<< endl;

    // 注意事项2
    // 不要利用拷贝构造函数 初始化匿名对象 编译器会认为 Person(p3)==Person p3

    //  3.隐式转化法
    Person p4 = 10; // 相当于写了 Person p4 = Person(10) 有参构造
    Person p5 = p4; // 拷贝构造

    // 根据个人习惯选用不同的方法
}

int main()
{
    test01();

    return 0;
}