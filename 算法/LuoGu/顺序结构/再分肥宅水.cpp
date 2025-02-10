#include <cstdio>

using namespace std;

int main()
{
    double volume;
    int num_students;
    scanf("%lf %d", &volume, &num_students);

    printf("%.3lf\n", volume / (double)num_students);

    printf("%d", 2 * num_students);

    return 0;
}