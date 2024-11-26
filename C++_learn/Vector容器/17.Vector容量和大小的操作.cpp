#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int>v1;
    //录入0-9数据
    for(int i = 0;i < 10;i++)
    {
        v1.push_back(i);
    }

    if(v1.empty())             //如果v1里面没有元素,则返回0；反之则1
    {
        cout << "v1为空" << endl;
    }
    else
    {
        cout << "v1不为空" << endl;
        cout << "v1的容量为：" << v1.capacity() << endl;//容量永远大于等于大小
        cout << "v1的大小为：" << v1.size() << endl;    //v1.size返回容器v1里元素的个数
    }
    cout << "-------------------------------------" << endl;
   
    //resize(int num)
    //重新指定v1的长度,如果容器变长，则以默认值0重新填充位置.
    //如果容器变短，则末尾超出容器长度的元素会被删除.
    v1.resize(13);
    cout << "v1的容量为：" << v1.capacity() << endl;
    cout << "v1的大小为：" << v1.size() << endl; 
    for(auto it = v1.begin();it != v1.end();it++)
    {
        std::cout << *it << " ";
    }
    cout << " " << endl;
    cout << "-------------------------------------" << endl;
   

    //resize(int num,elem)
    //重新指定v1的长度,如果容器变长，则以elem重新填充位置.
    //如果容器变短，则末尾超出容器长度的元素会被删除.
    v1.resize(17,4);//此时容器长度从13变化到17,多的部分用4来填补.
    cout << "v1的容量为：" << v1.capacity() << endl;
    cout << "v1的大小为：" << v1.size() << endl; 
    for(auto it = v1.begin();it != v1.end();it++)
    {
        std::cout << *it << " ";
    }
    cout << " " << endl;
    //补充



    return 0;
} 