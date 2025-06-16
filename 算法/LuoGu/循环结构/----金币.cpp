#include <iostream>
using namespace std;

int main()
{
    int k, total, day;
    cin >> k;

    total = 0;
    day = 0;

    for (int i = 1;; ++i)
    {
        for (int j = 1; j <= i; ++j) // i相加j次
        {
            total = i + total;
            day++;
            if (day == k)
            {
                cout << total << endl;
                return 0;
            }
        }
    }

    return 0;
}