#include <cstdio>
#include <cmath>

// 存在的问题：
// 1、没有考虑被除数为0和题目隐藏条件

void method1()
{
    int m, t, s;
    scanf("%d %d %d", &m, &t, &s);
    // -----此处思考时间过长-----

    if (t == 0)
    {
        printf("0");
    }
    else
    {
        int eaten_apples = ceil((s * 1.0) / (t * 1.0));

        if (eaten_apples >= m)
        {
            printf("0");
        }
        else
        {
            printf("%d", m - eaten_apples);
        }
    }
}

int main()
{
    method1();
    return 0;
}