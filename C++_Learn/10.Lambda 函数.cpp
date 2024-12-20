#include <iostream>
using namespace std;

int main()
{
    // Lambda 函数是一种便捷定义函数的方式,
    // 他的优点在于不用像传统定义函数那样在main主题外再去声明
    // 简洁，灵活
    int a = 10;
    int b = 20;

    // auto 用来声明lambda函数，可以上kimi搜一搜auto的其他作用
    auto lambda = [a, &b](int x) -> int
    { return x + a + b; };

    int result = lambda(20);
    std::cout << "Result: " << result << std::endl; // 输出 35

    return 0;
}
