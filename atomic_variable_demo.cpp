#include <thread>
#include <atomic>
#include <iostream>

#define NNNNNN 1000000

std::atomic<int> g_atomic_num(0);
int g_num;

void increase()
{
    for (int i = 0; i < NNNNNN; ++i)
    {
        ++g_atomic_num;
        ++g_num;
    }
}

int main()
{
    std::thread th1(increase);
    std::thread th2(increase);

    th1.join();
    th2.join();

    std::cout << "g_atomic_num=" << g_atomic_num << "\n";
    std::cout << "g_num=" << g_num << "\n";

    return 0;
}