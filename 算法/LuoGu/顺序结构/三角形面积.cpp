#include <cstdio>
#include <cmath>

int main()
{
    double a, b, c;
    scanf("%lf %lf %lf", &a, &b, &c);

    double p;
    p = (a + b + c) / 2.0;
    // printf("%f\n", p);

    double Area;
    Area = sqrt(p * (p - a) * (p - b) * (p - c));

    printf("%.1f", Area);

    return 0;
}