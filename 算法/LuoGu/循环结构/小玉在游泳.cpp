#include <cstdio>

int main()
{
    double s;
    scanf("%lf", &s);

    int step = 1;
    double total_distance = 2.0;
    double once_step_distance = 2.0;

    while (total_distance < s)
    {
        once_step_distance = once_step_distance * 0.98;
        total_distance += once_step_distance;
        step++;
    }

    printf("%d", step);

    return 0;
}