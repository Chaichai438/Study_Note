#include <iostream>
using namespace std;

void method1(int i, int &count, int &x) // 统计特定数字 x 的出现次数
{
    while (i != 0)
    {
        if (i % 10 == x)
        {
            count++;
        }
        i = i / 10; // 去掉最低位
    }
}

int main()
{
    int n, x;
    cin >> n >> x;

    int count = 0;

    for (int i = 1; i <= n; ++i)
    {
        method1(i, count, x); // 统一处理所有数字
    }

    cout << count;

    return 0;
}