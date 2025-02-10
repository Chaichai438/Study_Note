#include <iostream>
using namespace std;

void method1()
{
    int year;
    cin >> year;

    int ge, shi;
    ge = year % 10;
    shi = year / 10 % 10;

    int year_normal = shi * 10 + ge;

    if (year_normal != 0)
    {
        if (year_normal % 4 == 0)
        {
            cout << 1;
        }
        else
        {
            cout << 0;
        }
    }
    else
    {
        if (year % 400 == 0)
        {
            cout << 1;
        }
        else
        {
            cout << 0;
        }
    }
}

void method2()
{
    int n;
    cin >> n;
    cout << ((n % 4 == 0 && n % 100 != 0) || (n % 400 == 0)) ? 1 : 0;
}

int main()
{
    method1();
    return 0;
}