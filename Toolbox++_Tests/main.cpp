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
    Vector3 point(0, 1, 0);
    Quaternion rotation = Quaternion::FromEuler(Vector3(PI / 2.f, 0.f, 0.f));
    //Quaternion rotation = Quaternion::FromAxisAngle(Vector3(1.f, 0.f, 0.f), PI / 2.f);
    
    PRINT(point);
    PRINT((Quaternion) point);

    PRINT(rotation);

    Vector3 newPoint = (Vector3) (rotation * (Quaternion) point * rotation.Conjugate());

    PRINT(newPoint);

    return 0;
}
