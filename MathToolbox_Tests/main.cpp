#include <iostream>
#include <numbers>
#include <chrono>

#include "vector2i.hpp"
#include "vector2.hpp"
#include "vector3.hpp"
#include "matrix.hpp"
#include "matrix4x4.hpp"
#include "calc.hpp"
#include "quaternion.hpp"

#define PRINT(o) (std::cout << (o) << '\n' << std::endl)
#define PI std::numbers::pi_v<float>

int main()
{
    Vector3 euler(PI / 2.f, 0.f, 0.f);

    Matrix4x4 trs = Matrix4x4::TRS(10.f, euler, 2.f);

    PRINT(trs);

    Matrix4x4 inverse = Matrix4x4::Inverse(trs);

    PRINT(inverse);

    PRINT(trs * inverse);

    return 0;
}
