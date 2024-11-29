#include "../include/User.h"
#include <limits>
#include <string>

using namespace std;

// 构造函数
User::User()
{
}

Room_Type::Room_Type()
{
}

// 构造函数
User::~User() {}
Room_Type::~Room_Type() {}

// 预定房间
void User::addUser(User_Book *ub)
{
    // 判断预定信息是否已满
    if (ub->User_size == MAX)
    {
        cout << "本酒店已经没有多余的房间了" << endl;
        return;
    }
    else
    {
        // 预定用户信息

        // 预定类型房间
        int type;
        cout << "请输入你想预定的房间： " << endl;
        cout << "1 -- 标准干净间" << endl;
        cout << "2 -- 双人享受间" << endl;
        cout << "3 -- 三人套房间" << endl;
        cout << "4 -- 四人豪华间" << endl;

        while (true)
        {
            cin >> type;
            if (type == 1 || type == 2 || type == 3 || type == 4)
            {
                ub->userinfoArr[ub->User_size].Room_Type = type;
                break;
            }
            cout << "输入有误，请重新输入" << endl;
        }

        // 姓名
        string name;
        cout << "请输入姓名： " << endl;
        cin >> name;
        ub->userinfoArr[ub->User_size].User_Name = name;

        // 性别
        int gender = 0;
        cout << "请输入性别： " << endl;
        cout << "1 -- 男" << endl;
        cout << "2 -- 女" << endl;
        cout << "3 -- 沃尔玛购物袋" << endl;

        while (true)
        {
            cin >> gender;
            if (gender == 1 || gender == 2 || gender == 3)
            {
                ub->userinfoArr[ub->User_size].User_Gender = gender;
                break;
            }
            cout << "输入有误，请重新输入" << endl;
        }

        // 年龄
        int age;
        cout << "请输入年龄： " << endl;

        ub->userinfoArr[ub->User_size].User_Age = age;
        while (true)
        {
            cin >> age;
            if (age > 0 && age <= 120)
            {
                ub->userinfoArr[ub->User_size].User_Age = age;
                break;
            }
            cout << "输入有误，请重新输入" << endl;
        }

        // 电话
        string phone_number;
        cout << "请输入电话： " << endl;
        cin >> phone_number;
        ub->userinfoArr[ub->User_size].User_Phone_Number = phone_number;

        // ID
        string id;
        cout << "请输入ID： " << endl;
        cin >> id;
        ub->userinfoArr[ub->User_size].User_ID = id;

        // 更新预定人数
        ub->User_size++;

        cout << "预定成功" << endl;

        std::cout << "按下任意建继续" << std::endl;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 忽略之前的换行符
        std::cin.get();                                                     // 等待用户按键
        system("clear");
    }
}

// 显示预定信息
void Room_Type::ShowUserInfo(User_Book *ub)
{
    if (ub->User_size == 0)
    {
        cout << "当前房间充足" << endl;
    }
    else
    {
        for (int i = 0; i < ub->User_size; i++)
        {
            cout << "姓名：  " << ub->userinfoArr[i].User_Name << "\t";

            switch (ub->userinfoArr[i].Room_Type)
            {
            case 1:
                std::cout << "房间类型：标准干净间\t";
                break;
            case 2:
                std::cout << "房间类型：双人享受间\t";
                break;
            case 3:
                std::cout << "房间类型：三人套房间\t";
                break;
            case 4:
                std::cout << "房间类型：四人豪华间\t";
                break;
            }

            cout << "电话：" << ub->userinfoArr[i].User_Phone_Number << endl;
        }
    }
    std::cout << "按下任意建继续" << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 忽略之前的换行符
    std::cin.get();                                                     // 等待用户按键
    system("clear");
}

// 查看预定账单
void User::checkLists(User_Book *ub)
{
    if (ub->User_size == 0)
    {
        cout << "目前没有预定账单" << endl;
        std::cout << "按下任意建继续" << std::endl;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 忽略之前的换行符
        std::cin.get();                                                     // 等待用户按键
    }
    else
    {
        string id;
        string name;
        cout << "请输入姓名： " << endl;
        cin >> name;
        cout << "请输入ID： " << endl;
        cin >> id;

        for (int i = 0; i < ub->User_size; i++)
        {
            if (id != ub->userinfoArr[i].User_ID && name != ub->userinfoArr[i].User_Name)
            {
                cout << "没有您的预定账单" << endl;
            }

            else
            {
                cout << "尊敬的 " << ub->userinfoArr[i].User_Name << " 顾客" << endl;

                cout << "您的账单如下" << endl;

                cout << "-----------------------------------------" << endl;

                cout << "姓名：  " << ub->userinfoArr[i].User_Name << "\t";

                switch (ub->userinfoArr[i].Room_Type)
                {
                case 1:
                    std::cout << "房间类型：标准干净间\t" << endl;

                    break;
                case 2:
                    std::cout << "房间类型：双人享受间\t" << endl;
                    break;
                case 3:
                    std::cout << "房间类型：三人套房间\t" << endl;
                    break;
                case 4:
                    std::cout << "房间类型：四人豪华间\t" << endl;
                    break;
                }
                cout << "-----------------------------------------" << endl;
                switch (ub->userinfoArr[i].User_Gender)
                {
                case 1:
                    cout << "性别：男\t";
                    break;
                case 2:
                    cout << "性别：女\t";
                    break;
                case 3:
                    cout << "性别：沃尔玛购物袋\t";
                    break;
                }

                cout << "年龄： " << ub->userinfoArr[i].User_Age << endl;
                cout << "-----------------------------------------" << endl;
                cout << "电话： " << ub->userinfoArr[i].User_Phone_Number << "\t";

                cout << "ID： " << ub->userinfoArr[i].User_ID << endl;
                cout << "-----------------------------------------" << endl;

                std::cout << "按下任意建继续" << std::endl;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 忽略之前的换行符
                std::cin.get();                                                     // 等待用户按键
                system("clear");
            }
        }
    }
}

// 取消预定
void User::cancelBook(User_Book *ub)
{
    if (ub->User_size == 0)
    {
        cout << "目前没有预定信息" << endl;
    }

    else
    {
        for (int i = 0; i < ub->User_size; i++)
        {
            string name;
            string id;
            cout << "请输入您的姓名： " << endl;
            cin >> name;
            cout << "请输入您的ID: " << endl;
            cin >> id;

            if (id != ub->userinfoArr[i].User_ID && name != ub->userinfoArr[i].User_Name)
            {
                cout << "输入错误，请重新输入" << endl;
            }

            else
            {
                cout << "尊敬的 " << ub->userinfoArr[i].User_Name << " 顾客" << endl;

                cout << "您的账单如下" << endl;

                cout << "-----------------------------------------" << endl;

                cout << "姓名：  " << ub->userinfoArr[i].User_Name << "\t";

                switch (ub->userinfoArr[i].Room_Type)
                {
                case 1:
                    std::cout << "房间类型：标准干净间\t" << endl;

                    break;
                case 2:
                    std::cout << "房间类型：双人享受间\t" << endl;
                    break;
                case 3:
                    std::cout << "房间类型：三人套房间\t" << endl;
                    break;
                case 4:
                    std::cout << "房间类型：四人豪华间\t" << endl;
                    break;
                }
                cout << "-----------------------------------------" << endl;
                switch (ub->userinfoArr[i].User_Gender)
                {
                case 1:
                    cout << "性别：男\t";
                    break;
                case 2:
                    cout << "性别：女\t";
                    break;
                case 3:
                    cout << "性别：沃尔玛购物袋\t";
                    break;
                }

                cout << "年龄： " << ub->userinfoArr[i].User_Age << endl;
                cout << "-----------------------------------------" << endl;
                cout << "电话： " << ub->userinfoArr[i].User_Phone_Number << "\t";

                cout << "ID： " << ub->userinfoArr[i].User_ID << endl;
                cout << "-----------------------------------------" << endl;

                int choice = 0;
                cout << "您确定要取消预定吗？" << endl;
                cout << "1--Yes" << endl;
                cout << "2--NO" << endl;
                cin >> choice;

                int condition = 0;

                if (choice == 1)
                {
                    cout << "正在为您取消预定房间..." << endl;

                    for (int i = 0; i < ub->User_size; i++)
                    {
                        if (ub->userinfoArr[i].User_Name == name && ub->userinfoArr[i].User_ID == id)
                        {
                            condition = i;
                        }
                    }

                    for (int i = condition; i < ub->User_size; i++)
                    {
                        // 数据迁移
                        ub->userinfoArr[i] = ub->userinfoArr[i + 1];
                    }
                    ub->User_size--; // 更新用户数量
                    cout << "取消预定成功" << endl;

                    std::cout << "按下任意建继续" << std::endl;
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 忽略之前的换行符
                    std::cin.get();                                                     // 等待用户按键
                    system("clear");
                }

                else
                {
                    cout << "您拒绝了取消预定" << endl;
                    std::cout << "按下任意建继续" << std::endl;
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 忽略之前的换行符
                    std::cin.get();                                                     // 等待用户按键
                    system("clear");
                    break;
                }
            }
        }
    }
}
