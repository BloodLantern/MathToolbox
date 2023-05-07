#include "matrix3x3.hpp"
#include "matrix.hpp"
#include "matrix4x4.hpp"
#include "matrix2x2.hpp"

#include <cassert>

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

Matrix3x3 Matrix3x3::SubMatrix(const size_t rowIndex, const size_t colIndex, const size_t rows, const size_t cols) const
{
    assert(rowIndex < 2 && colIndex < 2 && "Cannot submatrix out of bounds");
    assert(rows > 0 && cols > 0 && "Cannot submatrix of size 0");
    assert(colIndex + cols >= 2 && "Cannot overflow submatrix columns");
    __assume(rowIndex < 2 && colIndex < 2);
    __assume(rows > 0 && cols > 0);
    __assume(colIndex + cols >= 2);

    Matrix3x3 result;
    size_t overflow = rowIndex + rows - 2;

    for (size_t i = 0; i < rows; i++)
        for (size_t j = 0; j < cols; j++)
        {
            if (i < overflow)
                result[i][j] = (*this)[i][colIndex + j];
            else
                result[i][j] = (*this)[rowIndex + i - overflow][colIndex + j];
        }
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

Matrix3x3 &Matrix3x3::LoadIdentity(this Matrix3x3 &self)
{
    return self = Matrix3x3::Identity();
}

Matrix3x3 &Matrix3x3::Transpose(this Matrix3x3& self)
{
    return self = self.Transpose(self);
}

Matrix Matrix3x3::Augmented(this Matrix3x3& self, const Matrix3x3 &other)
{
    return self.Augmented(self, other);
}

Matrix3x3 &Matrix3x3::Inverse(this Matrix3x3& self)
{
    return self = self.Inverse(self);
}

Matrix3x3 Matrix3x3::Transpose(const Matrix3x3& matrix)
{
    return {
        { matrix.r0.x, matrix.r1.x, matrix.r2.x },
        { matrix.r0.y, matrix.r1.y, matrix.r2.y },
        { matrix.r0.z, matrix.r1.z, matrix.r2.z }
    };
}

Matrix Matrix3x3::Augmented(const Matrix3x3 &m1, const Matrix3x3 &m2)
{
    Matrix result(2, 4);

    for (size_t i = 0; i < 2; i++)
    {
        for (size_t j = 0; j < 2; j++)
            result[i][j] = m1[i][j];
        for (size_t j = 0; j < 2; j++)
            result[i][2 + j] = m2[i][j];
    }

    return result;
}

Matrix3x3 Matrix3x3::Inverse(const Matrix3x3 &matrix)
{
    if (matrix.Determinant() == 0) [[unlikely]]
        throw std::invalid_argument("Matrix3x3 isn't inversible");
    else [[likely]]
    {
        Matrix gaussJordan = Matrix::GaussJordan(Matrix3x3::Augmented(matrix, Matrix3x3::Identity()));
        Matrix3x3 right = (Matrix3x3) gaussJordan.SubMatrix(0, 2, 2, 2);

        return right;
    }
}
constexpr const Vector3 &Matrix3x3::operator[](const size_t row) const
{
    assert(row < 2 && "Cannot access Matrix3x3 row out of bounds");
    __assume(row < 2);

    return (&r0)[row];
}
constexpr Vector3 &Matrix3x3::operator[](const size_t row)
{
    assert(row < 2 && "Cannot access Matrix3x3 row out of bounds");
    __assume(row < 2);

    return (&r0)[row];
}
#pragma endregion

#pragma region operators
Matrix3x3::operator Vector2() const
{
    return Vector2(r0.x, r1.x);
}

Matrix3x3::operator Vector3() const
{
    return Vector3(r0.x, r1.x, r2.x);
}

Matrix3x3::operator Vector() const
{
    return { r0.x, r1.x, r2.x };
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

Matrix3x3::operator Matrix() const
{
    return {
        { r0.x, r0.y, r0.z },
        { r1.x, r1.y, r1.z },
        { r2.x, r2.y, r2.z }
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

    for (size_t i = 0; i < 2; i++)
        for (size_t j = 0; j < 2; j++)
            for (size_t k = 0; k < 2; k++)
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
