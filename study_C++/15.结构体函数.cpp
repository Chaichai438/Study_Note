#include <iostream>
#include <cstring>
//大家看看就好了，这个和C语言是一脉相承的，C语言黑马里面甚至讲得更清楚，可以把之前写过的代码拿过来做一个迁移

 
using namespace std;
void printBook( struct Books book );
 
// 声明一个结构体类型 Books 
struct Books
{
   char  title[50];
   char  author[50];
   char  subject[100];
   int   book_id;
};
 
int main( )
{
   Books Book1;        // 定义结构体类型 Books 的变量 Book1
   Books Book2;        // 定义结构体类型 Books 的变量 Book2
 
    // Book1 详述
   strcpy( Book1.title, "C++ 教程");
   strcpy( Book1.author, "xxx"); 
   strcpy( Book1.subject, "编程语言");
   Book1.book_id = 12345;
 
   // Book2 详述
   strcpy( Book2.title, "ROS教程");
   strcpy( Book2.author, "xxx");
   strcpy( Book2.subject, "前端技术");
   Book2.book_id = 12346;
 
   // 输出 Book1 信息
   printBook( Book1 );
 
   cout << "---------------------------"<< endl;
   // 输出 Book2 信息
   printBook( Book2 );
 
   return 0;
}
void printBook( struct Books book )
{
   cout << "书标题 : \t" << book.title << endl;
   cout << "书作者 : \t" << book.author << endl;
   cout << "书类目 : \t" << book.subject << endl;
   cout << "书 ID : \t" << book.book_id << endl;
}