#include <iostream>
using namespace std;

void method1()
{
    int x, n;
    cin >> x >> n;

    int week = n / 7;
    int day_left = n % 7;

    int week_km = 250 * week * 5;

    int remain_km;
    if (x + day_left - 1 <= 5)
    {
        remain_km = day_left * 250;
    }
    else if (x + day_left - 1 == 6)
    {
        if (day_left - 1 >= 0)
        {
            remain_km = (day_left - 1) * 250;
        }
        else
        {
            remain_km = 0;
        }
    }
    else if (x + day_left - 1 >= 7)
    {
        if (x == 7)
        {
            if (day_left - 1 >= 0)
            {
                remain_km = (day_left - 1) * 250;
            }
            else
            {
                remain_km = 0;
            }
        }

        else
        {
            if (day_left - 2 >= 0)
            {
                remain_km = (day_left - 2) * 250;
            }
            else
            {
                remain_km = 0;
            }
        }
    }
    cout << week_km + remain_km << endl;
}

int main()
{
    method1();

    return 0;
}