#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;

    int reserved = 0;
    int original = N;
    if (N < 0)
    {
        N *= -1;
        while (N > 0)
        {
            reserved = reserved * 10 + N % 10;
            N /= 10;
        }

        reserved *= -1;
    }
    else
    {
        while (N > 0)
        {
            reserved = reserved * 10 + N % 10;
            N /= 10;
        }
    }

    cout << reserved;
}