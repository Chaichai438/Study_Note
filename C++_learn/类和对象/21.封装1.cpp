#include<iostream>
using namespace std;

//类是 C++ 的核心特性，通常被称为用户定义的类型。他可以面向对象

//C++中的类可以被看作是一个“蓝图”或“模板”，用于创建具有特定属性（特征）和行为（功能）的对象。
//想象一下，你正在建造一座房子，你需要一个蓝图来指导你如何建造它。在C++中，类就是这样的蓝图。
//例如我们现在想求得一个盒子的体积，你需要以下信息：

class Box
{
      //访问权限
      //公共权限  
   public:             // 关键字public确定了类成员的访问属性
      //属性
      double length;   // 盒子的长度
      double breadth;  // 盒子的宽度
      double height;   // 盒子的高度
      //行为
      void set(double len,double bre,double hei)
   {
      length = len;
      breadth = bre;
      height = hei;
   }
      
      double get()
   {
         return  length * breadth * height;
   }
};

int main()
{
   //我们可以类比一下结构体
   Box b1;        // 声明 b1，类型为 Box
   Box b2;        // 声明 b2，类型为 Box
   Box b3;        // 声明 b3，类型为 Box
   double V = 0.0;     // 用于存储体积   
   
   //初始化类中的对象
   b1 = {5.0,5.0,5.0};
   b2 = {4.0,4.0,4.0};

   V= b1.height * b1.length * b1.breadth;
   cout << "b1 的体积：" << V << endl;

   V= b2.height * b2.length * b2.breadth;
   cout << "b2 的体积：" << V << endl;

   b3.set(3.0,3.0,3.0);
   V = b3.get();
   cout << "b3 的体积：" << V << endl;


   /*总结一下：
   class语法与结构体有着相似之处
   不同的是，class的具体内涵和struct不同(需要区自主了解一下)，而且class中可以包含对象的行为(以函数的形式)
   */
   return 0;
}
