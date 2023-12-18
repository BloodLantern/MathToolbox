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
    Matrix4x4 matrix = Matrix3x3::Rotation3DY(PI / 2.f);

    PRINT(matrix);

    Quaternion quat = Quaternion::FromRotationMatrix(matrix);

    PRINT(quat);

    return 0;
}
