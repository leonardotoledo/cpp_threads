#include <iostream>
#include <chrono>
#include <thread>

void run(int count)
{
    while (count --> 0)
        std::cout << count << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(3));
}

int main()
{
    std::thread t1(run, 10);
    std::cout << "main()" << std::endl;

    if (t1.joinable())
        t1.detach();

    // if (t1.joinable())
    //     t1.join();
    return 0;
}