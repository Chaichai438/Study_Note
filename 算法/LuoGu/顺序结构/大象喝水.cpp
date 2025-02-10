#include <cstdio>
#include <cmath>

const double PI = 3.14;
const long V_need = 20 * 1e3;

void method1()
{
    int H, R;
    scanf("%d %d", &H, &R);

    double vulumn = PI * R * R * H;

    int n = ceil((V_need * 1.0 / vulumn * 1.0));

    printf("%d", n);
}

int main()
{

    method1();
    return 0;
}