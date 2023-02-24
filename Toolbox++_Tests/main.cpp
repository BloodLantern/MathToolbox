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
        { 6, 0, 4 },
        { 2, 0, 8 },
        { 3, 0, 9 }
    };

    std::cout << std::endl;
    PRINT(mat);

    std::cout << std::endl;
    PRINT(mat.Inverse());

    return 0;
}
