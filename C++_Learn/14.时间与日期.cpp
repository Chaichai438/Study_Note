#include<iostream>
#include<ctime>

using namespace std;


 int main()
{
   //该函数返回系统的当前日历时间，自1970年1月1日以来经过的秒数。如果系统没有时间，则返回 -1。
   time_t now = time(0);//语法 ： time_t <name> = time(NULL) 0也可以
   cout << now << endl;//获取到时间戳，他表示的是自1970年1月1日以来经过的秒数，我们看不懂这个所以我们要转换成我们看的明白的东西

   char* dt = ctime(&now);
   cout << dt << endl;//小问题：char* dt打印出来不应该是指针吗？怎么是字符串？
   //标准输出函数打印一个 char*类型的变量时，它会将该变量视为一个字符串（KIMI)
   //我们动手实践一下

   char str[100] = "Hello World";
   char* p = str;
   cout << p << "\n";
   printf("%s\n",p);//也是这样，我详细的去查了一下
   /*在C和C++中，char* 类型的指针被特殊对待，因为它通常用于指向字符串。字符串在C和C++中是以 null 结尾的字符数组，即以 \0 字符结束。
    当 cout 接收到一个 char* 类型的指针时，它会将这个指针视为指向一个字符串的起始地址，并开始从这个地址逐个字符地读取，直到遇到 null 字符 \0 为止。
    这个过程实际上就是字符串的输出。*/


    
   
   return 0;
   
}
