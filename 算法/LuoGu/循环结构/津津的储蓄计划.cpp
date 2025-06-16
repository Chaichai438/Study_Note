#include <iostream>
#define YEAR 12

using namespace std;

int main()
{
    int budget[YEAR] = {0};
    int save[YEAR] = {0};

    for (int i = 0; i < YEAR; ++i)
    {
        cin >> budget[i];
    }

    int have_money = 0;

    for (int i = 0; i < YEAR; ++i)
    {
        have_money = have_money + 300 - budget[i];

        if (have_money < 0)
        {
            cout << "-" << i + 1;
            return 0;
        }

        while (have_money >= 100)
        {
            have_money -= 100;
            save[i] += 100;
        }
    }

    int sum = 0;
    for (int i = 0; i < YEAR; ++i)
    {
        sum += save[i];
    }

    cout << sum * 1.2 + have_money;
}