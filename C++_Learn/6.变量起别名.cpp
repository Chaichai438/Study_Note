#include<iostream>

using namespace std;

int main()
{
    /*
    - typedef 顾名思义就是类型定义(type define)，有点类似于C语言中给结构体起别名
    - 可以使用 typedef 为一个已有的类型取一个新的名字 
    - 语法： typedef 数据类型 <name>
    - 思考一下这个指令存在的意义是什么?
    */    
    
    typedef int it;
    typedef double de;
    typedef float ft;

    it a = 10;
    de b = 20.3;
    ft c = 19.3f;

    cout << a << endl;
    cout << b << endl;
    cout << c << endl;

    return 0;
}