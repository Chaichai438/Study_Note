#include <iostream>
#include <algorithm>
#define MAX 1000

using namespace std;

int find_max(int arr[], int n_count)
{
    int max = 0;
    for (int i = 1; i < n_count; ++i)
    {
        if (arr[max] < arr[i])
        {
            max = i;
        }
    }

    return arr[max];
}

int main()
{
    int n;
    cin >> n;

    int arr[MAX];
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    int count[MAX] = {0};
    int j = 0;
    for (int i = 1; i < n; ++i)
    {
        if (arr[i] == arr[i - 1] + 1)
        {
            count[j]++;
        }
        else
        {
            j++;
        }
    }

    cout << find_max(count, MAX) + 1;

    return 0;
}