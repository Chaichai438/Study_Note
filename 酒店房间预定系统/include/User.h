#pragma once
#include <iostream>
#include <string>
using namespace std;
#define MAX 4

// 用户信息
struct User_Info
{
    // 房间信息
    int Room_Type;
    //  姓名
    string User_Name;
    // 性别
    int User_Gender;
    // ID
    string User_ID;
    // 电话
    string User_Phone_Number;
    // 年龄
    int User_Age;
};

struct User_Book
{
    // 保存的用户信息的数组
    struct User_Info userinfoArr[MAX];

    // 当前记录用户的个数
    int User_size;
};

// 用户信息类
class User
{
public:
    // 构造函数
    User();

    // 析构函数
    ~User();

    // 开始房间预定
    void addUser(User_Book *ub);

    // 查看预定账单
    void checkLists(User_Book *ub);

    // 取消预定
    void cancelBook(User_Book *ub);
};

// 房间类
class Room_Type
{
public:
    // 构造函数
    Room_Type();

    // 析构函数
    ~Room_Type();

    // 显示预定信息
    void ShowUserInfo(User_Book *ub);
};