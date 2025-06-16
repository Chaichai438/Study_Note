#include <iostream>
using namespace std;

void method1()
{
    int n;
    cin >> n;

    int j = 1;
    int m = n;
    for (int i = 1; i <= (n + 1) * n / 2; ++i)
    {

        if (i < 10)
            cout << 0 << i;
        else
            cout << i;

        j++;

        if (j > m)
        {
            cout << endl;
            j = 1;
            --m;
        }
    }
}

void method2()
{
    int cnt = 0, n;
    cin >> n;

    for (int i = 1; i <= n; ++i) // 外循环循环n次，在数字三角形中对应着有n行
    {
        for (int j = 1; j <= n - i + 1; ++j) // 内循环循环n-i+1次,对应着每行几个数
        {
            printf("%02d", ++cnt);
        }
        cout << endl;
    }
}

int main()
{
    method2();
    return 0;
}