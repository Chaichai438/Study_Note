#include <iostream>
using namespace std;

void method1()
{
    int L, load = 0, answer = 0;
    cin >> L; // 负载量

    int prime_num = 0;

    for (int i = 2;; ++i)
    {
        bool is_prime = true; // 状态变量，用于得到是否是质数的结果。每次循环前假设是质数
        for (int j = 2; j * j <= i; ++j)
        {
            if (i % j == 0) // 判断是否是质数,不是就直接跳出当前循环
            {
                is_prime = false;
                break;
            }
        }

        if (!is_prime)
            continue;
        if (i + load > L) // 判断是否超载
            break;
        cout << i << endl;
        answer++;
        load += i;
    }
    cout << answer;
}

int main()
{
    method1();

    return 0;
}