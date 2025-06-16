#include <iostream>
#include <thread>
#include <mutex> //互斥锁

std::mutex mtx1;
std::mutex mtx2;
void func01()
{
    for (int i = 0; i < 500; ++i)
    {
        mtx1.lock();
        mtx2.lock();
        mtx1.unlock();
        mtx2.unlock();
    }
}

void func02()
{
    for (int i = 0; i < 20; ++i)
    {
        mtx2.lock();
        mtx1.lock();
        mtx1.unlock();
        mtx2.unlock();
    }
}

int main()
{
    std::thread t1(func01);
    std::thread t2(func02);

    t1.join();
    t2.join();

    std::cout << "Finish" << std::endl;

    return 0;
}