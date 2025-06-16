#include <iostream>
#include <thread>
#include <mutex>
#include <string>
#include <condition_variable>
#include <queue>

std::queue<int> g_queue;
std::condition_variable g_cv;
std::mutex mtx;

void Producer()
{
    for (int i = 0; i < 10; i++)
    {

        {
            std::unique_lock<std::mutex> lock(mtx);
            g_queue.push(i);
            g_cv.notify_one();
            // 通知消费者来取任务
            std::cout << "task:" << i << std::endl;
        }
        std::this_thread::sleep_for(std::chrono::microseconds(100));
    }
}

void Consumer()
{
    while (1)
    {
        std::unique_lock<std::mutex> lock(mtx);
        g_cv.wait(lock, []()
                  { return !g_queue.empty(); });
        int value = g_queue.front();
        g_queue.pop();

        std::cout << "Consumer" << value << std::endl;
    }
}

int main()
{
    std::thread t1(Producer);
    std::thread t2(Consumer);
    t1.join();
    t2.join();
    return 0;
}