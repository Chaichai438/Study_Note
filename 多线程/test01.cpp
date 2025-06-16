#include <iostream>
#include <thread>
#include <string>

void printhelloworld(std::string msg)
{
    std::cout << msg << std::endl;
}

int main()
{
    // 1、创建线程
    std::thread thread01(printhelloworld, "Hello Thread");
    thread01.join(); // 检查线程是否结束
                     // thread01.joinable();
                    

    return 0;
}
