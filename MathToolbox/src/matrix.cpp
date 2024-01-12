#include "matrix.hpp"

#include "calc.hpp"
#include "vector3.hpp"

bool Matrix::IsDiagonal() const noexcept
{
    for (size_t i = 0; i < 4; i++)
    {
        for (size_t j = 0; j < 4; j++)
        {
            if (i != j && !calc::IsZero((*this)[i][j]))
                return false;
        }
    }
    
    return true;
}

bool Matrix::IsIdentity() const noexcept
{
    if (!IsDiagonal())
        return false;

    for (size_t i = 0; i < 4; i++)
    {
        if (!calc::Equals((*this)[i][i], 1.f))
            return false;
    }
    
    return true;
}

bool Matrix::IsNull() const noexcept
{
    if (!IsDiagonal())
        return false;

    for (size_t i = 0; i < 4; i++)
    {
        if (!calc::IsZero((*this)[i][i]))
            return false;
    }
    
    return true;
}

bool Matrix::IsSymmetric() const noexcept
{
    for (size_t i = 0; i < 4; i++)
    {
        for (size_t j = i + 1; j < 4; j++)
        {
            if (!calc::Equals((*this)[i][j], (*this)[j][i]))
                return false;
        }
    }
    
    return true;
}

bool Matrix::IsAntisymmetric() const noexcept
{
    for (size_t i = 0; i < 4; i++)
    {
        for (size_t j = 0; j < 4; j++)
        {
            if (!calc::Equals((*this)[i][j], -(*this)[j][i]))
                return false;
        }
    }
    
    return true;
}

Matrix Matrix::Rotation3D(const float angle, const Vector3 &axis) noexcept
{
    return Rotation3D(std::cos(angle), std::sin(angle), axis);
}

Matrix Matrix::Rotation3DX(const float angle) noexcept
{
    return Rotation3DX(std::cos(angle), std::sin(angle));
}

Matrix Matrix::Rotation3DY(const float angle) noexcept
{
    return Rotation3DY(std::cos(angle), std::sin(angle));
}

Matrix Matrix::Rotation3DZ(const float angle) noexcept
{
    return Rotation3DZ(std::cos(angle), std::sin(angle));
}

Matrix Matrix::Rotation3D(const Vector3 &rotation) noexcept
{
    return Rotation3DZ(rotation.z)
         * Rotation3DY(rotation.y)
         * Rotation3DX(rotation.x);
}

Matrix Matrix::Rotation3D(const float cos, const float sin, const Vector3 &axis) noexcept
{
    const float c2 = 1 - cos;
    Vector3 v = axis.Normalized();

    return Matrix(
        SQ(v.x) * c2 + cos, v.y * v.x * c2 - v.z * sin, v.z * v.x * c2 + v.y * sin, 0.f,
        v.x * v.y * c2 - v.z * sin, SQ(v.y) * c2 + cos, v.z * v.y * c2 - v.x * sin, 0.f,
        v.x * v.z * c2 - v.y * sin, v.y * v.z * c2 + v.x * sin, SQ(v.z) * c2 + cos, 0.f,
        0.f, 0.f, 0.f,                                                              1.f
    );
}

Matrix Matrix::Trs(const Vector3 &translation, const Vector3 &rotation, const Vector3 &scale) noexcept
{
    return Trs(translation, Rotation3D(rotation), scale);
}

Matrix Matrix::Trs(const Vector3 &translation, const float rotationAngle, const Vector3& axis, const Vector3 &scale) noexcept
{
    return Trs(translation, Rotation3D(rotationAngle, axis), scale);
}

void Matrix::View(const Vector3 &eye, const Vector3 &center, const Vector3 &up, Matrix &result) noexcept
{
    const Vector3 cameraForward = -(eye - center).Normalized();
    const Vector3 cameraRight = Vector3::Cross(up, cameraForward).Normalized();
    const Vector3 cameraUp = Vector3::Cross(cameraForward, cameraRight);
    
    result = Matrix(
        cameraRight.x, cameraRight.y, cameraRight.z, 0.f,
        cameraUp.x, cameraUp.y, cameraUp.z, 0.f,
        cameraForward.x, cameraForward.y, cameraForward.z, 0.f,
        0.f, 0.f, 0.f, 1.f
    ) * Translation3D(-eye);
}

void Matrix::PerspectiveProjection(const float fov, const float aspectRatio, const float near, const float far, Matrix &result)
{
    if (near > far) [[unlikely]]
        throw std::invalid_argument("Near must be smaller than far.");
    else [[likely]]
    {
        const float range = near - far;
        const float tanHalfFov = std::tan(fov / 2);

        result = Matrix(
            1.f / (tanHalfFov * aspectRatio), 0.f, 0.f, 0.f,
            0.f, 1.f / tanHalfFov, 0.f, 0.f,
            0.f, 0.f, (-near - far) / range, 2.f * far * near / range,
            0.f, 0.f, 1.f, 0.f
        );
    }
}

Matrix::operator Vector4() const noexcept
{
    return Vector4(r0.x, r1.x, r2.x, r3.x);
}

bool operator==(Matrix a, Matrix b)
{
    return a[0] == b[0]
        && a[1] == b[1]
        && a[2] == b[2]
        && a[3] == b[3];
}

bool operator!=(Matrix a, Matrix b)
{
    return !(a == b);
}

std::ostream &operator<<(std::ostream &out, const Matrix &m)
{
    return out << '{' << m[0] << m[1] << m[2] << m[3] << '}';
}
