#include <iostream>
#include <numbers>
#include <chrono>

#include "vector2.hpp"
#include "vector3.hpp"
#include "matrix.hpp"

#define PRINT(o) (std::cout << (o) << std::endl)

int main()
{
    Matrix mat = { 
        { 1, 2, 3 },
        { 4, 5, 6 },
        { 7, 8, 9 }
    };

    std::cout << std::endl;
    PRINT(mat);

    Vector v = mat.Diagonal();

    std::cout << std::endl;
    PRINT(v);

    return 0;
}
