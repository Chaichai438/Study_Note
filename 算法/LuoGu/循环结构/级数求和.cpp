#include <iostream>
using namespace std;

int main()
{
    int k;
    cin >> k;

    double sum = 0;
    int n = 1;
    while (sum <= k * 1.0)
    {
        sum = sum + 1.0 / n;
        ++n;
    }

    cout << n-1;

    return 0;
}