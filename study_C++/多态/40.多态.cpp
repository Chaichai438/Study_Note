#include <iostream>
using namespace std;

class Animal
{
public:
    virtual void speak()
    {
        cout << "动物在说话" << endl;
    }
};

// 猫类
class Cat : public Animal
{
public:
    // 重写 函数返回值类型 函数名 参数列表 完全相同
    virtual void speak()
    {
        cout << "喵喵喵" << endl;
    }
};

// 狗类
class Dog : public Animal
{
public:
    virtual void speak()
    {
        cout << "汪汪汪" << endl;
    }
};

// 执行说话的函数
// 地址早绑定 在编译阶段确定函数地址
// 如果想执行让猫说话 那么函数地址就不能提前绑定 需要在运行阶段进行绑定 地址晚绑定

// 动态多态满足条件
// 1、有继承关系
// 2、子类重写父类的虚函数

// 动态多态的调用
// 父类的指针或者引用 指向子类对象

void doSpeak(Animal &ani) // Animal &ani =  cat;
{
    ani.speak();
}

void test01()
{
    Cat cat;
    doSpeak(cat);
    Dog dog;
    doSpeak(dog);
}

void test02()
{
    cout << "sizeof Animal = " << sizeof(Animal) << endl;
}

int main()
{
    test01();
    test02();

    return 0;
}