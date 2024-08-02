#include "Maths/calc.hpp"

#include "Maths/matrix.hpp"
#include "Maths/matrix2.hpp"
#include "Maths/matrix3.hpp"
#include "Maths/quaternion.hpp"
#include "Maths/vector2.hpp"
#include "Maths/vector3.hpp"
#include "Maths/vector4.hpp"

bool_t Calc::Equals(const Vector2 a, const Vector2 b) noexcept
{
    return Equals(a.x, b.x) && Equals(a.y, b.y);
}

bool_t Calc::Equals(const Vector3& a, const Vector3& b) noexcept
{
    return Equals(a.x, b.x) && Equals(a.y, b.y) && Equals(a.z, b.z);
}

bool_t Calc::Equals(const Vector4& a, const Vector4& b) noexcept
{
    return Equals(a.x, b.x) && Equals(a.y, b.y) && Equals(a.z, b.z) && Equals(a.w, b.w);
}

bool_t Calc::Equals(const Matrix2& a, const Matrix2& b) noexcept
{
    return Equals(a.m00, b.m00) && Equals(a.m01, b.m01)
        && Equals(a.m10, b.m10) && Equals(a.m11, b.m11);
}

bool_t Calc::Equals(const Matrix3& a, const Matrix3& b) noexcept
{
    return Equals(a.m00, b.m00) && Equals(a.m01, b.m01) && Equals(a.m02, b.m02)
        && Equals(a.m10, b.m10) && Equals(a.m11, b.m11) && Equals(a.m12, b.m12)
        && Equals(a.m20, b.m20) && Equals(a.m21, b.m21) && Equals(a.m22, b.m22);
}

bool_t Calc::Equals(const Matrix& a, const Matrix& b) noexcept
{
    return Equals(a.m00, b.m00) && Equals(a.m01, b.m01) && Equals(a.m02, b.m02) && Equals(a.m03, b.m03)
        && Equals(a.m10, b.m10) && Equals(a.m11, b.m11) && Equals(a.m12, b.m12) && Equals(a.m13, b.m13)
        && Equals(a.m20, b.m20) && Equals(a.m21, b.m21) && Equals(a.m22, b.m22) && Equals(a.m23, b.m23)
        && Equals(a.m30, b.m30) && Equals(a.m31, b.m31) && Equals(a.m32, b.m32) && Equals(a.m33, b.m33);
}

bool_t Calc::Equals(const Quaternion& a, const Quaternion& b) noexcept
{
    return Equals(a.imaginary, b.imaginary) && Equals(a.real, b.real);
}
