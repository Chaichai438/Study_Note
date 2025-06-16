#include <iostream>
#include <future>

int func()
{
    int i = 0;
    for (i = 0; i < 1000; i++)
    {
        i++;
    }

    return i;
}

int main()
{
    std::future<int> future_result = std::async(std::launch::async, func);
    std::cout << func() << std::endl;

    std::cout << future_result.get() << std::endl;
}