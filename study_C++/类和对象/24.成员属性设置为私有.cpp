#include <iostream>
using namespace std;

// 成员属性设置私有
// 1.可以自己控制读写权限
// 2.对于写权限，我们可以检测数据的有效性

class Human
{
public:
    // 设置姓名
    void setName(string n)
    {
        name = n;
    }
    // 获取姓名
    string getName()
    {
        return name;
    }
    // 设置年龄  (0~150)
    void setAge()
    {
        int a;
        cout << "请输入要更改的年龄:" << endl;
        cin >> a;
        if (a < 0 || a > 150)
        {
            cout << "年龄输入有误，赋值失败" << endl;
            return;
        }
        age = a;
    }
    // 获取年龄
    int getAge()
    {
        return age;
    }
    // 设置Idoi
    void setIdoi(string n)
    {
        Idoi = n;
    }

private:
    string name; // 设置为可读可写

    int age = 18; // 设置为只读

    string Idoi; // 设置为只写
};

int main()
{
    Human h;
    h.setName("CWZ");
    cout << "姓名:" << h.getName() << endl;

    h.setAge();
    cout << "年龄:" << h.getAge() << endl;

    h.setIdoi("Jay Chou");
    // cout << "Idoi" << h.getIdoi() <<endl;   //只写状态，外界访问不到
}

/*总结
一般我们会将类里面的成员设置为私有
但是我们可以通过公共的函数自己来访问到成员里面的属性
同时，我们也可以写一些权限来确保数据的有效性
*/