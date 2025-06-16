#include <iostream>

using namespace std;

void method1()
{
    int apple[10] = {0};
    for (int i = 0; i < 10; ++i)
    {
        cin >> apple[i];
    }

    int taotao;
    cin >> taotao;

    int apple_num = 0;

    for (int i = 0; i < 10; ++i)
    {
        if (taotao + 30 >= apple[i])
        {
            apple_num++;
        }
    }
    cout << apple_num;
}

int main()
{
    method1();

    return 0;
}