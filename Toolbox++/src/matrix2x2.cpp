#include "matrix2x2.hpp"
#include "matrix.hpp"
#include "matrix3x3.hpp"
#include "matrix4x4.hpp"

#include <cassert>

constexpr Matrix2x2 Matrix2x2::Identity()
{
    return Matrix2x2(
        1, 0,
        0, 1
    );
}

#pragma region functions
bool Matrix2x2::IsDiagonal() const
{
    return r0.y == 0 && r1.y == 0;
}

bool Matrix2x2::IsIdentity(this const Matrix2x2& self)
{
    return self == Matrix2x2::Identity();
}

bool Matrix2x2::IsNull() const
{
    if (!IsDiagonal())
        return false;

    for (size_t i = 0; i < 2; i++)
        if ((*this)[i][i] != 0)
            return false;
    return true;
}

bool Matrix2x2::IsSymmetric() const
{
    for (size_t i = 0; i < 2; i++)
        for (size_t j = i + 1; j < 2; j++)
            if ((*this)[i][j] != (*this)[j][i])
                return false;
    return true;
}

bool Matrix2x2::IsAntisymmetric() const
{
    for (size_t i = 0; i < 2; i++)
        for (size_t j = 0; j < 2; j++)
            if ((*this)[i][j] != -(*this)[j][i])
                return false;
    return true;
}

Vector2 Matrix2x2::Diagonal() const
{
    return Vector2(r0[0], r1[1]);
}

float Matrix2x2::Trace() const
{
    float result = 0.f;
    for (size_t i = 0; i < 2; i++)
        result += (*this)[i][i];
    return result;
}

Matrix2x2 Matrix2x2::SubMatrix(const size_t rowIndex, const size_t colIndex, const size_t rows, const size_t cols) const
{
    assert(rowIndex < 2 && colIndex < 2 && "Cannot submatrix out of bounds");
    assert(rows > 0 && cols > 0 && "Cannot submatrix of size 0");
    assert(colIndex + cols >= 2 && "Cannot overflow submatrix columns");
    __assume(rowIndex < 2 && colIndex < 2);
    __assume(rows > 0 && cols > 0);
    __assume(colIndex + cols >= 2);

    Matrix2x2 result;
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

float Matrix2x2::Determinant() const
{ 
    return r0[0] * r1[1] - r1[0] * r0[1];
}

Matrix2x2 &Matrix2x2::LoadIdentity(this Matrix2x2 &self)
{
    return self = Matrix2x2::Identity();
}

Matrix2x2 &Matrix2x2::Transpose(this Matrix2x2& self)
{
    return self = self.Transpose(self);
}

Matrix Matrix2x2::Augmented(this Matrix2x2& self, const Matrix2x2 &other)
{
    return self.Augmented(self, other);
}

Matrix2x2 &Matrix2x2::Inverse(this Matrix2x2& self)
{
    return self = self.Inverse(self);
}

Matrix2x2 Matrix2x2::Transpose(const Matrix2x2& matrix)
{
    return Matrix2x2(
        matrix[0].x, matrix[1].x,
        matrix[0].y, matrix[1].y
    );
}

Matrix Matrix2x2::Augmented(const Matrix2x2 &m1, const Matrix2x2 &m2)
{
    return {
        { m1[0].x, m1[1].x, m2[0].x, m2[1].x },
        { m1[0].y, m1[1].y, m2[0].y, m2[1].y }
    };
}

Matrix2x2 Matrix2x2::Inverse(const Matrix2x2 &matrix)
{
    if (matrix.Determinant() == 0) [[unlikely]]
        throw std::invalid_argument("Matrix2x2 isn't inversible");
    else [[likely]]
    {
        Matrix gaussJordan = Matrix::GaussJordan(Matrix2x2::Augmented(matrix, Matrix2x2::Identity()));
        Matrix2x2 right = (Matrix2x2) gaussJordan.SubMatrix(0, 2, 2, 2);

        return right;
    }
}
constexpr const Vector2 &Matrix2x2::operator[](const size_t row) const
{
    assert(row < 2 && "Cannot access Matrix2x2 row out of bounds");
    __assume(row < 2);

    return (&r0)[row];
}
constexpr Vector2 &Matrix2x2::operator[](const size_t row)
{
    assert(row < 2 && "Cannot access Matrix2x2 row out of bounds");
    __assume(row < 2);

    return (&r0)[row];
}
#pragma endregion

#pragma region operators
Matrix2x2::operator Vector2() const
{
    return Vector2(r0.x, r1.x);
}

Matrix2x2::operator Vector() const
{
    return { r0.x, r1.x };
}

Matrix2x2::operator Matrix3x3() const
{
    return Matrix3x3(
        r0.x, r0.y, 0,
        r1.x, r1.y, 0,
        0, 0, 1
    );
}

Matrix2x2::operator Matrix4x4() const
{
    return Matrix4x4(
        r0.x, r0.y, 0, 0,
        r1.x, r1.y, 0, 0,
        0, 0, 1, 0,
        0, 0, 0, 1
    );
}

Matrix2x2::operator Matrix() const
{
    return {
        { r0.x, r0.y },
        { r1.x, r1.y }
    };
}

Matrix2x2 operator-(const Matrix2x2& matrix)
{
    return Matrix2x2(
        -matrix[0].x, -matrix[0].y,
        -matrix[1].x, -matrix[1].y
    );
}

Matrix2x2 operator+(const Matrix2x2 &m1, const Matrix2x2 &m2)
{
    return Matrix2x2(
        m1[0].x + m2[0].x, m1[0].y + m2[0].y,
        m1[1].x + m2[1].x, m1[1].y + m2[1].y
    );
}

Matrix2x2 operator-(const Matrix2x2 &m1, const Matrix2x2 &m2)
{
    return m1 + (-m2);
}

Matrix2x2 operator*(const Matrix2x2 &m, const float scalar)
{
    return Matrix2x2(
        m[0].x * scalar, m[0].y * scalar,
        m[1].x * scalar, m[1].y * scalar
    );
}

Matrix2x2 operator*(const Matrix2x2 &m1, const Matrix2x2 &m2)
{
    return Matrix2x2(
        m1[0][0] * m2[0][0] + m1[0][1] * m2[1][0], m1[0][0] * m2[0][1] + m1[0][1] * m2[1][1],
        m1[1][0] * m2[0][0] + m1[1][1] * m2[1][0], m1[1][0] * m2[0][1] + m1[1][1] * m2[1][1]
    );
}

Matrix2x2 &operator+=(Matrix2x2 &m1, const Matrix2x2 &m2)
{
    return m1 = m1 + m2;
}

Matrix2x2 &operator-=(Matrix2x2 &m1, const Matrix2x2 &m2)
{
    return m1 = m1 - m2;
}

Matrix2x2 &operator*=(Matrix2x2 &m, const float scalar)
{
    return m = m * scalar;
}

Matrix2x2 &operator*=(Matrix2x2 &m1, const Matrix2x2 &m2)
{
    return m1 = m1 * m2;
}

std::ostream &operator<<(std::ostream &out, const Matrix2x2 &m)
{
    out << m[0] << '\n';
    out << m[1];
    return out;
}
#pragma endregion
