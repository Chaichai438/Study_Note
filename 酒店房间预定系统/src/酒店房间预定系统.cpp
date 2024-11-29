#include <iostream>
#include <thread>

using namespace std;

#include "../include/hotel_Book.h"
#include "../include/User.h"

int main()
{
    // 创建预定类对象
    hotelBook hb;

    // 创建用户类
    User user;

    // 创建房间类
    Room_Type rt;

    // 初始化数组
    User_Book usb;
    usb.User_size = 0;

    int choice = 0; // 存储用户的输入

    while (true)
    {
        hb.show_Menu();

        cout
            << "请输入您的选择" << endl;

        cin >> choice;

        switch (choice)
        {
        case 1: // 开始预定
            user.addUser(&usb);
            break;

        case 2: // 查看预定信息
            rt.ShowUserInfo(&usb);
            break;

        case 3: // 查看预定账单
            user.checkLists(&usb);
            break;

        case 4: // 取消预定
            user.cancelBook(&usb);
            break;

        case 0: // 退出系统
            hb.exitSystem();
            break;

        default:
            cout << "输入错误，三秒后即将清屏，请重新输入" << endl;
            this_thread::sleep_for(chrono::seconds(3)); // 等待三秒
            system("clear");                            // 清屏
            break;
        }
    }

    return 0;
}
