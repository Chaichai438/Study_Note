#include <iostream>
#include <string>
using namespace std;

// 分别利用普通写法和多态技术实现计算器

// 普通实现
class Calculator
{
public:
    int
    getResult(string oper)
    {
        if (oper == "+")
        {
            return Num1 + Num2;
        }
        else if (oper == "-")
        {
            return Num1 - Num2;
        }
        else if (oper == "*")
        {
            return Num1 * Num2;
        }
        // 缺点：如果向扩展新的功能，需要修改源码
        // 在真实的开发中 提倡 开闭原则
        // 开闭原则：对扩展进行开放 对修改进行关闭
    }
    int Num1; // 操作数1
    int Num2; // 操作数2
};

void test01()
{
    // 创建计算机对象
    Calculator c;
    c.Num1 = 10;
    c.Num2 = 20;

    cout << c.Num1 << "+" << c.Num2 << "=" << c.getResult("+") << endl;
    cout << c.Num1 << "-" << c.Num2 << "=" << c.getResult("-") << endl;
    cout << c.Num1 << "*" << c.Num2 << "=" << c.getResult("*") << endl;
}

// 利用多态实现计算器
// 多态带来的好处：
// 1、组织结构清晰
// 2、可读性强
// 3、对于前期和后期扩展以及维护性高
// 实现计算器抽象类
class AbstractCalculator
{
public:
    virtual int getResult()
    {
        return 0;
    }
    int Num1;
    int Num2;
};

// 加法计算器类
class AddCalculator : public AbstractCalculator
{
public:
    virtual int getResult()
    {
        return Num1 + Num2;
    }
};

// 减法计算器类
class SubCalculator : public AbstractCalculator
{
public:
    virtual int getResult()
    {
        return Num1 - Num2;
    }
};

// 乘法计算器类
class MulCalculator : public AbstractCalculator
{
public:
    virtual int getResult()
    {
        return Num1 * Num2;
    }
};

void test02()
{
    // 多态使用条件
    // 父类指针或者引用指向子类对象

    // 加法运算
    AbstractCalculator *abc = new AddCalculator;
    abc->Num1 = 10;
    abc->Num2 = 10;

    cout << abc->Num1 << "+" << abc->Num2 << "=" << abc->getResult() << endl;
    delete abc;

    // 减法运算
    abc = new SubCalculator;
    abc->Num1 = 100;
    abc->Num2 = 10;
    cout << abc->Num1 << "-" << abc->Num2 << "=" << abc->getResult() << endl;
    delete abc;

    // 乘法运算
    abc = new MulCalculator;
    abc->Num1 = 100;
    abc->Num2 = 10;
    cout << abc->Num1 << "*" << abc->Num2 << "=" << abc->getResult() << endl;
    delete abc;
}

int main()
{
    // test01();

    test02();
    return 0;
}