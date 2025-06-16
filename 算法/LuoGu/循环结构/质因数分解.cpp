#include <iostream>
using namespace std;

int main()
{
    int n, p;
    cin >> n;

    for (int i = 2; i < n; ++i)
    {
        if (n % i == 0)
        {
            p = n / i;
            break;
        }
    }

    cout << p;

    return 0;
}