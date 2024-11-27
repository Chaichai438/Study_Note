#include <iostream>
using namespace std;

// 动物类
class Animal
{
public:
    int age;
};

// 利用虚继承 解决菱形继承问题
// 在继承之前加上关键字 virtual 变为虚继承
// Animal类 成为虚基类
// 虚继承 继承了两个指针 通过指针的偏移量指向基类中唯一的数据

// 羊类
class Sheep : virtual public Animal
{
};

// 驼类
class Camel : virtual public Animal
{
};

// 羊驼类
class Alpaca : public Sheep, public Camel
{
};

void test01()
{
    Alpaca al;
    al.Sheep::age = 18;
    al.Camel::age = 28;

    // 当菱形继承，两个父类拥有相同数据，需要加以作用域区分
    cout << "al.Sheep::age = " << al.Sheep::age << endl;
    cout << "al.Camel::age = " << al.Camel::age << endl;
    cout << "al.age = " << al.age << endl;

    // 这份数据只有一份就可以，菱形继承导致资源浪费
}

int main()
{
    test01();
    return 0;
}