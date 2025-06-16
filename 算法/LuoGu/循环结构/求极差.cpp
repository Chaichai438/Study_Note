#include <iostream>
#define MAX 100

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

int find_min(int arr[], int n_count)
{
    int min = 0;
    for (int i = 1; i < n_count; ++i)
    {
        if (arr[min] > arr[i])
        {
            min = i;
        }
    }

    return arr[min];
}

int main()
{
    int n_countl;
    cin >> n_countl;

    int arr[MAX];
    for (int i = 0; i < MAX; ++i)
    {
        cin >> arr[i];
    }

    int max = find_max(arr, n_countl);
    int min = find_min(arr, n_countl);

    cout << max - min << endl;

    return 0;
}