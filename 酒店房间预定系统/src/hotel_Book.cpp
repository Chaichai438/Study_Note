#include "../include/hotel_Book.h"
#include "../include/User.h"

// 构造函数
hotelBook::hotelBook() {}

// 菜单功能
void hotelBook::show_Menu()
{
    cout << "*********************************" << endl;
    cout << "*******  欢迎预定本酒店房间  *******" << endl;
    cout << "*******  1.开始房间预定  **********" << endl;
    cout << "*******  2.查看预定信息  **********" << endl;
    cout << "*******  3.查看预定账单  **********" << endl;
    cout << "*******  4.取消房间预定  **********" << endl;
    cout << "*******  0.退出预定系统  **********" << endl;
    cout << "*********************************" << endl;
    cout << endl;
}

// 退出系统
void hotelBook::exitSystem()
{
    cout << "欢迎您的下次使用！！！" << endl;
    exit(0);
}

// 析构函数
hotelBook::~hotelBook() {}
