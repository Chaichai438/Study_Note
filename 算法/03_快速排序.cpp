#include <iostream>
using namespace std;

void sort(int Data[], int n)
{
    for (int j = 0; j < n - 1; j++)
    {
        for (int i = j + 1; i < n; i++)
        {
            if (Data[j] > Data[i])
            {
                int temp = Data[j];
                Data[j] = Data[i];
                Data[i] = temp;
            }
        }
    }
}

int main()
{
    int N;
    cin >> N;

    int data[100] = {0};
    for (int i = 0; i < N; i++)
    {
        cin >> data[i];
    }

    sort(data, N);

    for (int i = 0; i < N; i++)
    {
        cout << data[i] << " ";
    }

    return 0;
}