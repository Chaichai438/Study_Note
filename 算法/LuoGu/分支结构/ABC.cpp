#include <iostream>

using namespace std;

void method1()
{
    int num1, num2, num3;
    cin >> num1 >> num2 >> num3;

    if (num1 > num2)
    {
        int temp = num2;
        num2 = num1;
        num1 = temp;
    }
    if (num1 > num3)
    {
        int temp = num3;
        num3 = num1;
        num1 = temp;
    }
    if (num2 > num3)
    {
        int temp = num3;
        num3 = num2;
        num2 = temp;
    }

    string Arr;

    cin >> Arr;

    for (int i = 0; i < 3; ++i)
    {
        if (Arr[i] == 'A')
            cout << num1 << " ";
        else if (Arr[i] == 'B')
            cout << num2 << " ";
        else if (Arr[i] == 'C')
            cout << num3 << " ";
    }
}

int main()
{
    method1();

    return 0;
}