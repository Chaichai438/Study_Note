#include <iostream>
using namespace std;

class Person
{
public:
    Person(int a)
    {
        Age = new int(a); // 堆区由程序员手动开辟，也需要手动释放,释放的时机在析构函数中
    }
    ~Person()
    {
        if (Age == NULL)
        {
            delete Age;
            Age = NULL;
        }
    }
    int *Age;
    // 重载 赋值运算符
    Person &operator=(Person &p)
    {
        // 编译器提供浅拷贝
        // Age = p.Age;

        // p2在赋值前已经在堆区有数据了,应该先判断是否有属性在堆区,如果有先释放干净，然后再深拷贝
        if (Age != NULL)
        {
            delete Age;
            Age = NULL;
        }

        // 深拷贝
        Age = new int(*p.Age);

        return *this;
    }
};

void test01()
{
    Person p1(19);

    Person p2(20);

    Person p3(30);

    p3 = p2 = p1; // 赋值操作

    cout << "p1的年龄:" << *p1.Age << endl;
    cout << "p2的年龄:" << *p2.Age << endl;
    cout << "p3的年龄:" << *p3.Age << endl;
}

int main()
{
    test01();
    return 0;
}