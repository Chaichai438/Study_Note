#include <iostream>

using namespace std;

void method1()
{
    int n, n1, n2, n3, p1, p2, p3;
    cin >> n >> n1 >> p1 >> n2 >> p2 >> n3 >> p3;

    int t1 = !(n % n1) ? n / n1 * p1 : (n / n1 + 1) * p1;
}

int main()
{
    method1();

    return 0;
}