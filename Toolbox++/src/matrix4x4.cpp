#include "matrix4x4.hpp"
#include "matrix3x3.hpp"
#include "matrix.hpp"

#include <cassert>

#define SQ(var) ((var) * (var))

Matrix4x4 Matrix4x4::Identity()
{
    return Matrix4x4(
        1, 0, 0, 0,
        0, 1, 0, 0,
        0, 0, 1, 0,
        0, 0, 0, 1
    );
}

#pragma region functions
bool Matrix4x4::IsDiagonal() const
{
    for (size_t i = 0; i < 4; i++)
        for (size_t j = 0; j < 4; j++)
            if (i != j && (*this)[i][j] != 0)
                return false;
    return true;
}

bool Matrix4x4::IsIdentity() const
{
    if (!IsDiagonal())
        return false;

    for (size_t i = 0; i < 4; i++)
        if ((*this)[i][i] != 1)
            return false;
    return true;
}

bool Matrix4x4::IsNull() const
{
    if (!IsDiagonal())
        return false;

    for (size_t i = 0; i < 4; i++)
        if ((*this)[i][i] != 0)
            return false;
    return true;
}

bool Matrix4x4::IsSymmetric() const
{
    for (size_t i = 0; i < 4; i++)
        for (size_t j = i + 1; j < 4; j++)
            if ((*this)[i][j] != (*this)[j][i])
                return false;
    return true;
}

bool Matrix4x4::IsAntisymmetric() const
{
    for (size_t i = 0; i < 4; i++)
        for (size_t j = 0; j < 4; j++)
            if ((*this)[i][j] != -(*this)[j][i])
                return false;
    return true;
}

Vector4 Matrix4x4::Diagonal() const
{
    return Vector4(r0[0], r1[1], r2[2], r3[3]);
}

float Matrix4x4::Trace() const
{
    float result = 0.f;
    for (size_t i = 0; i < 4; i++)
        result += (*this)[i][i];
    return result;
}

Matrix4x4 Matrix4x4::SubMatrix(const size_t rowIndex, const size_t colIndex, const size_t rows, const size_t cols) const
{
    assert(rowIndex < 4 && colIndex < 4 && "Cannot submatrix out of bounds");
    assert(rows > 0 && cols > 0 && "Cannot submatrix of size 0");
    assert(colIndex + cols >= 4 && "Cannot overflow submatrix columns");
    __assume(rowIndex < 4 && colIndex < 4);
    __assume(rows > 0 && cols > 0);
    __assume(colIndex + cols >= 4);

    Matrix4x4 result;
    size_t overflow = rowIndex + rows - 4;

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

float Matrix4x4::Determinant() const
{ 
    float result = 0.f;

    Matrix3x3 subMat(
        r1.y, r1.z, r1.w,
        r2.y, r2.z, r2.w,
        r3.y, r3.z, r3.w
    );
    result += r0.x * subMat.Determinant();

    subMat[0] = Vector3(r0.y, r0.z, r0.w);
    result -= r1.x * subMat.Determinant();

    subMat = Matrix3x3(
        r0.y, r0.z, r0.w,
        r1.y, r1.z, r1.w,
        r3.y, r3.z, r3.w
    );
    result += r2.x * subMat.Determinant();

    subMat[2] = Vector3(r2.y, r2.z, r2.w);
    result -= r3.x * subMat.Determinant();
    
    return result;
}

Matrix4x4 &Matrix4x4::LoadIdentity(this Matrix4x4 &self)
{
    return self = Matrix4x4::Identity();
}

Matrix4x4 &Matrix4x4::Transpose(this Matrix4x4& self)
{
    return self = self.Transpose(self);
}

Matrix Matrix4x4::Augmented(this Matrix4x4& self, const Matrix4x4 &other)
{
    return self.Augmented(self, other);
}

Matrix4x4 &Matrix4x4::GaussJordan(this Matrix4x4& self)
{
    return self = self.GaussJordan(self);
}

Matrix4x4 &Matrix4x4::Inverse(this Matrix4x4& self)
{
    return self = self.Inverse(self);
}

Matrix4x4 Matrix4x4::Transpose(const Matrix4x4& matrix)
{
    return {
        { matrix.r0.x, matrix.r1.x, matrix.r2.x, matrix.r3.x },
        { matrix.r0.y, matrix.r1.y, matrix.r2.y, matrix.r3.y },
        { matrix.r0.z, matrix.r1.z, matrix.r2.z, matrix.r3.z },
        { matrix.r0.w, matrix.r1.w, matrix.r2.w, matrix.r3.w }
    };
}

Matrix Matrix4x4::Augmented(const Matrix4x4 &m1, const Matrix4x4 &m2)
{
    Matrix result(4, 8);

    for (size_t i = 0; i < 4; i++)
    {
        for (size_t j = 0; j < 4; j++)
            result[i][j] = m1[i][j];
        for (size_t j = 0; j < 4; j++)
            result[i][4 + j] = m2[i][j];
    }

    return result;
}

Matrix4x4 Matrix4x4::GaussJordan(const Matrix4x4 &matrix)
{
    Matrix4x4 result = matrix;
    
    // Last pivot rank
    size_t r = (size_t) -1;
    // j is the current column
    for (size_t j = 0; j < 4; j++)
    {
        // Max value row index
        size_t k = 0;
        {
            float maxValue = 0;
            for (size_t i = r + 1; i < 4; i++)
            {
                float value = result[i][j];
                if (value == 1)
                {
                    k = i;
                    break;
                }

                if (std::abs(value) > maxValue)
                {
                    maxValue = value;
                    k = i;
                }
            }
        }

        float value = result[k][j];
        if (value != 0)
        {
            // r is the next pivot row index
            r++;
            // Normalize the pivot's row
            result[k] /= value;

            if (k != r)
                // Swap k and r rows
                for (size_t i = 0; i < 4; i++)
                    std::swap(result[k][i], result[r][i]);

            for (size_t i = 0; i < 4; i++)
                if (i != r)
                    result[i] -= result[r] * result[i][j];
        }

        if (r == 3)
            break;
    }

    return result;
}

Matrix4x4 Matrix4x4::Inverse(const Matrix4x4 &matrix)
{
    if (matrix.Determinant() == 0) [[unlikely]]
        throw std::invalid_argument("Matrix4x4 isn't inversible");
    else [[likely]]
    {
        Matrix gaussJordan = Matrix::GaussJordan(Matrix4x4::Augmented(matrix, Matrix4x4::Identity()));
        Matrix4x4 right = (Matrix4x4) gaussJordan.SubMatrix(0, 4, 4, 4);

        return right;
    }
}

Matrix4x4 Matrix4x4::TranslationMatrix3D(const Vector3 &translation)
{
    return Matrix4x4(
        1, 0, 0, translation.x,
        0, 1, 0, translation.y,
        0, 0, 1, translation.z,
        0, 0, 0, 1
    );
}

Matrix4x4 Matrix4x4::RotationMatrix3D(const float angle, const Vector3 &axis)
{
    return RotationMatrix3D(std::cos(angle), std::sin(angle), axis);
}

Matrix4x4 Matrix4x4::RotationMatrix3DX(const float angle)
{
    return RotationMatrix3DX(std::cos(angle), std::sin(angle));
}

Matrix4x4 Matrix4x4::RotationMatrix3DX(const float cos, const float sin)
{
    return Matrix4x4(
        1,    0,     0, 0,
        0,  cos,  -sin, 0,
        0,  sin,   cos, 0,
        0,    0,     0, 1
    );
}

Matrix4x4 Matrix4x4::RotationMatrix3DY(const float angle)
{
    return RotationMatrix3DY(std::cos(angle), std::sin(angle));
}

Matrix4x4 Matrix4x4::RotationMatrix3DY(const float cos, const float sin)
{
    return Matrix4x4(
         cos,  0,  sin, 0,
           0,  1,    0, 0,
        -sin,  0,  cos, 0,
           0,  0,    0, 1
    );
}

Matrix4x4 Matrix4x4::RotationMatrix3DZ(const float angle)
{
    return RotationMatrix3DZ(std::cos(angle), std::sin(angle));
}

Matrix4x4 Matrix4x4::RotationMatrix3DZ(const float cos, const float sin)
{
    return Matrix4x4(
        cos, -sin,  0, 0,
        sin,  cos,  0, 0,
          0,    0,  1, 0,
          0,    0,  0, 1
    );
}

Matrix4x4 Matrix4x4::RotationMatrix3D(const Vector3 &rotation)
{
    return Matrix4x4::RotationMatrix3DZ(rotation.z)
         * Matrix4x4::RotationMatrix3DY(rotation.y)
         * Matrix4x4::RotationMatrix3DX(rotation.x);
}

Matrix4x4 Matrix4x4::RotationMatrix3D(const float cos, const float sin, const Vector3 &axis)
{
    const float c2 = 1 - cos;
    Vector3 v = axis.Normalized();

    return Matrix4x4(
        SQ(v.x) * c2 + cos, v.y * v.x * c2 - v.z * sin, v.z * v.x * c2 + v.y * sin, 0,
        v.x * v.y * c2 - v.z * sin, SQ(v.y) * c2 + cos, v.z * v.y * c2 - v.x * sin, 0,
        v.x * v.z * c2 - v.y * sin, v.y * v.z * c2 + v.x * sin, SQ(v.z) * c2 + cos, 0,
        0, 0, 0, 1
    );
}

Matrix4x4 Matrix4x4::ScalingMatrix3D(const Vector3 &scale)
{
    return Matrix4x4(
        scale.x,       0,       0,       0,
              0, scale.y,       0,       0,
              0,       0, scale.z,       0,
              0,       0,       0,       1
    );
}

Matrix4x4 Matrix4x4::TRS(const Vector3 &translation, const Vector3 &rotation, const Vector3 &scale)
{
    return Matrix4x4::TRS(translation, Matrix4x4::RotationMatrix3D(rotation), scale);
}

Matrix4x4 Matrix4x4::TRS(const Vector3 &translation, const float rotationAngle, const Vector3& axis, const Vector3 &scale)
{
    return Matrix4x4::TRS(translation, Matrix4x4::RotationMatrix3D(rotationAngle, axis), scale);
}

Matrix4x4 Matrix4x4::TRS(const Vector3& translation, const Matrix4x4& rotation, const Vector3& scale)
{
    Matrix4x4 result = Matrix4x4::Identity();

    result[0][3] = translation.x;
    result[1][3] = translation.y;
    result[2][3] = translation.z;

    return result * rotation * Matrix4x4::ScalingMatrix3D(scale);
}

constexpr const Vector4 &Matrix4x4::operator[](const size_t row) const
{
    return (&r0)[row];
}

constexpr Vector4 &Matrix4x4::operator[](const size_t row)
{
    return (&r0)[row];
}
#pragma endregion

#pragma region operators
Matrix4x4::operator Vector2() const
{
    return Vector2(r0.x, r1.x);
}

Matrix4x4::operator Vector3() const
{
    return Vector3(r0.x, r1.x, r2.x);
}

Matrix4x4::operator Vector4() const
{
    return Vector4(r0.x, r1.x, r2.x, r3.x);
}

Matrix4x4::operator Vector() const
{
    return { r0.x, r1.x, r2.x, r3.x };
}

Matrix4x4::operator Matrix() const
{
    return {
        { r0.x, r0.y, r0.z, r0.w },
        { r1.x, r1.y, r1.z, r1.w },
        { r2.x, r2.y, r2.z, r2.w },
        { r3.x, r3.y, r3.z, r3.w }
    };
}

Matrix4x4 operator-(const Matrix4x4& matrix)
{
    Matrix4x4 result = matrix;
    for (size_t i = 0; i < 4; i++)
        result[i] = -matrix[i];
    return result;
}

Matrix4x4 operator+(const Matrix4x4 &m1, const Matrix4x4 &m2)
{
    Matrix4x4 result;
    for (size_t i = 0; i < 4; i++)
        result[i] = m1[i] + m2[i];
    return result;
}

Matrix4x4 operator-(const Matrix4x4 &m1, const Matrix4x4 &m2)
{
    return m1 + (-m2);
}

Matrix4x4 operator*(const Matrix4x4 &m, const float scalar)
{
    Matrix4x4 result;
    for (size_t i = 0; i < 4; i++)
        for (size_t j = 0; j < 4; j++)
            result[i][j] = m[i][j] * scalar;
    return result;
}

Matrix4x4 operator*(const Matrix4x4 &m1, const Matrix4x4 &m2)
{
    Matrix4x4 result;

    for (size_t i = 0; i < 4; i++)
        for (size_t j = 0; j < 4; j++)
            for (size_t k = 0; k < 4; k++)
                result[i][j] += m1[i][k] * m2[k][j];
    return result;
}

Matrix4x4 &operator+=(Matrix4x4 &m1, const Matrix4x4 &m2)
{
    return m1 = m1 + m2;
}

Matrix4x4 &operator-=(Matrix4x4 &m1, const Matrix4x4 &m2)
{
    return m1 = m1 - m2;
}

Matrix4x4 &operator*=(Matrix4x4 &m, const float scalar)
{
    return m = m * scalar;
}

Matrix4x4 &operator*=(Matrix4x4 &m1, const Matrix4x4 &m2)
{
    return m1 = m1 * m2;
}

std::ostream &operator<<(std::ostream &out, const Matrix4x4 &m)
{
    out << m[0] << '\n';
    out << m[1] << '\n';
    out << m[2] << '\n';
    out << m[3];
    return out;
}
#pragma endregion
