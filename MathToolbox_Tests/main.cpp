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
    constexpr vec2i v2(1, 2);

    return v2.x;
}
