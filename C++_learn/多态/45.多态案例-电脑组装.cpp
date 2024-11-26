#include <iostream>
using namespace std;

// CPU
class CPUAbstract
{
public:
    // 抽象计算函数
    virtual void calculate() = 0;
};

// 显卡
class VideoCardAbstract
{
public:
    // 抽象显示函数
    virtual void display() = 0;
};

// 内存条
class MemoryAbstract
{
public:
    // 抽象存储函数
    virtual void storage() = 0;
};

// 电脑主机
class Computer
{
public:
    Computer(CPUAbstract *cpu, VideoCardAbstract *vc, MemoryAbstract *my)
    {
        CPU = cpu;
        VC = vc;
        MY = my;
    }

    // 提供工作的函数
    void Run()
    {
        CPU->calculate();
        VC->display();
        MY->storage();
    }

private:
    CPUAbstract *CPU;
    VideoCardAbstract *VC;
    MemoryAbstract *MY;
};

// Intel厂商
class IntelCPU : public CPUAbstract
{
public:
    void calculate()
    {
        cout << "Intel的CPU开始计算了!" << endl;
    }
};

class IntelCard : public VideoCardAbstract
{
public:
    virtual void display()
    {
        cout << "Intel的显卡开始显示了!" << endl;
    }
};

class IntelMemory : public MemoryAbstract
{
public:
    virtual void storage()
    {
        cout << "Intel的内存开始存储了!" << endl;
    }
};

// 联想厂商
class LenovoCPU : public CPUAbstract
{
public:
    void calculate()
    {
        cout << "Lenovo的CPU开始计算了!" << endl;
    }
};

class LenovoCard : public VideoCardAbstract
{
public:
    virtual void display()
    {
        cout << "Lenovo的显卡开始显示了!" << endl;
    }
};

class LenovoMemory : public MemoryAbstract
{
public:
    virtual void storage()
    {
        cout << "Lenovo的内存开始存储了!" << endl;
    }
};

// 华为厂商
class HuaweiCPU : public CPUAbstract
{
public:
    void calculate()
    {
        cout << "Huawei的CPU开始计算了!" << endl;
    }
};

class HuaweiCard : public VideoCardAbstract
{
public:
    virtual void display()
    {
        cout << "Huawei的显卡开始显示了!" << endl;
    }
};

class HuaweiMemory : public MemoryAbstract
{
public:
    virtual void storage()
    {
        cout << "Huawei的内存开始存储了!" << endl;
    }
};

void test01()
{
    CPUAbstract *intelCpu = new IntelCPU;
    VideoCardAbstract *intelCard = new IntelCard;
    MemoryAbstract *intelMemory = new IntelMemory;

    Computer *computer1 = new Computer(intelCpu, intelCard, intelMemory);
    computer1->Run();
    delete computer1;
}

void test02()
{
    CPUAbstract *intelCpu = new IntelCPU;
    VideoCardAbstract *lenovoCard = new LenovoCard;
    MemoryAbstract *huaweiMemory = new HuaweiMemory;

    Computer *computer2 = new Computer(intelCpu, lenovoCard, huaweiMemory);
    computer2->Run();
    delete computer2;
}

int main()
{
    // test01();

    test02();
    return 0;
}