#include <cstdio>

void method1()
{
    int A, B, C;
    scanf("%d %d %d", &A, &B, &C);

    double result = A * 0.2 + B * 0.3 + C * 0.5;
    printf("%d", (int)result);
}

void method2()
{
    int A, B, C;
    scanf("%d %d %d", &A, &B, &C);
    printf("%d", A * 2 / 10 + B * 3 / 10 + C * 5 / 10); // 不会接触到浮点数
}

int main()
{
    method1();
    return 0;
}