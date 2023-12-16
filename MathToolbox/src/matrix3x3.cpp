#include "matrix3x3.hpp"
#include "matrix.hpp"
#include "matrix4x4.hpp"
#include "matrix2x2.hpp"
#include "quaternion.hpp"

#include <cassert>

#define SQ(var) ((var) * (var))

Matrix3x3 Matrix3x3::Identity()
{
    return Matrix3x3(
        1, 0, 0,
        0, 1, 0,
        0, 0, 1
    );
}

#pragma region functions
bool Matrix3x3::IsDiagonal() const
{
    for (size_t i = 0; i < 2; i++)
        for (size_t j = 0; j < 2; j++)
            if (i != j && (*this)[i][j] != 0)
                return false;
    return true;
}

bool Matrix3x3::IsIdentity() const
{
    if (!IsDiagonal())
        return false;

    for (size_t i = 0; i < 2; i++)
        if ((*this)[i][i] != 1)
            return false;
    return true;
}

bool Matrix3x3::IsNull() const
{
    if (!IsDiagonal())
        return false;

    for (size_t i = 0; i < 2; i++)
        if ((*this)[i][i] != 0)
            return false;
    return true;
}

bool Matrix3x3::IsSymmetric() const
{
    for (size_t i = 0; i < 2; i++)
        for (size_t j = i + 1; j < 2; j++)
            if ((*this)[i][j] != (*this)[j][i])
                return false;
    return true;
}

bool Matrix3x3::IsAntisymmetric() const
{
    for (size_t i = 0; i < 2; i++)
        for (size_t j = 0; j < 2; j++)
            if ((*this)[i][j] != -(*this)[j][i])
                return false;
    return true;
}

Vector3 Matrix3x3::Diagonal() const
{
    return Vector3(r0[0], r1[1]);
}

float Matrix3x3::Trace() const
{
    float result = 0.f;
    for (size_t i = 0; i < 2; i++)
        result += (*this)[i][i];
    return result;
}

float Matrix3x3::Determinant() const
{ 
    float result = 0.f;

    Matrix2x2 subMat(
        r1.y, r1.z,
        r2.y, r2.z
    );
    result += r0.x * subMat.Determinant();

    subMat[0] = Vector2(r0.y, r0.z);
    result -= r1.x * subMat.Determinant();

    subMat = Matrix2x2(
        r0.y, r0.z,
        r1.y, r1.z
    );
    result += r2.x * subMat.Determinant();

    return result;
}

Matrix3x3 &Matrix3x3::LoadIdentity()
{
    return *this = Matrix3x3::Identity();
}

Matrix3x3 &Matrix3x3::Transpose()
{
    return *this = Matrix3x3::Transpose(*this);
}

Matrix3x3 &Matrix3x3::Inverse()
{
    return *this = Matrix3x3::Inverse(*this);
}

Matrix3x3 Matrix3x3::Transpose(const Matrix3x3& matrix)
{
    return {
        { matrix.r0.x, matrix.r1.x, matrix.r2.x },
        { matrix.r0.y, matrix.r1.y, matrix.r2.y },
        { matrix.r0.z, matrix.r1.z, matrix.r2.z }
    };
}

float Matrix3x3::Cofactor(const Matrix3x3 &matrix, size_t row, size_t column)
{
    Matrix2x2 result;
    
    for (size_t i = 0, k = 0; i < 3; i++)
        if (i != row)
        {
            for (size_t j = 0, l = 0; j < 3; j++)
                if (j != column)
                {
                    result[k][l] = matrix[i][j];
                    l++;
                }
            k++;
        }

    return result.Determinant();
}

Matrix3x3 Matrix3x3::Cofactor(const Matrix3x3 &matrix)
{
    Matrix3x3 result;
    
    for (size_t i = 0; i < 3; i++)
        for (size_t j = 0; j < 3; j++)
            result[i][j] = Cofactor(matrix, i, j);

    return result;
}

Matrix3x3 Matrix3x3::Inverse(const Matrix3x3 &matrix)
{
    if (matrix.Determinant() == 0) [[unlikely]]
        throw std::invalid_argument("Matrix3x3 isn't inversible");
    else [[likely]]
        return Matrix3x3::Cofactor(matrix).Transpose() * (1 / matrix.Determinant());
}

Matrix3x3 Matrix3x3::Rotation3D(const float angle, const Vector3 &axis)
{
    return Rotation3D(std::cos(angle), std::sin(angle), axis);
}

Matrix3x3 Matrix3x3::Rotation3DX(const float angle)
{
    return Rotation3DX(std::cos(angle), std::sin(angle));
}

Matrix3x3 Matrix3x3::Rotation3DX(const float cos, const float sin)
{
    return Matrix3x3(
        1,    0,     0,
        0,  cos,  -sin,
        0,  sin,   cos
    );
}

Matrix3x3 Matrix3x3::Rotation3DY(const float angle)
{
    return Rotation3DY(std::cos(angle), std::sin(angle));
}

Matrix3x3 Matrix3x3::Rotation3DY(const float cos, const float sin)
{
    return Matrix3x3(
         cos,  0,  sin,
           0,  1,    0,
        -sin,  0,  cos
    );
}

Matrix3x3 Matrix3x3::Rotation3DZ(const float angle)
{
    return Rotation3DZ(std::cos(angle), std::sin(angle));
}

Matrix3x3 Matrix3x3::Rotation3DZ(const float cos, const float sin)
{
    return Matrix3x3(
        cos, -sin,  0,
        sin,  cos,  0,
          0,    0,  1
    );
}

Matrix3x3 Matrix3x3::Rotation3D(const Vector3 &rotation)
{
    return Matrix3x3::Rotation3DZ(rotation.z)
         * Matrix3x3::Rotation3DY(rotation.y)
         * Matrix3x3::Rotation3DX(rotation.x);
}

Matrix3x3 Matrix3x3::Rotation3D(const Quaternion& rotation)
{
    float xx = SQ(rotation.X());
    float yy = SQ(rotation.Y());
    float zz = SQ(rotation.Z());

    float xy = rotation.X() * rotation.Y();
    float wz = rotation.Z() * rotation.W();
    float xz = rotation.Z() * rotation.X();
    float wy = rotation.Y() * rotation.W();
    float yz = rotation.Y() * rotation.Z();
    float wx = rotation.X() * rotation.W();

    Matrix3x3 result;

    result[0] = Vector3(
        1.f - 2.f * (yy + zz),
        2.f * (xy - wz),
        2.f * (xz + wy)
    );
    result[1] = Vector3(
        2.f * (xy + wz),
        1.f - 2.f * (zz + xx),
        2.f * (yz - wx)
    );
    result[2] = Vector3(
        2.f * (xz - wy),
        2.f * (yz + wx),
        1.f - 2.f * (yy + xx)
    );

    return result;
}

Matrix3x3 Matrix3x3::Rotation3D(const float cos, const float sin, const Vector3 &axis)
{
    const float c2 = 1 - cos;
    Vector3 v = axis.Normalized();

    return Matrix3x3(
        SQ(v.x) * c2 + cos, v.y * v.x * c2 - v.z * sin, v.z * v.x * c2 + v.y * sin,
        v.x * v.y * c2 - v.z * sin, SQ(v.y) * c2 + cos, v.z * v.y * c2 - v.x * sin,
        v.x * v.z * c2 - v.y * sin, v.y * v.z * c2 + v.x * sin, SQ(v.z) * c2 + cos
    );
}

Matrix3x3 Matrix3x3::Scaling3D(const Vector3 &scale)
{
    return Matrix3x3(
        scale.x,       0,       0,
              0, scale.y,       0,
              0,       0, scale.z
    );
}

constexpr const Vector3 &Matrix3x3::operator[](const size_t row) const
{
    return (&r0)[row];
}

constexpr Vector3 &Matrix3x3::operator[](const size_t row)
{
    return (&r0)[row];
}
#pragma endregion

#pragma region operators
Matrix3x3::operator Vector3() const
{
    return Vector3(r0.x, r1.x, r2.x);
}

Matrix3x3::operator Vector<3>() const
{
    return Vector<3>{ r0.x, r1.x, r2.x };
}

Matrix3x3::operator Matrix2x2() const
{
    return Matrix2x2(
        r0.x, r0.y,
        r1.x, r1.y
    );
}

Matrix3x3::operator Matrix4x4() const
{
    return Matrix4x4(
        r0.x, r0.y, r0.z, 0,
        r1.x, r1.y, r1.z, 0,
        r2.x, r2.y, r2.z, 0,
        0, 0, 0, 1
    );
}

Matrix3x3::operator Matrix<3>() const
{
    return Matrix<3>{
        r0, r1, r2
    };
}

Matrix3x3 operator-(const Matrix3x3& matrix)
{
    return Matrix3x3(
        -matrix[0].x, -matrix[0].y, -matrix[0].z,
        -matrix[1].x, -matrix[1].y, -matrix[1].z,
        -matrix[2].x, -matrix[2].y, -matrix[2].z
    );
}

Matrix3x3 operator+(const Matrix3x3 &m1, const Matrix3x3 &m2)
{
    return Matrix3x3(
        m1[0].x + m2[0].x, m1[0].y + m2[0].y, m1[0].z + m2[0].z,
        m1[1].x + m2[1].x, m1[1].y + m2[1].y, m1[1].z + m2[1].z,
        m1[2].x + m2[2].x, m1[2].y + m2[2].y, m1[2].z + m2[2].z
    );
}

Matrix3x3 operator-(const Matrix3x3 &m1, const Matrix3x3 &m2)
{
    return m1 + (-m2);
}

Matrix3x3 operator*(const Matrix3x3 &m, const float scalar)
{
    return Matrix3x3(
        m[0][0] * scalar, m[0][1] * scalar, m[0][2] * scalar,
        m[1][0] * scalar, m[1][1] * scalar, m[1][2] * scalar,
        m[2][0] * scalar, m[2][1] * scalar, m[2][2] * scalar
    );
}

Matrix3x3 operator*(const Matrix3x3 &m1, const Matrix3x3 &m2)
{
    Matrix3x3 result;

    for (size_t i = 0; i < 3; i++)
        for (size_t j = 0; j < 3; j++)
            for (size_t k = 0; k < 3; k++)
                result[i][j] += m1[i][k] * m2[k][j];
    return result;
}

Matrix3x3 &operator+=(Matrix3x3 &m1, const Matrix3x3 &m2)
{
    return m1 = m1 + m2;
}

Matrix3x3 &operator-=(Matrix3x3 &m1, const Matrix3x3 &m2)
{
    return m1 = m1 - m2;
}

Matrix3x3 &operator*=(Matrix3x3 &m, const float scalar)
{
    return m = m * scalar;
}

Matrix3x3 &operator*=(Matrix3x3 &m1, const Matrix3x3 &m2)
{
    return m1 = m1 * m2;
}

std::ostream &operator<<(std::ostream &out, const Matrix3x3 &m)
{
    out << m[0] << '\n';
    out << m[1] << '\n';
    out << m[2];
    return out;
}
#pragma endregion
