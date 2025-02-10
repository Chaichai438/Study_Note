#include <iostream>
#include <cstdio>
using namespace std;

void method1()
{
    double num1;
    cin >> num1;

    int a, b, c, d, p;
    p = num1 * 10;

    a = p % 10;        // 个位
    b = p / 10 % 10;   // 十位
    c = p / 100 % 10;  // 百位
    d = p / 1000 % 10; // 千位

    cout << a << "." << b << c << d;
}

void method2()
{
    char a, b, c, dot, d;
    cin >> a >> b >> c >> dot >> d;
    cout << d << dot << c << b << a;
}

void method3()
{
    int a, b, c, d;
    scanf("%c%c%c%c", &a, &b, &c, &d);
    printf("%c.%c%c%c", d, c, b, a);
}

int main()
{

    return 0;
}
