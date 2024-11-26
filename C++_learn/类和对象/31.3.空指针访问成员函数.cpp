#include <iostream>
using namespace std;

class Person
{
public:
    void showClassName()
    {
        cout << "this is Person class" << endl;
    }
    void showPersonAge()
    {
        // 报错原因：传入的指针为空,否则会导致程序崩溃(进行了非法操作)，那么加入以下代码防止程序崩溃
        if (this == NULL)
        {
            return;
        }

        cout << "age = " << this->age << endl;
    }
    int age;
};

void test01()
{
    Person *p = NULL;
    p->showClassName();
    p->showPersonAge();
}

int main()
{
    test01();
    return 0;
}