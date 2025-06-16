#include <cstdio>
#define N 1000
#include <vector>

void metho1()
{
    std::vector<int> A, B;
    int n, k;
    scanf("%d %d", &n, &k);
    double avrg_A, avrg_B;

    for (int i = 1; i <= n; ++i)
    {
        if (i % k == 0)
        {
            A.push_back(i);
        }
        else
        {
            B.push_back(i);
        }
    }

    int sum1 = 0, sum2 = 0;

    for (int n : A)
    {
        sum1 += n;
    }
    for (int n : B)
    {
        sum2 += n;
    }
    avrg_A = sum1 * 1.0 / A.size();
    avrg_B = sum2 * 1.0 / B.size();

    printf("%.1f %.1f", avrg_A, avrg_B);
}

int main()
{
    metho1();
    return 0;
}