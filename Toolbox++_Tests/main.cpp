#include <iostream>
#include <numbers>
#include <chrono>

#include "vector2i.hpp"
#include "vector2.hpp"
#include "vector3.hpp"
#include "matrix.hpp"
#include "matrix4x4.hpp"
#include "calc.hpp"

#define PRINT(o) (std::cout << (o) << std::endl)
#define PI ((float) std::numbers::pi)

int main()
{
    Matrix4x4 mat = Matrix4x4::Identity();
    PRINT(mat);
    std::cout << std::endl;

    PRINT(Matrix::RotationMatrix3DX(PI / 2));

    std::cout << std::endl;
    std::cout << (int) calc::Sign(-7) << std::endl;

    Vector3 v0 = { 3, 0.5f, 5 };
    Vector3 v1 = { 1.5f, 56, -6.5f };
    PRINT(Matrix::TRS(v0, Matrix::RotationMatrix3DX(PI / 2), v1));

    return 0;
}
