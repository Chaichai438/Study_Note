#include <iostream>

using namespace std;
// 普通实现页面

// Java页面
// class Java
// {
// public:
//     void header()
//     {
//         cout << "首页、公开课、登录、注册...(公共头部)" << endl;
//     }
//     void footer()
//     {
//         cout << "帮助中心、交流中心、站内地图...(公共底部)" << endl;
//     }
//     void left()
//     {
//         cout << "Java、Python、C++...公共分类列表" << endl;
//     }
//     void content()
//     {
//         cout << "Java学科视频" << endl;
//     }
// };

// Python页面
//....

// 继承实现页面
// 好处：减少重复代码
// 语法：class 子类(派生类) : 继承方式 父类(基类)
class BasePage
{
public:
    void header()
    {
        cout << "首页、公开课、登录、注册...(公共头部)" << endl;
    }
    void footer()
    {
        cout << "帮助中心、交流中心、站内地图...(公共底部)" << endl;
    }
    void left()
    {
        cout << "Java、Python、C++...公共分类列表" << endl;
    }
};

// Java页面
class Java : public BasePage
{
public:
    void content()
    {
        cout << "Java学科视频" << endl;
    }
};

// Python页面
class Python : public BasePage
{
public:
    void content()
    {
        cout << "Python学科视频" << endl;
    }
};

// C++页面
class CPP : public BasePage
{
public:
    void content()
    {
        cout << "C++学科视频" << endl;
    }
};

void test01()
{
    Java ja;
    ja.header();
    ja.footer();
    ja.left();
    ja.content();
}

int main()
{
    test01();

    return 0;
}