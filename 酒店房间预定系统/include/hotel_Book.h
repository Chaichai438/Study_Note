#pragma once // 防止头文件重复编译
#include <iostream>
#include <vector>
using namespace std;

// 设计房间预定类
class hotelBook
{
public:
    // 构造函数
    hotelBook();

    // 菜单功能
    void show_Menu();

    // 退出系统
    void exitSystem();

    // 析构函数
    ~hotelBook();
};