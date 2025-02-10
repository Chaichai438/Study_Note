#include <iostream>
#include <cstdio>
#include <cmath>
// 填上你觉得需要的其他头文件
using namespace std;

const double PI = 3.141593;
int main()
{
    int T;
    cin >> T;
    if (T == 1)
    {
        cout << "I love Luogu!";
    }
    else if (T == 2)
    {
        cout << 2 + 4 << " " << 10 - 2 - 4;
    }
    else if (T == 3)
    {
        cout << 14 / 4 << endl
             << 14 / 4 * 4 << endl
             << 14 - (14 / 4 * 4);
    }
    else if (T == 4)
    {
        printf("%.6g", 500.0 / 3.0);
    }
    else if (T == 5)
    {
        cout << 480 / 32;
    }
    else if (T == 6)
    {
        cout << hypot(6, 9);
    }
    else if (T == 7)
    {
        cout << 100 + 10 << endl
             << 100 + 10 - 20 << endl
             << 0;
    }
    else if (T == 8)
    {
        int r = 5;
        cout << 2 * PI * r << endl
             << PI * r * r << endl
             << 4.0 / 3.0 * PI * r * r * r;
    }
    else if (T == 9)
    {
        cout << (((1 + 1) * 2 + 1) * 2 + 1) * 2;
    }
    else if (T == 10)
    {
        cout << 9;
    }
    else if (T == 11)
    {
        cout << 100.0 / 3.0;
    }
    else if (T == 12)
    {
        printf("%d\n", 'M' - 'A' + 1);
        printf("%c", 'A' + 17);
    }
    else if (T == 13)
    {
        double V = 4.0 / 3.0 * PI * (pow(4, 3) + pow(10, 3));
        printf("%d", (int)cbrt(V));
    }
    else if (T == 14)
    {
        cout << 50;
    }
    return 0;
}