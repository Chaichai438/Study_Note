#include <iostream>

void method1()
{
    int m;
    double h;
    std::cin >> m;
    std::cin >> h;

    m = m * 1.0;
    h = h * 1.0;

    if (m / h / h < 18.5)
    {
        std::cout << "Underweight";
    }
    else if (m / h / h >= 18.5 && m / h / h < 24)
    {
        std::cout << "Normal";
    }
    else
    {
        std::cout << m / h / h << std::endl
                  << "Overweight";
    }
}

int main()
{
    method1();
    return 0;
}