#include <iostream>

#include "calc.hpp"
#include "vector2i.hpp"
#include "vector2.hpp"
#include "vector3.hpp"
#include "vector4.hpp"
#include "matrix.hpp"
#include "quaternion.hpp"

#define PRINT(o) (std::cout << (o) << '\n' << std::endl)

int main()
{
    constexpr vec2 v2(1.f, 2.f);
    PRINT(v2);
    /*constexpr vec2i v2i(1, 2);
    PRINT(v2i);
    constexpr vec3 v3(1.f, 2.f, 3.f);
    PRINT(v3);
    constexpr vec4 v4(1.f, 2.f, 3.f, 4.f);
    PRINT(v4);
    constexpr quat q(1.f, 2.f, 3.f, 4.f);
    PRINT(q);
    constexpr mat4 m4(1.f, 2.f, 3.f, 4.f, 5.f, 6.f, 7.f, 8.f, 9.f, 10.f, 11.f, 12.f, 13.f, 14.f, 15.f, 16.f);
    PRINT(m4);*/

    return 0;
}
