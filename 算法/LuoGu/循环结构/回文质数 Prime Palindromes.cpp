#include <iostream>
#include <cmath>

using namespace std;

int is_prime(int num)
{
    if (num % 2 == 0)
        return 0;

    else
    {
        for (int i = 2; i <= sqrt(num); i++)
        {
            if (num % i == 0)
                return 0;
        }
        return 1;
    }
}

int is_huiwen2(int num)
{
    int reversed = 0;
    int original = num;

    while (num != 0)
    {
        reversed = reversed * 10 + num % 10;
        num /= 10;
    }

    if (reversed == original) // 判断是否回文
        return 1;
    else
        return 0;
}
int main()
{
    int num1, num2;
    cin >> num1 >> num2;

    for (int i = num1; i <= num2; i++)
    {
        if (i == 9989900)
            break;

        if (is_prime(i) && is_huiwen2(i))
        {
            cout << i << endl;
        }
    }

    return 0;
}