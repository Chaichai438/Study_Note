//练习
//设计一个学生类，属性有姓名学号,可以给姓名学号赋值并显示
#include<iostream>
using namespace std;

class Student
{
    public:
        string name;
        string ID;

        void PrintINFO()
        {
             cout << "学生的姓名：" << name << endl;
             cout << "学生的学号：" << ID << endl;
        };

        void amend()
        {
             PrintINFO();
             cout << "请修改学生的姓名："  << endl;
             cin >> name;
             cout << "请修改学生的学号："  << endl;
             cin >> ID;
             PrintINFO();
        }
};

int main()
{
    //创建并初始化一个对象
    Student stu1;
    stu1 = {"CWZ","123456"};
 
    stu1.amend();
    

    return 0;

}