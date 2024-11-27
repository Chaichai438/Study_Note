#include <iostream>
using namespace std;

class AbstractDrinking
{
public:
    // 煮水
    virtual void Boil() = 0;
    // 冲泡
    virtual void Brew() = 0;
    // 倒茶
    virtual void PourInCup() = 0;
    // 辅料
    virtual void PutSomething() = 0;
    // 制作成品
    virtual void MakeDrink()
    {
        Boil();
        Brew();
        PourInCup();
        PutSomething();
        cout << "制作完成！" << endl;
    }
};

// 制作咖啡
class Coffee : public AbstractDrinking
{
    virtual void Boil()
    {
        cout << "煮饮用水..." << endl;
    }
    virtual void Brew()
    {
        cout << "冲泡咖啡..." << endl;
    }
    virtual void PourInCup()
    {
        cout << "倒入杯中..." << endl;
    }
    virtual void PutSomething()
    {
        cout << "加入糖和牛奶..." << endl;
    }
};

// 冲泡茶
class Tea : public AbstractDrinking
{
    virtual void Boil()
    {
        cout << "煮净水..." << endl;
    }
    virtual void Brew()
    {
        cout << "冲泡茶叶..." << endl;
    }
    virtual void PourInCup()
    {
        cout << "倒入杯中..." << endl;
    }
    virtual void PutSomething()
    {
        cout << "加入枸杞..." << endl;
    }
};

// 制作函数
void DoWork(AbstractDrinking *abs)
{
    abs->MakeDrink();
    delete abs;
}

void test01()
{
    // 制作咖啡
    DoWork(new Coffee);
    cout << "------------" << endl;
    // 制作茶叶
    DoWork(new Tea);
}

int main()
{
    test01();
    return 0;
}