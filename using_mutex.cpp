#include <iostream>
#include <thread>
#include <mutex>

// RACE CONDITION:
// Two or more threads try to modify the same variable.

// Mutex is used to avoid race condition
// We use lock() and unlock() to do so.
// Mutex prevents two threads from accessing the same variable at the exactly same time.

int myAmount = 0;
std::mutex m; // You have to use the same mutex variable for both threads

void addMoney()
{
    m.lock();
    ++myAmount;
    m.unlock();
}

int main()
{
    std::thread t1(addMoney);
    std::thread t2(addMoney);

    if (t1.joinable())
        t1.join();

    if (t2.joinable())
        t2.join();

    std::cout << myAmount << std::endl;
    return 0;
}