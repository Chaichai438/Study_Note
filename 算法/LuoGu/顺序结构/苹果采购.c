#include <stdio.h>

int main()
{
    long long quantity, students;
    scanf("%lld %lld", &quantity, &students);

    printf("%lld", quantity * students);

    return 0;
}