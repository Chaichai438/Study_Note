#include <cstdio>
#include <cmath>
using namespace std;

void func1()
{
    int s; // 距离
    int v; // 速度

    scanf("%d%d", &s, &v);

    int time = ceil(1.0 * s / v) + 10; // 所用时间,为了保证不迟到，我们采用向上取整的方式

    int form_zero = 60 * (24 + 8) - time; // 计算到前一天零点的时间,单位:min

    int HH = (form_zero / 60) % 24; // 计算所用小时
    int MM = form_zero % 60;
    printf("%02d:%02d\n", HH, MM);
}

int main()
{
    func1();

    return 0;
}