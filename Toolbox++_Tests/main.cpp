#include <iostream>
#include <numbers>
#include <chrono>

#include "vector2.hpp"
#include "vector3.hpp"
#include "matrix.hpp"

#define PRINT(o) (std::cout << (o) << std::endl)
#define PI ((float) std::numbers::pi)

int main()
{
    PRINT(Matrix::TRS(Vector3(2, 3, 4), Vector3(PI / 6, PI / 3, PI / 4), Vector3(3, 2, 1)));

    return 0;
}
