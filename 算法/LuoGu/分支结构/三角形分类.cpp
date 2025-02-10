#include <iostream>
#include <cmath>

using namespace std;

void method1()
{
    int a, b, c;
    cin >> a >> b >> c;
    if (a > b)
    {
        int temp = b;
        b = a;
        a = temp;
    }
    if (a > c)
    {
        int temp = c;
        c = a;
        a = temp;
    }
    if (b > c)
    {
        int temp = b;
        b = c;
        c = temp;
    }

    if (a + b > c)
    {
        if (a * a + b * b > c * c)
        {
            cout << "Acute triangle" << endl;
        }
        else if (a * a + b * b == c * c)
        {
            cout << "Right triangle" << endl;
        }
        else if (a * a + b * b < c * c)
        {
            cout << "Obtuse triangle" << endl;
        }

        if (a == b || a == c || b == c)
        {
            cout << "Isosceles triangle" << endl;
        }

        if (a == b && b == c && a == c)
        {
            cout << "Equilateral triangle" << endl;
        }
    }
    else
    {
        cout << "Not triangle" << endl;
    }
}

int main()
{
    method1();

    return 0;
}