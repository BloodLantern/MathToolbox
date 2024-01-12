#include <iostream>
#include <chrono>

#include "math.hpp"

#define PRINT(o) (std::cout << o << '\n' << std::endl)

int main()
{
    vec4 v = calc::Abs(4.f);

    return 0;
}
