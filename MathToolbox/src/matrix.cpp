#include "matrix.hpp"

#include <cassert>

#include "calc.hpp"
#include "quaternion.hpp"
#include "vector3.hpp"

Matrix Matrix::Identity()
{
    return Matrix(
        1.f, 0.f, 0.f, 0.f,
        0.f, 1.f, 0.f, 0.f,
        0.f, 0.f, 1.f, 0.f,
        0.f, 0.f, 0.f, 1.f
    );
}

bool Matrix::IsDiagonal() const
{
    for (size_t i = 0; i < 4; i++)
    {
        for (size_t j = 0; j < 4; j++)
        {
            if (i != j && !calc::Equals((*this)[i][j], 0))
                return false;
        }
    }
    
    return true;
}

bool Matrix::IsIdentity() const
{
    if (!IsDiagonal())
        return false;

    for (size_t i = 0; i < 4; i++)
    {
        if (!calc::Equals((*this)[i][i], 1))
            return false;
    }
    
    return true;
}

bool Matrix::IsNull() const
{
    if (!IsDiagonal())
        return false;

    for (size_t i = 0; i < 4; i++)
    {
        if (!calc::Equals((*this)[i][i], 0))
            return false;
    }
    
    return true;
}

bool Matrix::IsSymmetric() const
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

bool Matrix::IsAntisymmetric() const
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

Vector4 Matrix::Diagonal() const
{
    return Vector4(r0[0], r1[1], r2[2], r3[3]);
}

float Matrix::Trace() const
{
    float result = 0.f;
    
    for (size_t i = 0; i < 4; i++)
        result += (*this)[i][i];
    
    return result;
}

float Matrix::Determinant() const
{ 
    // Definition from MonoGame/XNA: https://github.com/MonoGame/MonoGame/blob/b30122c99597eaf81b81f32ab1d467a7b4185c73/MonoGame.Framework/Matrix.cs
    
    const float num22 = (*this)[0][0];
    const float num21 = (*this)[0][1];
    const float num20 = (*this)[0][2];
    const float num19 = (*this)[0][3];
    const float num12 = (*this)[1][0];
    const float num11 = (*this)[1][1];
    const float num10 = (*this)[1][2];
    const float num9 = (*this)[1][3];
    const float num8 = (*this)[2][0];
    const float num7 = (*this)[2][1];
    const float num6 = (*this)[2][2];
    const float num5 = (*this)[2][3];
    const float num4 = (*this)[3][0];
    const float num3 = (*this)[3][1];
    const float num2 = (*this)[3][2];
    const float num = (*this)[3][3];
    
    const float num18 = (num6 * num) - (num5 * num2);
    const float num17 = (num7 * num) - (num5 * num3);
    const float num16 = (num7 * num2) - (num6 * num3);
    const float num15 = (num8 * num) - (num5 * num4);
    const float num14 = (num8 * num2) - (num6 * num4);
    const float num13 = (num8 * num3) - (num7 * num4);
    
    return ((((num22 * (((num11 * num18) - (num10 * num17)) + (num9 * num16))) - (num21 * (((num12 * num18) - (num10 * num15)) + (num9 * num14)))) + (num20 * (((num12 * num17) - (num11 * num15)) + (num9 * num13)))) - (num19 * (((num12 * num16) - (num11 * num14)) + (num10 * num13))));
}

Matrix &Matrix::LoadIdentity()
{
    return *this = Identity();
}

Matrix &Matrix::Transpose()
{
    return *this = Transpose(*this);
}

Matrix &Matrix::Invert()
{
    return *this = Invert(*this);
}

Matrix Matrix::Transpose(const Matrix& matrix)
{
    return Matrix(
        matrix.r0.x, matrix.r1.x, matrix.r2.x, matrix.r3.x,
        matrix.r0.y, matrix.r1.y, matrix.r2.y, matrix.r3.y,
        matrix.r0.z, matrix.r1.z, matrix.r2.z, matrix.r3.z,
        matrix.r0.w, matrix.r1.w, matrix.r2.w, matrix.r3.w
    );
}

Matrix Matrix::Invert(const Matrix &matrix)
{
    if (matrix.Determinant() == 0.f) [[unlikely]]
        throw std::invalid_argument("Matrix isn't invertible");
    else [[likely]]
    {
        // Definition from MonoGame/XNA: https://github.com/MonoGame/MonoGame/blob/b30122c99597eaf81b81f32ab1d467a7b4185c73/MonoGame.Framework/Matrix.cs
        Matrix result;
        
        const float num1 = matrix[0][0];
		const float num2 = matrix[0][1];
		const float num3 = matrix[0][2];
		const float num4 = matrix[0][3];
		const float num5 = matrix[1][0];
		const float num6 = matrix[1][1];
		const float num7 = matrix[1][2];
		const float num8 = matrix[1][3];
		const float num9 = matrix[2][0];
		const float num10 = matrix[2][1];
		const float num11 = matrix[2][2];
		const float num12 = matrix[2][3];
		const float num13 = matrix[3][0];
		const float num14 = matrix[3][1];
		const float num15 = matrix[3][2];
		const float num16 = matrix[3][3];
        
		const float num17 = (num11 * num16 - num12 * num15);
		const float num18 = (num10 * num16 - num12 * num14);
		const float num19 = (num10 * num15 - num11 * num14);
		const float num20 = (num9 * num16 - num12 * num13);
		const float num21 = (num9 * num15 - num11 * num13);
		const float num22 = (num9 * num14 - num10 * num13);
		const float num23 = (num6 * num17 - num7 * num18 + num8 * num19);
		const float num24 = -(num5 * num17 - num7 * num20 + num8 * num21);
		const float num25 = (num5 * num18 - num6 * num20 + num8 * num22);
		const float num26 = -(num5 * num19 - num6 * num21 + num7 * num22);
		const float num27 = (1.f / (num1 * num23 + num2 * num24 + num3 * num25 + num4 * num26));
		
		result[0][0] = num23 * num27;
		result[1][0] = num24 * num27;
		result[2][0] = num25 * num27;
		result[3][0] = num26 * num27;
        
		result[0][1] = -(num2 * num17 - num3 * num18 + num4 * num19) * num27;
		result[1][1] = (num1 * num17 - num3 * num20 + num4 * num21) * num27;
		result[2][1] = -(num1 * num18 - num2 * num20 + num4 * num22) * num27;
		result[3][1] = (num1 * num19 - num2 * num21 + num3 * num22) * num27;
        
		const float num28 = (num7 * num16 - num8 * num15);
		const float num29 = (num6 * num16 - num8 * num14);
		const float num30 = (num6 * num15 - num7 * num14);
		const float num31 = (num5 * num16 - num8 * num13);
		const float num32 = (num5 * num15 - num7 * num13);
		const float num33 = (num5 * num14 - num6 * num13);
        
		result[0][2] = (num2 * num28 - num3 * num29 + num4 * num30) * num27;
		result[1][2] = -(num1 * num28 - num3 * num31 + num4 * num32) * num27;
		result[2][2] = (num1 * num29 - num2 * num31 + num4 * num33) * num27;
		result[3][2] = -(num1 * num30 - num2 * num32 + num3 * num33) * num27;
        
		const float num34 = (num7 * num12 - num8 * num11);
		const float num35 = (num6 * num12 - num8 * num10);
		const float num36 = (num6 * num11 - num7 * num10);
		const float num37 = (num5 * num12 - num8 * num9);
		const float num38 = (num5 * num11 - num7 * num9);
		const float num39 = (num5 * num10 - num6 * num9);
        
		result[0][3] = -(num2 * num34 - num3 * num35 + num4 * num36) * num27;
		result[1][3] = (num1 * num34 - num3 * num37 + num4 * num38) * num27;
		result[2][3] = -(num1 * num35 - num2 * num37 + num4 * num39) * num27;
		result[3][3] = (num1 * num36 - num2 * num38 + num3 * num39) * num27;

        return result;
    }
}

Matrix Matrix::Translation3D(const Vector3 &translation)
{
    return Matrix(
        1, 0, 0, translation.x,
        0, 1, 0, translation.y,
        0, 0, 1, translation.z,
        0, 0, 0, 1
    );
}

Matrix Matrix::Rotation3D(const float angle, const Vector3 &axis)
{
    return Rotation3D(std::cos(angle), std::sin(angle), axis);
}

Matrix Matrix::Rotation3DX(const float angle)
{
    return Rotation3DX(std::cos(angle), std::sin(angle));
}

Matrix Matrix::Rotation3DX(const float cos, const float sin)
{
    return Matrix(
        1,    0,     0, 0.f,
        0,  cos,  -sin, 0.f,
        0,  sin,   cos, 0.f,
        0.f, 0.f, 0.f, 1.f
    );
}

Matrix Matrix::Rotation3DY(const float angle)
{
    return Rotation3DY(std::cos(angle), std::sin(angle));
}

Matrix Matrix::Rotation3DY(const float cos, const float sin)
{
    return Matrix(
         cos,  0,  sin, 0.f,
           0,  1,    0, 0.f,
        -sin,  0,  cos, 0.f,
        0.f, 0.f, 0.f, 1.f
    );
}

Matrix Matrix::Rotation3DZ(const float angle)
{
    return Rotation3DZ(std::cos(angle), std::sin(angle));
}

Matrix Matrix::Rotation3DZ(const float cos, const float sin)
{
    return Matrix(
        cos, -sin,  0, 0.f,
        sin,  cos,  0, 0.f,
          0,    0,  1, 0.f,
          0.f, 0.f, 0.f, 1.f
    );
}

Matrix Matrix::Rotation3D(const Vector3 &rotation)
{
    return Matrix::Rotation3DZ(rotation.z)
         * Matrix::Rotation3DY(rotation.y)
         * Matrix::Rotation3DX(rotation.x);
}

Matrix Matrix::Rotation3D(const Quaternion& rotation)
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

    Matrix result;

    result[0] = Vector4(
        1.f - 2.f * (yy + zz),
        2.f * (xy - wz),
        2.f * (xz + wy),
        0.f
    );
    result[1] = Vector4(
        2.f * (xy + wz),
        1.f - 2.f * (zz + xx),
        2.f * (yz - wx),
        0.f
    );
    result[2] = Vector4(
        2.f * (xz - wy),
        2.f * (yz + wx),
        1.f - 2.f * (yy + xx),
        0.f
    );
    result[3][3] = 1.f;

    return result;
}

Matrix Matrix::Rotation3D(const float cos, const float sin, const Vector3 &axis)
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

Matrix Matrix::Scaling3D(const Vector3 &scale)
{
    return Matrix(
        scale.x,       0.f,     0.f, 0.f,
              0.f, scale.y,     0.f, 0.f,
              0.f,     0.f, scale.z, 0.f,
              0.f,     0.f,     0.f, 1.f
    );
}

Matrix Matrix::Trs(const Vector3 &translation, const Vector3 &rotation, const Vector3 &scale)
{
    return Trs(translation, Matrix::Rotation3D(rotation), scale);
}

Matrix Matrix::Trs(const Vector3 &translation, const float rotationAngle, const Vector3& axis, const Vector3 &scale)
{
    return Trs(translation, Matrix::Rotation3D(rotationAngle, axis), scale);
}

Matrix Matrix::Trs(const Vector3& translation, const Matrix& rotation, const Vector3& scale)
{
    Matrix result = Identity();

    result[0][3] = translation.x;
    result[1][3] = translation.y;
    result[2][3] = translation.z;

    return result * rotation * Matrix::Scaling3D(scale);
}

Matrix Matrix::Trs(const Vector3& translation, const Quaternion& rotation, const Vector3& scale)
{
    return Trs(translation, Matrix::Rotation3D(rotation), scale);
}

void Matrix::View(const Vector3 &eye, const Vector3 &center, const Vector3 &up, Matrix &result)
{
    const Vector3 cameraForward = -(eye - center).Normalized();
    const Vector3 cameraRight = Vector3::Cross(up, cameraForward).Normalized();
    const Vector3 cameraUp = Vector3::Cross(cameraForward, cameraRight);
    
    result = Matrix(
        cameraRight.x, cameraRight.y, cameraRight.z, 0,
        cameraUp.x, cameraUp.y, cameraUp.z, 0,
        cameraForward.x, cameraForward.y, cameraForward.z, 0,
        0, 0, 0, 1
    ) * Translation3D(-eye);
}

void Matrix::PerspectiveProjection(const float fov, const float ar, const float near, const float far, Matrix &result)
{
    assert(near < far && "Near must be smaller than far.");

    const float range = near - far;
    const float tanHalfFov = std::tan(fov / 2);

    result = Matrix(
        1 / (tanHalfFov * ar), 0, 0, 0,
        0, 1 / tanHalfFov, 0, 0,
        0, 0, (-near - far) / range, 2 * far * near / range,
        0, 0, 1, 0
    );
}

void Matrix::OrthographicProjection(const float l, const float r, const float b, const float t, const float n, const float f, Matrix& result)
{
    assert(n < f && "Near must be smaller than far.");

    result = Matrix(
        2.f / (r - l), 0.f, 0.f, -((r + l) / (r - l)),
        0.f, 2.f / (t - b), 0.f, -((t + b) / (t - b)),
        0.f, 0.f, -2.f / (f - n), -((f + n) / (f - n)),
        0.f, 0.f, 0.f, 1.f
    );
}

constexpr Matrix::Matrix(const float defaultValue)
    : r0(defaultValue)
    , r1(defaultValue)
    , r2(defaultValue)
    , r3(defaultValue)
{
}

constexpr Matrix::Matrix(const Vector4& r0, const Vector4& r1, const Vector4& r2, const Vector4& r3)
    : r0(r0)
    , r1(r1)
    , r2(r2)
    , r3(r3)
{
}

constexpr Matrix::Matrix(
    const float r00, const float r01, const float r02, const float r03,
    const float r10, const float r11, const float r12, const float r13,
    const float r20, const float r21, const float r22, const float r23,
    const float r30, const float r31, const float r32, const float r33
)
    : r0(r00, r01, r02, r03)
    , r1(r10, r11, r12, r13)
    , r2(r20, r21, r22, r23)
    , r3(r30, r31, r32, r33)
{
}

constexpr const float* Matrix::Raw() const
{
    return &r0.x;
}

constexpr float* Matrix::Raw()
{
    return &r0.x;
}

constexpr const Vector4 &Matrix::operator[](const size_t row) const
{
    return (&r0)[row];
}

constexpr Vector4 &Matrix::operator[](const size_t row)
{
    return (&r0)[row];
}

Matrix::operator Vector4() const
{
    return Vector4(r0.x, r1.x, r2.x, r3.x);
}

Matrix operator-(const Matrix& matrix)
{
    Matrix result = matrix;
    for (size_t i = 0; i < 4; i++)
        result[i] = -matrix[i];
    return result;
}

Matrix operator+(const Matrix &m1, const Matrix &m2)
{
    Matrix result;
    for (size_t i = 0; i < 4; i++)
        result[i] = m1[i] + m2[i];
    return result;
}

Matrix operator-(const Matrix &m1, const Matrix &m2)
{
    return m1 + (-m2);
}

Matrix operator*(const Matrix &m, const float scalar)
{
    Matrix result;
    for (size_t i = 0; i < 4; i++)
        for (size_t j = 0; j < 4; j++)
            result[i][j] = m[i][j] * scalar;
    return result;
}

Matrix operator*(const Matrix &m1, const Matrix &m2)
{
    Matrix result;

    for (size_t i = 0; i < 4; i++)
        for (size_t j = 0; j < 4; j++)
            for (size_t k = 0; k < 4; k++)
                result[i][j] += m1[i][k] * m2[k][j];
    return result;
}

Matrix &operator+=(Matrix &m1, const Matrix &m2)
{
    return m1 = m1 + m2;
}

Matrix &operator-=(Matrix &m1, const Matrix &m2)
{
    return m1 = m1 - m2;
}

Matrix &operator*=(Matrix &m, const float scalar)
{
    return m = m * scalar;
}

Matrix &operator*=(Matrix &m1, const Matrix &m2)
{
    return m1 = m1 * m2;
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
