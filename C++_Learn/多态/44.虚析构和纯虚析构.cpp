#include <iostream>
using namespace std;

class Animal
{
public:
    Animal()
    {
        cout << "Animal的构造函数调用" << endl;
    }

    // 利用虚析构可以解决 父类指针释放子类对象时不干净的问题
    // virtual ~Animal()
    // {
    //     cout << "Animal的虚析构函数调用" << endl;
    // }

    // 纯虚析构 需要声明 也需要实现
    //有了纯虚析构之后 这个类也属于抽象类 无法实例化对象
    virtual ~Animal() = 0;

    // 纯虚函数
    virtual void speak() = 0;
};

Animal::~Animal()
{
    cout << "Animal的纯虚析构函数调用" << endl;
}

class Cat : public Animal
{
public:
    Cat(string name)
    {
        cout << "Cat的构造函数调用" << endl;
        Name = new string(name);
    }

    virtual void speak()
    {
        cout << *Name << "在喵喵喵" << endl;
    }

    ~Cat()
    {
        if (Name != NULL)
        {
            cout << "Cat的析构函数调用" << endl;
            delete Name;
            Name = NULL;
        }
    }

    string *Name;
};

void test01()
{
    Animal *animal = new Cat("Tom");
    animal->speak();
    // 父类的指针在析构时候 不会调用子类中析构函数，导致子类如果有堆区属性，出现内存泄漏
    // 解决方法：将Animal变为虚析构
    delete animal;
}

int main()
{
    test01();

    return 0;
}