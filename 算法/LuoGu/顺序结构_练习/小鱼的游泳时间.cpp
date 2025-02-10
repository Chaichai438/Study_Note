#include <cstdio>

void func1()
{
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);

    int min_begin = a * 60 + b;
    int min_end = c * 60 + d;

    int hour = (min_end - min_begin) / 60;
    int min = (min_end - min_begin) % 60;

    printf("%d %d", hour, min);
}

int main()
{

    func1();
    return 0;
}