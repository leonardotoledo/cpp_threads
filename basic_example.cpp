#include <iostream>
#include <thread>
#include <chrono>
#include <algorithm>

typedef unsigned long long ull;

ull oddSum = 0;
ull evenSum = 0;

void findEven(ull start, ull end)
{
    for (ull i = start; i <= end; ++i)
        if ((i & 1) == 0)
            evenSum += i;
}

void findOdd(ull start, ull end)
{
    for (ull i = start; i <= end; ++i)
        if ((i & 1) == 1)
            oddSum += i;
}

int main()
{
    ull start = 0, end = 1900000000;

    auto startTime = std::chrono::high_resolution_clock::now();

    std::thread t1(findEven, start, end);
    std::thread t2(findOdd, start, end);

    t1.join();
    t2.join();

    // findEven(start, end);
    // findOdd(start, end);

    auto stopTime = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::seconds>(stopTime - startTime);

    std::cout << "odd sum: " << oddSum << std::endl;
    std::cout << "even sum: " << evenSum << std::endl;
    std::cout << "Duration: " << duration.count() << " s." << std::endl;

    return 0;
}