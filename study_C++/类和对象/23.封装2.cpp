#include <iostream>
#include <string>
using namespace std;

// 访问权限
// 公共   public        成员 类内可以访问，类外可以访问属性
// 保护   protected     成员 类内可以访问，类外不能访问属性
// 私有   private       成员 类内可以访问，类外不能访问属性

class Person
{
public:
       string Name;

protected:
       string Car;

private:
       int password;

public:
       // 公共权限
       void func()
       {
              Name = "CWZ";
              Car = "BT";
              password = 12345;
       }
};

int main()
{
       Person p1;

       p1.Name = "TSY";
       // p1.Car = "BT";           //保护权限内容在类外访问不到
       // p1.password = "123456";  //私有权限内容在类外访问不到

       p1.func(); // 当这个函数从public改动到private时，函数就不可用了
}