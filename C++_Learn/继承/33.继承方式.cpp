#include <iostream>
using namespace std;

// 继承方式

// 公共继承
class Basel
{
public:
    int A;

protected:
    int B;

private:
    int C;
};

class Son1 : public Basel
{
public:
    void func()
    {
        A = 10; // 父类中的公共权限成员 到子类中依然是公共权限
        B = 10; // 父类中的保护权限成员 到子类中依然是保护权限
        // C=10;//父类中的私有权限成员 到子类访问不到
    }
};

void test01()
{
    Son1 s1;
    s1.A = 100;
    //  s1.B = 100;//到Son1中 B时保护权限 类外访问不到
}

// 保护继承
class Base2
{
public:
    int A;

protected:
    int B;

private:
    int C;
};

class Son2 : protected Base2
{
public:
    void func2()
    {
        A = 100; // 父类中公共成员 到子类中变为保护权限
        B = 200; // 父类中保护成员 到子类中变为保护权限
        // C=300;/父类中的私有权限成员 到子类访问不到
    }
};

void test02()
{
    Son2 s2;
    // s2.A = 100;//在Son2中 A变为保护权限 类外访问不到
}

class Base3
{
public:
    int A;

protected:
    int B;

private:
    int C;
};

// 私有继承
class Son3 : private Base3
{
public:
    void func3()
    {
        A = 100;
        B = 200;
        // C = 300; //访问不到
    }
};

void test03()
{
    Son3 s3;
    // s3.A = 100;   //为私有继承，父类中的均为私有权限，类外访问不到
    // s3.B = 200;
    // s3.C = 300;
}

int main()
{
    test01();
    test02();
    test03();
    return 0;
}