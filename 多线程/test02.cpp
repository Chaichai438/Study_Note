#include <iostream>
#include <thread>
#include <memory>

class A
{
    friend void thread_01();

private:
    void function()
    {
        std::cout << "My Demo Work" << std::endl;
    }
};

void thread_01()
{
    std::shared_ptr<A> a = std::make_shared<A>(); // 智能指针

    std::thread thread01(&A::function, a);
    thread01.join();
}

int main()
{
    thread_01();
    return 0;
}