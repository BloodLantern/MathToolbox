#include <iostream>
#include <numbers>
#include <chrono>

#include "vector2i.hpp"
#include "vector2.hpp"
#include "vector3.hpp"
#include "matrix.hpp"
#include "matrix4x4.hpp"
#include "calc.hpp"

#define PRINT(o) (std::cout << (o) << '\n' << std::endl)
#define PI std::numbers::pi_v<float>

int main()
{
    Matrix<4> m = {
        { 1, 0, 0, 0 },
        { 0, 0, 1, 0 },
        { 0, -1, 0, 0 },
        { 0, 0, 0, 1 }
    };
    PRINT(m);
    PRINT(m.Determinant());
    PRINT(Matrix<4>::Cofactor(m));
    Matrix<4> m2 = Matrix<4>::Inverse(m);
    PRINT(m2);
    PRINT(m * m2);

    PRINT('\n');

    mat4 m3 = {
        { 1, 0, 0, 0 },
        { 0, 0, 1, 0 },
        { 0, -1, 0, 0 },
        { 0, 0, 0, 1 }
    };
    PRINT(m3);
    PRINT(m3.Determinant());
    PRINT(mat4::Cofactor(m3));
    mat4 m4 = mat4::Inverse(m3);
    PRINT(m4);
    PRINT(m3 * m4);

    return 0;
}
