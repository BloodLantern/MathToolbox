#include <iostream>
#include <chrono>
#include <functional>
#include <numeric>

#include "math.hpp"

#define PRINT(o) (std::cout << o << '\n' << std::endl)

void Time(std::function<void()> func, int count = 1)
{
    using namespace std::chrono;
    
    time_point<high_resolution_clock> start;

    std::vector<double> durations(count);

    for (int i = 0; i < count; i++)
    {
        start = high_resolution_clock::now();
        func();
        durations.push_back(duration<double>(high_resolution_clock::now() - start).count());
    }
    
    PRINT("Average time over " << count << " iterations: " << std::reduce(durations.begin(), durations.end()) / count << "s");
}

int main()
{
    Matrix m;

    std::cout << std::fixed << std::setprecision(9);
    
    Time(
        [&]()
        {
            m.Transposed(m);
        },
        1000
    );
    
    Time(
        [&]()
        {
            m = m.Transposed();
        },
        1000
    );
    
    return 0;
}
