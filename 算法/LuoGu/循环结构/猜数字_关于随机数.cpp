#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    int answer, guess;
    srand(time(0));            // 获取种子
    answer = rand() % 100 + 1; // 生成一个1-100的随机数

    cin >> guess;

    while (answer != guess)
    {

        if (guess < answer)
            cout << "Too Small" << endl;
        if (guess > answer)
            cout << "Too Large" << endl;
        cin >> guess;
    }

    cout << "You are right!!" << endl;
    return 0;
}