#include <iostream>
using namespace std;

// 重载关系运算符

class Person
{
public:
    Person(string name, int age)
    {
        Name = name;
        Age = age;
    }
    string Name;
    int Age;
    bool operator==(Person &p)
    {
        if (this->Name == p.Name && this->Age == p.Age)
        {
            return true;
        }
        return false;
    }
   
    bool operator!=(Person &p)
    {
        if (this->Name != p.Name && this->Age != p.Age)
        {
            return false;
        }
        return true;
    }
};

void test01()
{
    Person p1("Tom", 18);
    Person p2("Tom", 18);

    if (p1 == p2)
    {
        cout << "p1和p2是相等的" << endl;
    }
}

int main()
{
    test01();
    return 0;
}