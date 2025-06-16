#include <iostream>

using namespace std;

void method1()
{
    int n, n1, n2, n3, p1, p2, p3;
    cin >> n >> n1 >> p1 >> n2 >> p2 >> n3 >> p3;

    int t1 = !(n % n1) ? n / n1 * p1 : (n / n1 + 1) * p1;
    int t2 = !(n % n2) ? n / n2 * p2 : (n / n2 + 1) * p2;
    int t3 = !(n % n3) ? n / n3 * p3 : (n / n3 + 1) * p3;

    if (t1 > t2)
    {
        int temp = t2;
        t2 = t1;
        t1 = temp;
    }
    if (t1 > t3)
    {
        int temp = t3;
        t3 = t1;
        t1 = temp;
    }
    if (t2 > t3)
    {
        int temp = t3;
        t3 = t2;
        t2 = temp;
    }

    cout << t1;
}

int main()
{

    method1();

    return 0;
}