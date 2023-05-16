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
#define PI ((float) std::numbers::pi)

int main()
{
    Matrix<4, 4> m = {
        { 2, 5, 3, 7 },
        { 4, 1, 6, 8 },
        { 1, 2, 3, 4 },
        { 5, 6, 7, 8 }
    };
    PRINT(m);
    PRINT(m.Determinant());
    Matrix<4, 4> m2 = m.Inverse();
    PRINT(m);
    PRINT(m * m2);

    return 0;
}
