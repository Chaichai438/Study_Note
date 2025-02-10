/*
涉及知识点:
1、取模(就是算余数)。
   在编程和数学中，取模运算通常用符号 % 或 mod 表示。
   为什么需要取模?
   (1)限制范围：取模运算可以将一个数限制在一个特定的范围内。例如，对于 a mod b，结果总是介于 0 和 b−1 之间。
   (2)循环结构：在计算机科学中，取模运算常用于处理循环结构，例如数组索引的循环。
   (3)大数处理：在处理大数时，取模运算可以防止数值溢出。例如，在计算大数的和或乘积时，可以对一个较大
   的模数（如 10E9 + 7）取模，从而避免数值过大导致的计算错误。
2、因数
*/

#include <iostream>

using namespace std;

const int MOD = 1e9 + 7;

int main()
{
    long long n;
    cin >> n; // 输入正整数 n

    long long result = 0;

    // 遍历所有可能的因数 d
    for (long long d = 1; d <= n; d++)
    {
        // d 是 n/d 个数的因数
        long long count = n / d;             // d 是 count 个数的因数
        result = (result + d * count) % MOD; // 累加 d 的贡献
    }

    cout << result << endl; // 输出结果
    return 0;
}