#include <cstdio>
#include <cmath>

void method1()
{
    int a, b;
    scanf("%d %d", &a, &b);

    int n = floor((a * 10 + b) * 1.0 / 19.0);

    printf("%d", n);
}

int main()
{
    method1();

    return 0;
}