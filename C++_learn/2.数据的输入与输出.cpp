#include<iostream>

using namespace std;

int main()
{
    char name[100];
    cout << "请输入你的姓名:" << endl;
    
    cin >> name;                    //cin>>相当于scanf
    cout << name << endl;

    cout << "请给布尔值赋值:\n";
    bool flag = false;
    cin >> flag;
    cout << flag << endl;

    return 0; 
}