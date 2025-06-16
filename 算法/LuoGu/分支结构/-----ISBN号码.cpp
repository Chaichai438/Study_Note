#include <iostream>
#include <string>
using namespace std;

void method1()
{
    string ISBN;
    cin >> ISBN;

    int sum = 0;
    int num = 1;
    char latest_num = ISBN.back();

    // 遍历前9位数字，计算加权和
    for (int i = 0; i < ISBN.size() - 1; ++i)
    {
        if (ISBN[i] == '-')
        {
            continue; // 跳过‘-’
        }

        sum += (ISBN[i] - '0') * num;
        ++num;
    }

    int mod = sum % 11;

    // 判断校验码是否正确
    if (mod == 10)
    {
        if (latest_num == 'X')
        {
            cout << "Right";
        }
        else
        {
            ISBN.back() = 'X';
            cout << ISBN;
        }
    }
    else
    {
        if (mod + '0' == latest_num)
        {
            cout << "Right";
        }
        else
        {
            ISBN.back() = mod + '0';
            cout << ISBN;
        }
    }
}

int main()
{
    method1();
    return 0;
}