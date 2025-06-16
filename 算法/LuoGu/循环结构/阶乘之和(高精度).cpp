#include <iostream>
using namespace std;

int n, a[101] = {0}, s[101] = {0};

void get_sum(int x)
{
    int g = 0;
    for (int i = 100; i >= 0; --i)
    {
        a[i] = a[i] * x + g;
        g = a[i] / 10;
        a[i] = a[i] % 10;
    }
}

void qh()
{
    int g = 0;
    for (int i = 100; i >= 0; i--)
    {
        s[i] = s[i] + a[i] + g;
        g = s[i] / 10;
        s[i] = s[i] % 10;
    }
}

void sc()
{
    int w;
    for (int i = 0; i <= 100; i++)
    {
        if (s[i] != 0)
        {
            w = i;
            break;
        }
    }
    for (int i = w; i <= 100; i++)
        printf("%d", s[i]);
}

int main()
{
    cin >> n;
    s[100] = a[100] = 1;
    for (int i = 2; i <= n; i++)
    {
        get_sum(i);
        qh();
    }
    sc();
    return 0;
}