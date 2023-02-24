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
        { 3, 9, 4 },
        { 5, 0, 5 },
        { 4, 6, 7 }
    };

    std::cout << std::endl;
    PRINT(mat);

    std::cout << std::endl;
    PRINT(mat.Inverse());

    return 0;
}
