#include <iostream>
using namespace std;

// 建议这部分观看黑马程序员P122
// 笔记很难懂

// 左移运算符重载
class Person
{
public:
    Person(int a, int b)
    {
        A = a;
        B = b;
    }
    friend ostream &operator<<(ostream &cout, Person &p);

private: // 一般设为私有，若我们想访问可以使用友元函数
    // 利用成员函数重载 左移运算符   p.operator<<(cout)     简化版本: p  <<  cout            很怪
    // 所以我们通常不会利用成员函数重载<<运算符,因为无法实现cout在左侧
    // void operator<<(Person &p)
    int A;
    int B;
};

ostream &operator<<(ostream &cout, Person &p) // 本质       operator << (cout ,p) 简化版本 cout << p
{                                             // cout 的数据类型为ostream输出流,点击查看定义即可或者KIMI
    cout << "A =" << p.A << " B =" << p.B;
    return cout;
}

void test01()
{
    Person p(10, 20);

    cout << p << endl; // 在上部分函数类型还是void的时候,我们运行cout << p << endl时编译器会给我们报错
    // 这是因为像这种类型的代码运用了链式编程的思想（前面的提到过），cout << p 运行后只有返回值时同一类型的时候才能继续往下运行，所以我们需要返回值cout
}

int main()
{
    test01();

    return 0;
}
