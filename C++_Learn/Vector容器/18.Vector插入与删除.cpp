#include<iostream>
#include<vector>
using namespace std;

//这里做一个遍历Vector的函数，方便我们进行多次遍历
void PrintVector(vector<int>&v1)
{
    for(vector<int>::iterator it = v1.begin();it != v1.end();it++)
    {
        cout << *it << endl;
    }
    cout << " " << endl;
}

int main()
 
    vector<int>v1;

    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(40);
    v1.push_back(50);
    PrintVector(v1);

    cout << "----------------------" << endl;

    //删去v1结尾的元素
    v1.pop_back();
    PrintVector(v1);           //此时50应该被删去

    cout << "----------------------" << endl;

    //插入元素 第一个参数是迭代器
    v1.insert(v1.begin(),100);
    PrintVector(v1);           //此时在开头会多一个100

    cout << "----------------------" << endl;

    //向开头插入2个1000
    v1.insert(v1.begin(),2,1000);
    PrintVector(v1);           //此时在开头会多两个1000

    cout << "----------------------" << endl;

    //向第二个数插入3个50
    v1.insert(v1.begin() + 2,3,50);
    PrintVector(v1);           //此时在第二个数后面会多出三个50

    cout << "----------------------" << endl;

    //删除    第一个参数也是迭代器
    v1.erase(v1.begin());
    PrintVector(v1);           //此时在开头会删去一个1000

    cout << "----------------------" << endl;

    v1.erase(v1.begin(),v1.end());//相当于清空元素 == v1.clear()
    PrintVector(v1);           //删去容器中所有的数，里面是空的，无输出

    cout << "----------------------" << endl;


 



}
