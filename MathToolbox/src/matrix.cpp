#include "matrix.hpp"

#include <iostream>

#include "calc.hpp"
#include "vector3.hpp"

void Matrix::DebugPrint() const noexcept
{
    std::cout << "{ "
        << m00 << ' ' << m01 << ' ' << m02 << ' ' << m03 << " }\n{ "
        << m10 << ' ' << m11 << ' ' << m12 << ' ' << m13 << " }\n{ "
        << m20 << ' ' << m21 << ' ' << m22 << ' ' << m23 << " }\n{ "
        << m30 << ' ' << m31 << ' ' << m32 << ' ' << m33 << " }\n";
}

bool Matrix::IsDiagonal() const noexcept
{
    return                      calc::IsZero(m01) && calc::IsZero(m02) && calc::IsZero(m03)
        && calc::IsZero(m10)                      && calc::IsZero(m12) && calc::IsZero(m13)
        && calc::IsZero(m20) && calc::IsZero(m21)                      && calc::IsZero(m23)
        && calc::IsZero(m30) && calc::IsZero(m31) && calc::IsZero(m32);
}

bool Matrix::IsIdentity() const noexcept
{
    if (!IsDiagonal())
        return false;
    
    return calc::Equals(m00, 1.f) && calc::Equals(m11, 1.f) && calc::Equals(m22, 1.f) && calc::Equals(m33, 1.f);
}

bool Matrix::IsNull() const noexcept
{
    if (!IsDiagonal())
        return false;

    return calc::IsZero(m00) && calc::IsZero(m11) && calc::IsZero(m22) && calc::IsZero(m33);
}

bool Matrix::IsSymmetric() const noexcept
{
    return calc::Equals(m01, m10) && calc::Equals(m02, m20) && calc::Equals(m03, m30)
        && calc::Equals(m12, m21) && calc::Equals(m13, m31)
        && calc::Equals(m23, m32);
}

bool Matrix::IsAntisymmetric() const noexcept
{
    return calc::Equals(m01, -m10) && calc::Equals(m02, -m20) && calc::Equals(m03, -m30)
        && calc::Equals(m12, -m21) && calc::Equals(m13, -m31)
        && calc::Equals(m23, -m32);
}

Matrix Matrix::Rotation(const float angle, const Vector3& axis) noexcept
{
    return Rotation(std::cos(angle), std::sin(angle), axis);
}

void Matrix::Rotation(const float angle, const Vector3& axis, Matrix& result) noexcept
{
    Rotation(std::cos(angle), std::sin(angle), axis, result);
}

Matrix Matrix::RotationX(const float angle) noexcept
{
    return RotationX(std::cos(angle), std::sin(angle));
}

void Matrix::RotationX(const float angle, Matrix& result) noexcept
{
    RotationX(std::cos(angle), std::sin(angle), result);
}

Matrix Matrix::RotationY(const float angle) noexcept
{
    return RotationY(std::cos(angle), std::sin(angle));
}

void Matrix::RotationY(const float angle, Matrix& result) noexcept
{
    RotationY(std::cos(angle), std::sin(angle), result);
}

Matrix Matrix::RotationZ(const float angle) noexcept
{
    return RotationZ(std::cos(angle), std::sin(angle));
}

void Matrix::RotationZ(const float angle, Matrix& result) noexcept
{
    RotationZ(std::cos(angle), std::sin(angle), result);
}

Matrix Matrix::Rotation(const Vector3& rotation) noexcept
{
    return RotationZ(rotation.z)
         * RotationY(rotation.y)
         * RotationX(rotation.x);
}

void Matrix::Rotation(const Vector3& rotation, Matrix& result) noexcept
{
    RotationZ(rotation.z, result);
    Matrix temp;
    RotationY(rotation.y, temp);
    result *= temp;
    RotationX(rotation.x, temp);
    result *= temp;
}

Matrix Matrix::Rotation(const float cos, const float sin, const Vector3& axis) noexcept
{
    const float c2 = 1.f - cos;
    Vector3 v = axis.Normalized();

    return Matrix(
        SQ(v.x) * c2 + cos, v.y * v.x * c2 - v.z * sin, v.z * v.x * c2 + v.y * sin, 0.f,
        v.x * v.y * c2 - v.z * sin, SQ(v.y) * c2 + cos, v.z * v.y * c2 - v.x * sin, 0.f,
        v.x * v.z * c2 - v.y * sin, v.y * v.z * c2 + v.x * sin, SQ(v.z) * c2 + cos, 0.f,
        0.f, 0.f, 0.f,                                                              1.f
    );
}

void Matrix::Rotation(const float cos, const float sin, const Vector3& axis, Matrix& result) noexcept
{
    const float c2 = 1.f - cos;
    Vector3 v = axis.Normalized();

    result = Matrix(
        SQ(v.x) * c2 + cos, v.y * v.x * c2 - v.z * sin, v.z * v.x * c2 + v.y * sin, 0.f,
        v.x * v.y * c2 - v.z * sin, SQ(v.y) * c2 + cos, v.z * v.y * c2 - v.x * sin, 0.f,
        v.x * v.z * c2 - v.y * sin, v.y * v.z * c2 + v.x * sin, SQ(v.z) * c2 + cos, 0.f,
        0.f, 0.f, 0.f,                                                              1.f
    );
}

Matrix Matrix::Trs(const Vector3& translation, const Vector3& rotation, const Vector3& scale) noexcept
{
    return Trs(translation, Rotation(rotation), scale);
}

void Matrix::Trs(const Vector3& translation, const Vector3& rotation, const Vector3& scale, Matrix& result) noexcept
{
    Trs(translation, Rotation(rotation), scale, result);
}

Matrix Matrix::Trs(const Vector3& translation, const float rotationAngle, const Vector3& rotationAxis, const Vector3& scale) noexcept
{
    return Trs(translation, Rotation(rotationAngle, rotationAxis), scale);
}

void Matrix::Trs(const Vector3& translation, const float rotationAngle, const Vector3& rotationAxis, const Vector3& scale, Matrix& result) noexcept
{
    Trs(translation, Rotation(rotationAngle, rotationAxis), scale, result);
}

Matrix Matrix::View(const Vector3& eye, const Vector3& center, const Vector3& up) noexcept
{
    const Vector3 cameraForward = -(eye - center).Normalized();
    const Vector3 cameraRight = Vector3::Cross(up, cameraForward).Normalized();
    const Vector3 cameraUp = Vector3::Cross(cameraForward, cameraRight);
    
    return Matrix(
        cameraRight.x, cameraRight.y, cameraRight.z, 0.f,
        cameraUp.x, cameraUp.y, cameraUp.z, 0.f,
        cameraForward.x, cameraForward.y, cameraForward.z, 0.f,
        0.f, 0.f, 0.f, 1.f
    ) * Translation(-eye);
}

void Matrix::View(const Vector3& eye, const Vector3& center, const Vector3& up, Matrix &result) noexcept
{
    const Vector3 cameraForward = -(eye - center).Normalized();
    const Vector3 cameraRight = Vector3::Cross(up, cameraForward).Normalized();
    const Vector3 cameraUp = Vector3::Cross(cameraForward, cameraRight);
    
    result = Matrix(
        cameraRight.x, cameraRight.y, cameraRight.z, 0.f,
        cameraUp.x, cameraUp.y, cameraUp.z, 0.f,
        cameraForward.x, cameraForward.y, cameraForward.z, 0.f,
        0.f, 0.f, 0.f, 1.f
    ) * Translation(-eye);
}

Matrix Matrix::Perspective(const float fov, const float aspectRatio, const float near, const float far)
{
    if (near > far) [[unlikely]]
        throw std::invalid_argument("Near must be smaller than far.");
    const float range = near - far;
    const float tanHalfFov = std::tan(fov / 2);

    return Matrix(
        1.f / (tanHalfFov * aspectRatio), 0.f, 0.f, 0.f,
        0.f, 1.f / tanHalfFov, 0.f, 0.f,
        0.f, 0.f, (-near - far) / range, 2.f * far * near / range,
        0.f, 0.f, 1.f, 0.f
    );
}

void Matrix::Perspective(const float fov, const float aspectRatio, const float near, const float far, Matrix &result)
{
    if (near > far) [[unlikely]]
        throw std::invalid_argument("Near must be smaller than far.");
    const float range = near - far;
    const float tanHalfFov = std::tan(fov / 2);

    result = Matrix(
        1.f / (tanHalfFov * aspectRatio), 0.f, 0.f, 0.f,
        0.f, 1.f / tanHalfFov, 0.f, 0.f,
        0.f, 0.f, (-near - far) / range, 2.f * far * near / range,
        0.f, 0.f, 1.f, 0.f
    );
}

Matrix::operator Vector4() const noexcept
{
    return Vector4(m00, m01, m02, m03);
}

bool operator==(Matrix a, Matrix b)
{
    return calc::Equals(a.m00, b.m00) && calc::Equals(a.m01, b.m01) && calc::Equals(a.m02, b.m02) && calc::Equals(a.m03, b.m03)
        && calc::Equals(a.m10, b.m10) && calc::Equals(a.m11, b.m11) && calc::Equals(a.m12, b.m12) && calc::Equals(a.m13, b.m13)
        && calc::Equals(a.m20, b.m20) && calc::Equals(a.m21, b.m21) && calc::Equals(a.m22, b.m22) && calc::Equals(a.m23, b.m23)
        && calc::Equals(a.m30, b.m30) && calc::Equals(a.m31, b.m31) && calc::Equals(a.m32, b.m32) && calc::Equals(a.m33, b.m33);
}

bool operator!=(Matrix a, Matrix b)
{
    return !(a == b);
}

std::ostream &operator<<(std::ostream &out, const Matrix &m)
{
    return out << "{ { " << m.m00 << ' ' << m.m01 << ' ' << m.m02 << ' ' << m.m03 << " } { "
                        << m.m10 << ' ' << m.m11 << ' ' << m.m12 << ' ' << m.m13 << " } { "
                        << m.m20 << ' ' << m.m21 << ' ' << m.m22 << ' ' << m.m23 << " } { "
                        << m.m30 << ' ' << m.m31 << ' ' << m.m32 << ' ' << m.m33 << " } }";
}
