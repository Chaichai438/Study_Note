#include <iostream>
using namespace std;

int main()
{
    int t = 0;
    int max = 8; // 最大时长

    for (int i = 1; i <= 7; i++)
    {
        int In_school, Outside_school;
        cin >> In_school >> Outside_school;

        if (In_school + Outside_school > max)
        {
            max = In_school + Outside_school;
            t = i;
        }
    }
    cout << t;

    return 0;
}