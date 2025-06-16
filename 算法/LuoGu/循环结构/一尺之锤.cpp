#include <iostream>
#include <cmath>

using namespace std;

void method1()
{
    int a, count = 1;
    cin >> a;

    while (1)
    {
        if (a == 1)
            break;
        a = ceil(a / 2);
        count++;
    }
    cout << count;
}

int main()
{
    method1();
    return 0;
}