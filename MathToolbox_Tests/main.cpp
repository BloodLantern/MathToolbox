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
    Vector3 euler(PI / 2.f, 0.f, 0.f);
    Quaternion rotation = Quaternion::FromEuler(euler);
    
    PRINT(point);
    
    PRINT(euler);

    PRINT(rotation);

    Vector3 newPoint = (Vector3) (rotation * point * rotation.Conjugate());

    PRINT(newPoint);

    newPoint = Quaternion::Rotate(point, rotation);

    PRINT(newPoint);

    Matrix4x4 trs = Matrix4x4::TRS(0.f, rotation, 1.f);

    PRINT(trs);

    trs = Matrix4x4::TRS(0.f, euler, 1.f);

    PRINT(trs);

    return 0;
}
