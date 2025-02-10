#include <iostream>
using namespace std;

void method1()
{
    int quantity;
    cin >> quantity;

    int time_local, time_Luogu;

    if (5 * quantity < 3 * quantity + 11)
    {
        cout << "Local";
    }
    else
    {
        cout << "Luogu";
    }
}

int main()
{

    method1();
    return 0;
}
