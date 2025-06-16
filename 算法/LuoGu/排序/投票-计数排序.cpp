#include <iostream>
using namespace std;

void method1()
{
    int n, m, arr[1010] = {0}, temp;
    cin >> n >> m;

    for (int i = 0; i < m; ++i)
    {
        cin >> temp;
        arr[temp]++;
    }

    for (int i = 0; i <= n; ++i)

        for (int j = 0; j < arr[i]; ++j)
            cout << i << " ";
    cout << endl;
}

int main()
{
    method1();
    return 0;
}
