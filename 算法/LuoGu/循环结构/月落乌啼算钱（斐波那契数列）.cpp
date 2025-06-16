#include <cstdio>
#include <cmath>

double Sum(int n)
{
    return (pow((1.0 + sqrt(5)) / 2.0, n) - pow((1 - sqrt(5)) / 2.0, n)) / sqrt(5);
}

int main()
{
    int n;
    double sum;

    scanf("%d", &n);

    printf("%.2f", Sum(n));

    return 0;
}
