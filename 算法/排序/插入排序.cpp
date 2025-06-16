#include <iostream>
using namespace std;

int arr[5] = {4, 2, 7, 1, 3};

void printArr(int arr[])
{
    for (int i = 0; i < 5; ++i)
    {
        cout << arr[i] << " ";
    }
}

void SectionSort()
{

    for (int i = 0; i < 5; ++i)
    {
        int arr_min_index = i;
        for (int j = i + 1; j < 5; ++j)
        {
            if (arr[j] < arr[arr_min_index])
            {
                arr_min_index = j;
            }
        }
        if (arr_min_index != i)
        {
            int temp = arr[i];
            arr[i] = arr[arr_min_index];
            arr[arr_min_index] = temp;
        }
    }

    printArr(arr);
}

void InsertSort()
{
    for (int i = 1; i < 5; ++i)
    {
        int index = i;
        int temp_value = arr[i];

        while (index > 0 && arr[index - 1] > temp_value)
        {
            arr[index] = arr[index - 1];
            --index;
        }
        arr[index] = temp_value;
    }

    printArr(arr);
}

void BubbleSort()
{
    for (int i = 0; i < 5 - 1; ++i)
    {                         // 外层循环控制轮次（n-1轮）
        bool swapped = false; // 优化：标记是否发生交换
        for (int j = 0; j < 5 - 1 - i; ++j)
        { // 内层循环比较相邻元素
            if (arr[j] > arr[j + 1])
            {                      // 如果前一个元素更大
                int temp = arr[j]; // 交换相邻元素
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true; // 标记发生交换
            }
        }
        if (!swapped)
            break; // 如果一轮未发生交换，说明已有序，提前终止
    }

    printArr(arr);
}

int main()
{
    // SectionSort();
    //  InsertSort();
    BubbleSort();

    return 0;
}