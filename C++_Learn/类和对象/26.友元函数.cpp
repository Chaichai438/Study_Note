#include <iostream>
#include <string>
using namespace std;

class Person
{
public:
    string name; // 可读可写

protected:
    int age; // 可写

private:
    double height = 1.80; // 可写

public:
    void setName(string n)
    {
        name = n;
    }

    void printName()
    {
        cout << "姓名为：" << name << endl;
    }

    void setAge(int a)
    {
        age = a;
    }

    void printHei()
    {
        cout << "身高为：" << height << endl;
    }

    friend void printAge1(Person p);  //在这里进行友元函数的声明

    friend void printHeight(Person p);//在这里进行友元函数的声明

private:
    void printAge()
    {
        cout << "年龄为：" << age << endl;
    }
};

void printAge1(Person p)
{
    p.printAge();
};
void printHeight(Person p)
{
    p.printHei();
};

int main()
{
    Person p1;

    // 设置并输出姓名
    p1.setName("CWZ");
    p1.printName();

    // 设置年龄
    p1.setAge(19);
    // p1.printAge();         // 不可访问

    // 输出身高
    p1.printHei();
    // p1.setHei();           // 不可访问

    // 友元函数
    printAge1(p1); /*友元函数可以访问类里面的所有成员
                  例如age本来只可写，现在我们能得到年龄的数据*/

    // 访问身高

    printHeight(p1);

    return 0;
}