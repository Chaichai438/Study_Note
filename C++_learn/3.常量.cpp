#include<iostream>

#define DAY 7                //预处理器定义常量，特点：不能被修改

#define MONTH 30              

using namespace std;

int main()
{
    cout << DAY << endl;
    
    cout << MONTH << endl;

    const int SHEXIA = 12;   //const 关键字 修饰变量，使其变为常量

    cout << "生肖一共有:" << SHEXIA << " 个" << endl;

    return 0;
}