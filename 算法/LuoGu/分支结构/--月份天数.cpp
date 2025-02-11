#include <iostream>
using namespace std;

void method1()
{
    int year, month;
    cin >> year >> month;

    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
    {
        switch (month)
        {
        case 1:
            cout << 31 << endl;
            break;
        case 2:
            cout << 29 << endl;
            break;
        case 3:
            cout << 31 << endl;
            break;
        case 4:
            cout << 30 << endl;
            break;
        case 5:
            cout << 31 << endl;
            break;
        case 6:
            cout << 30 << endl;
            break;
        case 7:
            cout << 31 << endl;
            break;
        case 8:
            cout << 31 << endl;
            break;
        case 9:
            cout << 30 << endl;
            break;
        case 10:
            cout << 31 << endl;
            break;
        case 11:
            cout << 30 << endl;
            break;
        case 12:
            cout << 31 << endl;
            break;
        }
    }
    else
    {
        switch (month)
        {
        case 1:
            cout << 31 << endl;
            break;
        case 2:
            cout << 28 << endl;
            break;
        case 3:
            cout << 31 << endl;
            break;
        case 4:
            cout << 30 << endl;
            break;
        case 5:
            cout << 31 << endl;
            break;
        case 6:
            cout << 30 << endl;
            break;
        case 7:
            cout << 31 << endl;
            break;
        case 8:
            cout << 31 << endl;
            break;
        case 9:
            cout << 30 << endl;
            break;
        case 10:
            cout << 31 << endl;
            break;
        case 11:
            cout << 30 << endl;
            break;
        case 12:
            cout << 31 << endl;
            break;
        }
    }
}

void method2()
{
    int y, m;
    cin >> y >> m;
    switch (m)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        cout << 31 << endl;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        cout << 30 << endl;
        break;
    case 2:
        if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)
            cout << 29 << endl;
        else
            cout << 28 << endl;
        break;
    }
}

int main()
{
    // method1();

    method2();

    return 0;
}