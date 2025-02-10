#include <iostream>

using namespace std;

void method1()
{
    int num1;
    cin >> num1;

    if (num1 % 2 == 0 && num1 <= 12 && num1 > 4) // 小A喜欢的条件
    {
        cout << 1 << " ";
    }
    else
    {
        cout << 0 << " ";
    }

    if (num1 % 2 == 0) // Uim喜欢的条件
    {
        cout << 1 << " ";
    }
    else if (num1 <= 12 && num1 > 4)
    {
        cout << 1 << " ";
    }
    else
    {
        cout << 0 << " ";
    }

    if (num1 % 2 == 0 && (num1 <= 4 || num1 > 12) || num1 > 4 && num1 <= 12 && num1 % 2 == 1) // 小B喜欢的条件
    {
        cout << 1 << " ";
    }
    else
    {
        cout << 0 << " ";
    }

    if (num1 % 2 == 0 || num1 <= 12 && num1 > 4) // 正妹喜欢的条件
    {
        cout << 0 << " ";
    }
    else
    {
        cout << 1 << " ";
    }
}

void method2()
{
    // 民间答案
    int n;
    bool a = 0, b = 0, c = 0, d = 0;
    cin >> n;
    if (n % 2 == 0 && (n > 4 && n <= 12))
        a = 1; // 必须要符合两个条件
    if (n % 2 == 0 || (n > 4 && n <= 12))
        b = 1; // 至少要符合一个条件
    if (n % 2 == 0 ^ (n > 4 && n <= 12))
        c = 1; // 必须要只符合一个条件
    if (n % 2 != 0 && (n <= 4 || n > 12))
        d = 1;                                             // 必须要两个条件全都不符合
    cout << a << " " << b << " " << c << " " << d << endl; // 输出
}

void method3()
{
    // 官方答案
    int x; // 输入一个数
    bool p1, p2;
    p1 = x % 2 == 0;
    p2 = x > 4 && x <= 12;

    cout << (p1 && p2) << " ";
    cout << (p1 || p2) << " ";
    cout << (p1 ^ p2) << " "; // 两个性质刚好成立一个
    cout << (!p1 && !p2);
}

int main()
{
    method1();
    // method2();

    return 0;
}