#include <iostream>

using namespace std;

void method1()
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

    cout << a << " " << b << " " << c;
}

int main()
{
    method1();
    return 0;
}