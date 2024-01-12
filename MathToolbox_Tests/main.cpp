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
    Matrix mat = Matrix::Trs(vec3(1.f, 0.f, 0.f), vec3(0.f, 0.f, calc::Pi) / 2.f, 2.f);
    PRINT(mat);
    vec3 v(1.f, 0.f, 0.f);
    PRINT(mat * v);

    return 0;
}
