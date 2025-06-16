#include <iostream>
#define MAX 100

using namespace std;

int a[MAX] = {0}, b[MAX] = {0};

void multipal(int x)
{
    int g = 0;
    for (int i = MAX - 1; i >= 0; --i)
    {
        a[i] = a[i] * x + g;
        g = a[i] / 10;
        a[i] %= 10;
    }
}

void get_sum()
{
    int g = 0;
    for (int i = MAX - 1; i >= 0; --i)
    {
        b[i] = b[i] + a[i] + g;
        g = b[i] / 10;
        b[i] %= 10;
    }
}

int main()
{
    int n;
    cin >> n;
    a[MAX - 1] = 1;
    b[MAX - 1] = 1;
    for (int i = 2; i <= n; ++i)
    {
        multipal(i);
        get_sum();
    }

    int w;
    for (int i = 0; i <= MAX - 1; ++i)
    {
        if (b[i] != 0)
        {
            w = i;
            break;
        }
    }

    for (int i = w; i <= MAX - 1; ++i)
        cout << b[i];
}