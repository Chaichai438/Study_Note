#include <iostream>
using namespace std;

void method1()
{
    int n, S = 0;
    cin >> n;

    for (int i = 1; i <= n; ++i)
        S += i;
    cout << S;
}

void method2()
{
    int s = 0, i = 0, n;
    cin >> n;
    while (n--)
        s += ++i;
    cout << s;
}

int main()
{
    method1();
    return 0;
}