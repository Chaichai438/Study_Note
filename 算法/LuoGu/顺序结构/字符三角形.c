#include <stdio.h>

int main()
{
    char x;
    scanf("%c", &x);

    printf("  %c\n", x);
    printf(" %c%c%c\n", x, x, x);
    printf("%c%c%c%c%c", x, x, x, x, x);

    return 0;
}