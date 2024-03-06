#include "matrix3.hpp"

#include <iostream>

Matrix3 Matrix3::Rotation(const float_t angle, const Vector3& axis) noexcept
{
    return Rotation(std::cos(angle), std::sin(angle), axis);
}

void Matrix3::Rotation(const float_t angle, const Vector3& axis, Matrix3* result) noexcept
{
    Rotation(std::cos(angle), std::sin(angle), axis, result);
}

Matrix3 Matrix3::RotationX(const float_t angle) noexcept
{
    return RotationX(std::cos(angle), std::sin(angle));
}

void Matrix3::RotationX(const float_t angle, Matrix3* result) noexcept
{
    RotationX(std::cos(angle), std::sin(angle), result);
}

Matrix3 Matrix3::RotationY(const float_t angle) noexcept
{
    return RotationY(std::cos(angle), std::sin(angle));
}

void Matrix3::RotationY(const float_t angle, Matrix3* result) noexcept
{
    RotationY(std::cos(angle), std::sin(angle), result);
}

Matrix3 Matrix3::RotationZ(const float_t angle) noexcept
{
    return RotationZ(std::cos(angle), std::sin(angle));
}

void Matrix3::RotationZ(const float_t angle, Matrix3* result) noexcept
{
    RotationZ(std::cos(angle), std::sin(angle), result);
}

Matrix3 Matrix3::Rotation(const Vector3& rotation) noexcept
{
    return RotationZ(rotation.z)
        * RotationY(rotation.y)
        * RotationX(rotation.x);
}

void Matrix3::Rotation(const Vector3& rotation, Matrix3* result) noexcept
{
    RotationZ(rotation.z, result);
    Matrix3 temp;
    RotationY(rotation.y, &temp);
    *result *= temp;
    RotationX(rotation.x, &temp);
    *result *= temp;
}

Matrix3 Matrix3::Rotation(const float_t cos, const float_t sin, const Vector3& axis) noexcept
{
    const float_t c2 = 1.f - cos;
    Vector3 v = axis.Normalized();

    return Matrix3(
        SQ(v.x) * c2 + cos, v.y * v.x * c2 - v.z * sin, v.z * v.x * c2 + v.y * sin,
        v.x * v.y * c2 - v.z * sin, SQ(v.y) * c2 + cos, v.z * v.y * c2 - v.x * sin,
        v.x * v.z * c2 - v.y * sin, v.y * v.z * c2 + v.x * sin, SQ(v.z) * c2 + cos
    );
}

void Matrix3::Rotation(const float_t cos, const float_t sin, const Vector3& axis, Matrix3* result) noexcept
{
    const float_t c2 = 1.f - cos;
    Vector3 v = axis.Normalized();

    *result = Matrix3(
        SQ(v.x) * c2 + cos, v.y * v.x * c2 - v.z * sin, v.z * v.x * c2 + v.y * sin,
        v.x * v.y * c2 - v.z * sin, SQ(v.y) * c2 + cos, v.z * v.y * c2 - v.x * sin,
        v.x * v.z * c2 - v.y * sin, v.y * v.z * c2 + v.x * sin, SQ(v.z) * c2 + cos
    );
}

void Matrix3::DebugPrint() const noexcept
{
    std::cout << "{ "
        << m00 << ' ' << m10 << ' ' << m20 << " }\n{ "
        << m01 << ' ' << m11 << ' ' << m21 << " }\n{ "
        << m02 << ' ' << m12 << ' ' << m22 << " }\n";
}

std::ostream& operator<<(std::ostream &out, const Matrix3 &m)
{
    return out << "{ { " << m.m00 << ' ' << m.m01 << ' ' << m.m02 << " } { "
        << m.m10 << ' ' << m.m11 << ' ' << m.m12 << " } { "
        << m.m20 << ' ' << m.m21 << ' ' << m.m22 << " } }";
}
