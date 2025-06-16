#include <iostream>
#define DAY 364

using namespace std;

void _K(int raised_money, int &K, int &X)
{
    while ((raised_money - 21 * 52 * K) % DAY != 0)
    {
        K++;
    }

    X = (raised_money - 21 * 52 * K) / 364;

    if (X > 100)
    {
        K++;
        _K(raised_money, K, X);
    }
}

int main()
{
    int raised_money;
    cin >> raised_money;

    int X; // week : 7X+21K year : 364X+21*52K
    int K = 1;

    _K(raised_money, K, X);

    cout << X << endl;
    cout << K;
}