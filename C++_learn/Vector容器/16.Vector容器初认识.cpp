/*
特性：
-动态大小：vector 的大小可以根据需要自动增长和缩小。
-连续存储：vector 中的元素在内存中是连续存储的，这使得访问元素非常快速。
-可迭代：vector 可以被迭代，你可以使用循环（如 for 循环）来访问它的元素。
-元素类型：vector 可以存储任何类型的元素，包括内置类型、对象、指针等。
* 我简单的理解为动态数组
*/

#include<iostream>
//想使用Vector首先需要包含头文件
#include<vector>

int main()
{
    // 创建一个存储整数的空 vector
    std::vector<int> myVector; 

    myVector = {1,2,3,4,5,6,7,8};  //初始化Vector
    for (int i = 0;i < 8;i++)      //遍历数组
    {
        std::cout << myVector[i] << " ";
    }
    std::cout << std::endl;

    //添加 9 到 vector 的末尾
    myVector.push_back(9);

    for (int i = 0;i < 9;i++)      //遍历数组
    {
        std::cout << myVector[i] << " ";
    }
    std::cout << std::endl;

    //访问元素,以下两种方法均可以,灵活使用
    int num1 = myVector[3];
    int num2 = myVector.at(4);

    std::cout << num1 << " " << num2 << std::endl;

    //获取元素个数
    int size = myVector.size();
    std::cout << size << std::endl;

    //使用迭代器遍历 vector 中的元素
    for (auto it = myVector.begin(); it != myVector.end(); it++)
    {
         std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    //或者
    for (int element : myVector) 
    {
    std::cout << element << " ";
    } 
    std::cout << std::endl;
    
    //删除元素
    myVector.erase(myVector.begin()+4);// 删除第5个元素
    for (auto it = myVector.begin();it != myVector.end();it++)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;




    return 0;
}


