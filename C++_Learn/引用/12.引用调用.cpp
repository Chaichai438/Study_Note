#include <iostream>
using namespace std;

/*
在理解引用函数之前，先来了解下什么是引用：
他是不同于指针的在C++中独有的
引用本身不占用内存，它只是对原始变量的一个别名。
当使用引用调用函数时，实际上是将函数的参数绑定到这个原始变量上，而不是创建一个新的变量副本，从而提高效率。
可以上kimi搜一下引用的内在逻辑，相信你很快就能理解引用
*/
void swap(int &x, int &y);
 
int main ()
{
   int a = 100;
   int b = 200;
 
   cout << "交换前，a 的值：" << a << endl;
   cout << "交换前，b 的值：" << b << endl;
 
  
   swap(a, b);
 
   cout << "交换后，a 的值：" << a << endl;
   cout << "交换后，b 的值：" << b << endl;
 
   return 0;
}
 
//将传入的参数与x,y绑定,相当于我跟你这个a，b变量共生死了！你怎么样我怎么样，函数也就能改变a，b的数值了，但他并没有涉及到内存
void swap(int &x, int &y)
{
   int temp;
   temp = x; 
   x = y;    
   y = temp; 
  
   return;
}