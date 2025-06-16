#include <iostream>
using namespace std;

long long method1(int n)
{
    long long S = 1;
    for (int i = 1; i <= n; ++i)
    {
        S *= i;
    }

    return S;
}
void method1()
{
    long long S = 0;
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        S += method1(i);
    }

    cout << S;
}

void method2()
{
    long long n, ans = 0;
    cin >> n;

    long long factor = 1;

    for (int i = 1; i <= n; ++i) // 循环n次
    {

        factor *= i;
        // for (int j = 1; j <= i; ++j) // 循环i次
        // factor = factor * j;     每次需要重新计算阶乘，时间复杂度为o(n^2)
        ans += factor;
    }

    cout << ans;
}

int main()
{
    method2();
    return 0;
}