#include <iostream>

using namespace std;

void method1()
{
    int x;
    cin >> x;

    switch (x)
    {
    case 0:
    {
        cout << "Today, I ate " << x << " apple.";
        break;
    }
    case 1:
    {
        cout << "Today, I ate " << x << " apple.";
        break;
    }
    default:
    {
        cout << "Today, I ate " << x << " apples.";
    }
    }
}

int main()
{
    method1();

    return 0;
}