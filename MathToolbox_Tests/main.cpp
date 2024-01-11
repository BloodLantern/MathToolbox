#include <iostream>
#include <chrono>

#include "calc.hpp"
#include "vector2i.hpp"
#include "vector2.hpp"
#include "vector3.hpp"
#include "vector4.hpp"
#include "matrix.hpp"
#include "quaternion.hpp"

#define PRINT(o) (std::cout << o << '\n' << std::endl)

int main()
{
    /*float f = 4.f;
    PRINT(f);
    PRINT(std::sqrt(f));
    auto start = std::chrono::high_resolution_clock::now();
    PRINT(1.f / std::sqrt(f));
    PRINT("Time: " << std::chrono::high_resolution_clock::now() - start);
    start = std::chrono::high_resolution_clock::now();
    PRINT(calc::FastInverseSqrt(f, false));
    PRINT("Time: " << std::chrono::high_resolution_clock::now() - start);
    start = std::chrono::high_resolution_clock::now();
    PRINT(calc::FastInverseSqrt(f, true));
    PRINT("Time: " << std::chrono::high_resolution_clock::now() - start);*/
    
    constexpr vec2i v2(1, 2);

    return v2.x;
}
