#include <iostream>
using namespace std;

void Rectangle(int line)
{
    for (int i = 1; i <= line * line; ++i)
    {
        if (i < 10)
            cout << "0" << i;
        else
            cout << i;

        if (i % line == 0)
        {
            cout << endl;
        }
    }
}

void Triangle(int line)
{
    int cnt = 1;
    for (int i = 1; i <= line; i++)
    {
        for (int j = 1; j <= line - i; j++)
        {
            cout << "  ";
        }

        while (cnt <= i * (i + 1) / 2)
        {
            if (cnt < 10)
            {
                cout << "0" << cnt;
            }
            else
            {
                cout << cnt;
            }
            cnt++;
        }
        cout << endl;
    }
}
int main()
{
    int n;
    cin >> n;

    Rectangle(n);

    cout << endl;

    Triangle(n);
    return 0;
}