#include <iostream>
using namespace std;

// 递归
void method1(int &a, int &c)
{
    for (int i = 2; i <= a; i++)
    {
        if (a % i == 0 && c % i == 0)
        {
            a = a / i;
            c = c / i;
            return method1(a, c);
        }
    }
}

int main()
{
    int a, b, c;
    cin >> a >> b >> c;

    if (a > b)
    {
        int temp1 = a;
        a = b;
        b = temp1;
    }
    if (a > c)
    {
        int temp3 = a;
        a = c;
        c = temp3;
    }
    if (b > c)
    {
        int temp2 = b;
        b = c;
        c = temp2;
    }

    // 约分
    method1(a, c);

    cout << a << "/" << c;

    return 0;
}