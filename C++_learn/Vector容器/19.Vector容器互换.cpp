#include<iostream>
#include<vector>

using namespace std;

void PrintVector(vector<int>&v)
{
    for(vector<int>::iterator it = v.begin();it != v.end();it++)
    {
        cout << *it << " ";
    }
    cout << " " << endl;
}

void vector_test_01()
{
    vector<int>v1;
    for(int i = 0;i < 10;i++)
    {
        v1.push_back(i);
    }
    PrintVector(v1);

    cout << "------------------------" << endl;

    vector<int>v2;
    for(int i = 10;i > 0;i--)
    {
        v2.push_back(i);
    }
    PrintVector(v2);

    cout << "以上是交换前的数据" << endl;
   
    v1.swap(v2);   //将v1与v2元素互换
    PrintVector(v1);
    cout << "----------------" << endl;
    PrintVector(v2);

    cout << "以上是交换后的数据" << endl;


}
//实际用途
//巧用swap可以收缩内存空间
void vector_test_02()
{
    vector<int>v;
    for(int i = 0 ; i < 100000 ; i++)
    {
        v.push_back(i);
    }

    cout << "v的容量:" << v.capacity() << endl;
    cout << "v的大小:" << v.size() << endl;

    v.resize(3);//重新指定大小
    cout << "v的容量:" << v.capacity() << endl;
    cout << "v的大小:" << v.size() << endl;    //此时我们会发现,虽然大小已经为3了，但是容量仍然很大，很浪费，这时候我们就可以用swap函数来实现内存收缩

    //巧用swap收缩内存
    vector<int>(v).swap(v);  //vector<int>(v)匿名对象(无名) ,(v)，代表着他会复制我们已经定义过的v来初始化这个新的Vector容器。匿名对象的特点：当这行代码执行完毕后，编译器会回收匿名对象所占用的内存(相当于黑户被警察抓了辇出去了)
    cout << "v的容量:" << v.capacity() << endl;
    cout << "v的大小:" << v.size() << endl;

    
}


//习惯了C语言的写法，我们也要尝试这种写法，这也是C++特点之一，可以kimi一下这种写法的原因
int main()
{
    vector_test_01();

    vector_test_02();

    return 0;
}
