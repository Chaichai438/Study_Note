#include <iostream>
using namespace std;

void method1()
{
    int num;
    int num_arr[1000] = {0};
    cin >> num;
    for (int i = 0; i < num; ++i)
    {
        cin >> num_arr[i];
    }

    for (int j = 1; j < num; ++j)
    {
        if (num_arr[0] > num_arr[j])
        {
            int temp = num_arr[j];
            num_arr[j] == num_arr[0];
            num_arr[0] = temp;
        }
    }

    cout << num_arr[0];
}

int main()
{
    method1();
    return 0;
}