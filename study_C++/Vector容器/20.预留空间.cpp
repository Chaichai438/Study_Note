#include<iostream>
#include<vector>

using namespace std;

void test01()
{
    vector<int>v;
    
    v.reserve(100000);    //利用reserve预留空间(在第一次学习这个时你需要先把这行代码注释掉来看看没有预留时的效果是怎么样的)
                          //思考一下reserve的好处？
    int num = 0;    //统计重新分配新空间的次数,这个需要你自主去了解Vector的动态空间的机制(这样你才能看懂如下的代码含义！！！！！)
    int* p = NULL;
    for (int i = 0; i < 1000000; i++)
    {
        v.push_back(i);
        if(p != &v[0])
        {
            p = &v[0];
            num++;
        }
    }
    cout << "num = " << num << endl;
    

   
    
}


int main()
{
    test01();

    return 0;
}