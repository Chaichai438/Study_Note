#include <cstdio>

void method1()
{
    int electric;
    double electric_fee;
    scanf("%d", &electric);

    if (electric <= 150)
    {
        electric_fee = electric * 0.4463;
    }
    else if (electric >= 151 && electric <= 400)
    {
        electric_fee = 150 * 0.4463 + (electric - 150) * 0.4663;
    }
    else if (electric >= 401)
    {
        electric_fee = 150 * 0.4463 + 250 * 0.4663 + (electric - 400) * 0.5663;
    }

    printf("%.1f", electric_fee);
}

int main()
{
    method1();

    return 0;
}