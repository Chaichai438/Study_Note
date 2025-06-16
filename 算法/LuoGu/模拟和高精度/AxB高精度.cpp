#include <iostream>
#include <string>
#define MAX 5010

using namespace std;
int a[MAX], b[MAX], c[MAX];
int main()
{
    string A, B;
    cin >> A;
    cin >> B;

    int len_a = A.length(),
        len_b = B.length();

    // 将录入的字符串转化成数字，转化之后为倒序的形式
    for (int i = len_a - 1; i >= 0; --i)
        a[len_a - i] = A[i] - '0';

    for (int i = len_b - 1; i >= 0; --i)
        b[len_b - i] = B[i] - '0';

    // 逐位相乘
    for (int i = 1; i <= len_a; ++i)
    {
        for (int j = 1; j <= len_b; ++j)
            c[i + j - 1] += a[i] * b[j];
    }

    int len = len_a + len_b;

    for (int i = 1; i <= len; ++i)
    {
        c[i + 1] += c[i] / 10; // 进位
        c[i] %= 10;
    }

    while (!c[len]) // 减去过长的数组
        len--;

    for (int i = max(1, len); i >= 1; --i)
        cout << c[i];
}