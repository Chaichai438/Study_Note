#include <cstdio>
#define MAX 1000

int find_max(int arr[], int n)
{
    int max_index = 0;
    for (int i = 1; i < n; ++i)
    {
        if (arr[max_index] < arr[i])
        {
            max_index = i;
        }
    }
    return max_index;
}

int find_min(int arr[], int n)
{
    int min_index = 0;
    for (int i = 1; i < n; ++i)
    {
        if (arr[min_index] > arr[i])
        {
            min_index = i;
        }
    }
    return min_index;
}

int main()
{
    int n;
    scanf("%d", &n);

    int arr[MAX] = {0};
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &arr[i]);
    }

    int max_index = find_max(arr, n);
    int min_index = find_min(arr, n);

    double average = 0.0;

    for (int i = 0; i < n; ++i)
    {
        if (i == max_index)
            continue;

        if (i == min_index)
            continue;

        average += arr[i];
    }

    printf("%.2f", average / (n - 2.0));
}