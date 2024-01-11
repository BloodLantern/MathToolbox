#pragma once

#include <ostream>
#include <cassert>

#include "quaternion.hpp"
#include "vector3.hpp"
#include "vector4.hpp"

class Vector2;

/// <summary>
/// The Matrix class represents a 4x4 array mainly used for mathematical operations.
/// Matrices are stored using the row-major convention.
/// </summary>
class Matrix
{
public:
    /// <summary>
    /// Returns the identity matrix.
    /// The identity matrix is a matrix with its diagonal
    /// set to one and everything else set to zero.
    /// </summary>
    [[nodiscard]]
    static constexpr Matrix Identity() noexcept;

    /// <summary>
    /// Creates a matrix with all its values set to 0.
    /// </summary>
    constexpr Matrix() = default;

    /// <summary>
    /// Creates a matrix with all its values set to this default value.
    /// </summary>
    explicit constexpr Matrix(const float defaultValue) noexcept;

    constexpr Matrix(
        const Vector4& r0,
        const Vector4& r1,
        const Vector4& r2,
        const Vector4& r3
    ) noexcept;

    constexpr Matrix(
        const float r00, const float r01, const float r02, const float r03,
        const float r10, const float r11, const float r12, const float r13,
        const float r20, const float r21, const float r22, const float r23,
        const float r30, const float r31, const float r32, const float r33
    ) noexcept;

    /// <summary>
    ///	Gets a pointer to the first value of this matrix.
    /// </summary>
    /// <returns>A pointer to the first value of this matrix.</returns>
    [[nodiscard]]
    constexpr const float* Raw() const noexcept;

    /// <summary>
    ///	Gets a pointer to the first value of this matrix.
    /// </summary>
    /// <returns>A pointer to the first value of this matrix.</returns>
    [[nodiscard]]
    constexpr float* Raw() noexcept;

    /// <summary>
    /// Returns whether the matrix has everything except its diagonal set to zero.
    /// </summary>
    [[nodiscard]]
    bool IsDiagonal() const noexcept;
    
    /// <summary>
    /// Returns whether the matrix is the identity matrix.
    /// If this returns true, Matrix::Identity() == *this should be true.
    /// </summary>
    [[nodiscard]]
    bool IsIdentity() const noexcept;
    
    /// <summary>
    /// Returns whether this matrix has everything set to zero.
    /// </summary>
    [[nodiscard]]
    bool IsNull() const noexcept;
    
    /// <summary>
    /// Returns whether the matrix is symmetric by its diagonal elements.
    /// </summary>
    [[nodiscard]]
    bool IsSymmetric() const noexcept;
    
    /// <summary>
    /// Returns whether the matrix is symmetric by its diagonal elements
    /// but one of the sides is the opposite of the other.
    /// </summary>
    [[nodiscard]]
    bool IsAntisymmetric() const noexcept;
    
    /// <summary>
    /// Returns the diagonal elements of the matrix.
    /// </summary>
    [[nodiscard]]
    constexpr Vector4 Diagonal() const noexcept;
    
    /// <summary>
    /// Returns the sum of the diagonal elements of the matrix.
    /// </summary>
    [[nodiscard]]
    constexpr float Trace() const noexcept;
    
    /// <summary>
    /// Returns the determinant of this matrix.
    /// </summary>
    [[nodiscard]]
    constexpr float Determinant() const noexcept;
    
    /// <summary>
    /// Sets this matrix to the identity matrix.
    /// </summary>
    constexpr Matrix& LoadIdentity() noexcept;
    
    /// <summary>
    /// Switches the matrix by its diagonal elements.
    /// </summary>
    constexpr Matrix& Transpose() noexcept;

    /// <summary>
    /// Computes the invert of this matrix, e.g. <code>*this * Invert() == Identity()</code> is true.
    /// </summary>
    constexpr Matrix& Invert();

    /// <summary>
    /// Switches the given matrix by its diagonal elements.
    /// </summary>
    [[nodiscard]]
    static constexpr Matrix Transpose(const Matrix& matrix) noexcept;
    
    /// <summary>
    /// Computes the inversion of the given matrix, e.g. <code>*this * Invert() == Identity()</code> is true.
    /// </summary>
    [[nodiscard]]
    static constexpr Matrix Invert(const Matrix& matrix);
    
    /// <summary>
    /// Creates a 3D translation matrix from the given angle for each of the x, y, and z axis.
    /// </summary>
    [[nodiscard]]
    static constexpr Matrix Translation3D(const Vector3& translation) noexcept;
    
    /// <summary>
    /// Creates a 3D rotation matrix from the given angle and axis.
    /// </summary>
	/// <param name="angle">The angle in radians.</param>
    [[nodiscard]]
    static Matrix Rotation3D(float angle, const Vector3& axis) noexcept;
    
    /// <summary>
    /// Creates a 3D rotation matrix around the X axis from the given angle.
    /// </summary>
    /// <param name="angle">The angle in radians.</param>
    [[nodiscard]]
    static Matrix Rotation3DX(float angle) noexcept;
    
    /// <summary>
    /// Creates a 3D rotation matrix around the X axis from the given angle.
    /// </summary>
    /// <param name="cos">The cosine of the angle in radians.</param>
    /// <param name="sin">The sine of the angle in radians.</param>
    [[nodiscard]]
    static constexpr Matrix Rotation3DX(float cos, float sin) noexcept;
    
    /// <summary>
    /// Creates a 3D rotation matrix around the Y axis from the given angle.
    /// </summary>
    /// <param name="angle">The angle in radians.</param>
    [[nodiscard]]
    static Matrix Rotation3DY(float angle) noexcept;
    
    /// <summary>
    /// Creates a 3D rotation matrix around the Y axis from the given angle.
    /// </summary>
    /// <param name="cos">The cosine of the angle in radians.</param>
    /// <param name="sin">The sine of the angle in radians.</param>
    [[nodiscard]]
    static constexpr Matrix Rotation3DY(float cos, float sin) noexcept;
    
    /// <summary>
    /// Creates a 3D rotation matrix around the Z axis from the given angle.
    /// </summary>
    /// <param name="angle">The angle in radians.</param>
    [[nodiscard]]
    static Matrix Rotation3DZ(float angle) noexcept;
    
    /// <summary>
    /// Creates a 3D rotation matrix around the Z axis from the given angle.
    /// </summary>
    /// <param name="cos">The cosine of the angle in radians.</param>
    /// <param name="sin">The sine of the angle in radians.</param>
    [[nodiscard]]
    static constexpr Matrix Rotation3DZ(float cos, float sin) noexcept;
    
    /// <summary>
    /// Creates a 3D rotation matrix from the given angle for each of the x, y, and z axis.
    /// </summary>
    [[nodiscard]]
    static Matrix Rotation3D(const Vector3& rotation) noexcept;
    
    [[nodiscard]]
    static constexpr Matrix Rotation3D(const Quaternion& rotation) noexcept;
    
    /// <summary>
    /// Creates a 3D rotation matrix from the given cosine, sine and axis.
    /// </summary>
	/// <param name="cos">The cosine of the angle in radians.</param>
	/// <param name="sin">The sine of the angle in radians.</param>
    [[nodiscard]]
    static Matrix Rotation3D(float cos, float sin, const Vector3& axis) noexcept;
    
    /// <summary>
    /// Creates a 3D scaling matrix from the given Vector3.
    /// </summary>
    [[nodiscard]]
    static constexpr Matrix Scaling3D(const Vector3& scale) noexcept;
    
    /// <summary>
    /// Creates a Translation-Rotation-Scaling (TRS) matrix from the given translation, rotation and scaling.
    /// </summary>
    [[nodiscard]]
    static Matrix Trs(const Vector3& translation, const Vector3& rotation, const Vector3& scale) noexcept;
    
    /// <summary>
    /// Creates a Translation-Rotation-Scaling (TRS) matrix from the given translation, rotation and scaling.
    /// </summary>
	/// <param name="rotationAngle">The angle in radians.</param>
    [[nodiscard]]
    static Matrix Trs(const Vector3& translation, float rotationAngle, const Vector3& axis, const Vector3& scale) noexcept;
    
    /// <summary>
    /// Creates a Translation-Rotation-Scaling (TRS) matrix from the given translation, rotation and scaling.
    /// </summary>
    [[nodiscard]]
    static constexpr Matrix Trs(const Vector3& translation, const Matrix& rotation, const Vector3& scale) noexcept;
    
    [[nodiscard]]
    static constexpr Matrix Trs(const Vector3& translation, const Quaternion& rotation, const Vector3& scale) noexcept;
    
    static void View(const Vector3& eye, const Vector3& center, const Vector3& up, Matrix& result) noexcept;
    
    static void PerspectiveProjection(float fov, float aspectRatio, float near, float far, Matrix& result);
    
    static constexpr void OrthographicProjection(float left, float right, float bottom, float top, float near, float far, Matrix& result);

    /// <summary>
    ///	Retrieves this matrix's row at index i.
    /// </summary>
    /// <param name="row">The index of the row to get.</param>
    /// <returns>The row at index i as a vector.</returns>
    [[nodiscard]]
    constexpr const Vector4& operator[](size_t row) const;
    
    /// <summary>
    ///	Retrieves this matrix's row at index i.
    /// </summary>
    /// <param name="row">The index of the row to get.</param>
    /// <returns>The row at index i as a vector.</returns>
    [[nodiscard]]
    constexpr Vector4& operator[](size_t row);
    
    explicit operator Vector4() const noexcept;

private:
    Vector4 r0, r1, r2, r3;
};

static_assert(std::is_default_constructible_v<Matrix>, "Class Matrix must be default constructible.");
static_assert(std::is_copy_constructible_v<Matrix>, "Class Matrix must be copy constructible.");
static_assert(std::is_move_constructible_v<Matrix>, "Class Matrix must be move constructible.");
static_assert(std::is_copy_assignable_v<Matrix>, "Class Matrix must be copy assignable.");
static_assert(std::is_move_assignable_v<Matrix>, "Class Matrix must be move assignable.");

constexpr Matrix::Matrix(const float defaultValue) noexcept
    : r0(defaultValue)
    , r1(defaultValue)
    , r2(defaultValue)
    , r3(defaultValue)
{
}

constexpr Matrix::Matrix(const Vector4& r0, const Vector4& r1, const Vector4& r2, const Vector4& r3) noexcept
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
) noexcept
    : r0(r00, r01, r02, r03)
    , r1(r10, r11, r12, r13)
    , r2(r20, r21, r22, r23)
    , r3(r30, r31, r32, r33)
{
}

constexpr Matrix Matrix::Identity() noexcept
{
    return Matrix(
        1.f, 0.f, 0.f, 0.f,
        0.f, 1.f, 0.f, 0.f,
        0.f, 0.f, 1.f, 0.f,
        0.f, 0.f, 0.f, 1.f
    );
}

constexpr const float* Matrix::Raw() const noexcept { return &r0.x; }

constexpr float* Matrix::Raw() noexcept { return &r0.x; }

constexpr Vector4 Matrix::Diagonal() const noexcept { return Vector4(r0[0], r1[1], r2[2], r3[3]); }

constexpr float Matrix::Trace() const noexcept
{
    float result = 0.f;
    
    for (size_t i = 0; i < 4; i++)
        result += (*this)[i][i];
    
    return result;
}

constexpr float Matrix::Determinant() const noexcept
{ 
    // Definition from MonoGame/XNA: https://github.com/MonoGame/MonoGame/blob/b30122c99597eaf81b81f32ab1d467a7b4185c73/MonoGame.Framework/Matrix.cs
    
    const float r00 = r0[0];
    const float r10 = r1[0];
    const float r20 = r2[0];
    const float r30 = r3[0];
    const float r01 = r0[1];
    const float r11 = r1[1];
    const float r21 = r2[1];
    const float r31 = r3[1];
    const float r02 = r0[2];
    const float r12 = r1[2];
    const float r22 = r2[2];
    const float r32 = r3[2];
    const float r03 = r0[3];
    const float r13 = r1[3];
    const float r23 = r2[3];
    const float r33 = r3[3];
    
    const float det2233 = r22 * r33 - r32 * r23;
    const float det1233 = r12 * r33 - r32 * r13;
    const float det1223 = r12 * r23 - r22 * r13;
    const float det0233 = r02 * r33 - r32 * r03;
    const float det0223 = r02 * r23 - r22 * r03;
    const float det0213 = r02 * r13 - r12 * r03;
    
    return ((r00 * ((r11 * det2233 - r21 * det1233) + r31 * det1223) - r10 * ((r01 * det2233 - r21 * det0233) + r31 * det0223)) + r20 * ((r01 * det1233 - r11 * det0233) + r31 * det0213)) - r30 * ((r01 * det1223 - r11 * det0223) + r21 * det0213);
}

constexpr Matrix& Matrix::LoadIdentity() noexcept { return *this = Identity(); }

constexpr Matrix& Matrix::Transpose() noexcept { return *this = Transpose(*this); }

constexpr Matrix& Matrix::Invert() { return *this = Invert(*this); }

constexpr Matrix Matrix::Transpose(const Matrix& matrix) noexcept
{
    return Matrix(
        matrix.r0.x, matrix.r1.x, matrix.r2.x, matrix.r3.x,
        matrix.r0.y, matrix.r1.y, matrix.r2.y, matrix.r3.y,
        matrix.r0.z, matrix.r1.z, matrix.r2.z, matrix.r3.z,
        matrix.r0.w, matrix.r1.w, matrix.r2.w, matrix.r3.w
    );
}

constexpr Matrix Matrix::Invert(const Matrix &matrix)
{
    if (matrix.Determinant() == 0.f) [[unlikely]]
        throw std::invalid_argument("Matrix isn't invertible");
    else [[likely]]
    {
        // Definition from MonoGame/XNA: https://github.com/MonoGame/MonoGame/blob/b30122c99597eaf81b81f32ab1d467a7b4185c73/MonoGame.Framework/Matrix.cs
        Matrix result;
        
        const float r00 = matrix.r0[0];
		const float r01 = matrix.r0[1];
		const float r02 = matrix.r0[2];
		const float r03 = matrix.r0[3];
		const float r10 = matrix.r1[0];
		const float r11 = matrix.r1[1];
		const float r12 = matrix.r1[2];
		const float r13 = matrix.r1[3];
		const float r20 = matrix.r2[0];
		const float r21 = matrix.r2[1];
		const float r22 = matrix.r2[2];
		const float r23 = matrix.r2[3];
		const float r30 = matrix.r3[0];
		const float r31 = matrix.r3[1];
		const float r32 = matrix.r3[2];
		const float r33 = matrix.r3[3];
        
		const float num17 = r22 * r33 - r23 * r32;
		const float num18 = r21 * r33 - r23 * r31;
		const float num19 = r21 * r32 - r22 * r31;
		const float num20 = r20 * r33 - r23 * r30;
		const float num21 = r20 * r32 - r22 * r30;
		const float num22 = r20 * r31 - r21 * r30;
		const float num23 = r11 * num17 - r12 * num18 + r13 * num19;
		const float num24 = -(r10 * num17 - r12 * num20 + r13 * num21);
		const float num25 = r10 * num18 - r11 * num20 + r13 * num22;
		const float num26 = -(r10 * num19 - r11 * num21 + r12 * num22);
		const float num27 = 1.f / (r00 * num23 + r01 * num24 + r02 * num25 + r03 * num26);
		
		result.r0[0] = num23 * num27;
		result.r1[0] = num24 * num27;
		result.r2[0] = num25 * num27;
		result.r3[0] = num26 * num27;
        
		result.r0[1] = -(r01 * num17 - r02 * num18 + r03 * num19) * num27;
		result.r1[1] = (r00 * num17 - r02 * num20 + r03 * num21) * num27;
		result.r2[1] = -(r00 * num18 - r01 * num20 + r03 * num22) * num27;
		result.r3[1] = (r00 * num19 - r01 * num21 + r02 * num22) * num27;
        
		const float num28 = r12 * r33 - r13 * r32;
		const float num29 = r11 * r33 - r13 * r31;
		const float num30 = r11 * r32 - r12 * r31;
		const float num31 = r10 * r33 - r13 * r30;
		const float num32 = r10 * r32 - r12 * r30;
		const float num33 = r10 * r31 - r11 * r30;
        
		result.r0[2] = (r01 * num28 - r02 * num29 + r03 * num30) * num27;
		result.r1[2] = -(r00 * num28 - r02 * num31 + r03 * num32) * num27;
		result.r2[2] = (r00 * num29 - r01 * num31 + r03 * num33) * num27;
		result.r3[2] = -(r00 * num30 - r01 * num32 + r02 * num33) * num27;
        
		const float num34 = r12 * r23 - r13 * r22;
		const float num35 = r11 * r23 - r13 * r21;
		const float num36 = r11 * r22 - r12 * r21;
		const float num37 = r10 * r23 - r13 * r20;
		const float num38 = r10 * r22 - r12 * r20;
		const float num39 = r10 * r21 - r11 * r20;
        
		result.r0[3] = -(r01 * num34 - r02 * num35 + r03 * num36) * num27;
		result.r1[3] = (r00 * num34 - r02 * num37 + r03 * num38) * num27;
		result.r2[3] = -(r00 * num35 - r01 * num37 + r03 * num39) * num27;
		result.r3[3] = (r00 * num36 - r01 * num38 + r02 * num39) * num27;

        return result;
    }
}

constexpr Matrix Matrix::Translation3D(const Vector3 &translation) noexcept
{
    return Matrix(
        1.f, 0.f, 0.f, translation.x,
        0.f, 1.f, 0.f, translation.y,
        0.f, 0.f, 1.f, translation.z,
        0.f, 0.f, 0.f, 1.f
    );
}

constexpr Matrix Matrix::Rotation3DX(const float cos, const float sin) noexcept
{
	return Matrix(
		1.f,    0.f,    0.f,    0.f,
		0.f,    cos,   -sin,    0.f,
		0.f,    sin,    cos,    0.f,
		0.f,    0.f,    0.f,    1.f
	);
}

constexpr Matrix Matrix::Rotation3DY(const float cos, const float sin) noexcept
{
	return Matrix(
		 cos,    0.f,    sin,    0.f,
		 0.f,    1.f,    0.f,    0.f,
		-sin,    0.f,    cos,    0.f,
		 0.f,    0.f,    0.f,    1.f
	);
}

constexpr Matrix Matrix::Rotation3DZ(const float cos, const float sin) noexcept
{
	return Matrix(
		cos,   -sin,    0.f,    0.f,
		sin,    cos,    0.f,    0.f,
		0.f,    0.f,    1.f,    0.f,
		0.f,    0.f,    0.f,    1.f
	);
}

constexpr Matrix Matrix::Rotation3D(const Quaternion& rotation) noexcept
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

	result.r0 = Vector4(
		1.f - 2.f * (yy + zz),
		2.f * (xy - wz),
		2.f * (xz + wy),
		0.f
	);
	result.r1 = Vector4(
		2.f * (xy + wz),
		1.f - 2.f * (zz + xx),
		2.f * (yz - wx),
		0.f
	);
	result.r2 = Vector4(
		2.f * (xz - wy),
		2.f * (yz + wx),
		1.f - 2.f * (yy + xx),
		0.f
	);
	result.r3[3] = 1.f;

	return result;
}

constexpr Matrix Matrix::Scaling3D(const Vector3 &scale) noexcept
{
	return Matrix(
		scale.x,       0.f,     0.f, 0.f,
			  0.f, scale.y,     0.f, 0.f,
			  0.f,     0.f, scale.z, 0.f,
			  0.f,     0.f,     0.f, 1.f
	);
}

constexpr Matrix Matrix::Trs(const Vector3& translation, const Quaternion& rotation, const Vector3& scale) noexcept { return Trs(translation, Matrix::Rotation3D(rotation), scale); }

constexpr void Matrix::OrthographicProjection(const float left, const float right, const float bottom, const float top, const float near, const float far, Matrix& result)
{
	if (near < far) [[unlikely]]
		throw std::invalid_argument("Near must be smaller than far.");
	else [[likely]]
		result = Matrix(
			2.f / (right - left), 0.f, 0.f, -((right + left) / (right - left)),
			0.f, 2.f / (top - bottom), 0.f, -((top + bottom) / (top - bottom)),
			0.f, 0.f, -2.f / (far - near), -((far + near) / (far - near)),
			0.f, 0.f, 0.f, 1.f
		);
}

constexpr const Vector4 &Matrix::operator[](const size_t row) const { return (&r0)[row]; }

constexpr Vector4 &Matrix::operator[](const size_t row) { return (&r0)[row]; }

constexpr Matrix operator-(const Matrix& matrix) noexcept
{
	Matrix result = matrix;
    
	for (size_t i = 0; i < 4; i++)
		result[i] = -matrix[i];
    
	return result;
}

constexpr Matrix operator+(const Matrix &m1, const Matrix &m2) noexcept
{
	Matrix result;
    
	for (size_t i = 0; i < 4; i++)
		result[i] = m1[i] + m2[i];
    
	return result;
}

constexpr Matrix operator-(const Matrix &m1, const Matrix &m2) noexcept { return m1 + (-m2); }

constexpr Matrix operator*(const Matrix &m, const float scalar) noexcept
{
	Matrix result;
    
	for (size_t i = 0; i < 4; i++)
	{
		for (size_t j = 0; j < 4; j++)
			result[i][j] = m[i][j] * scalar;
	}
    
	return result;
}

constexpr Vector3 operator*(const Matrix& m, const Vector3& v) noexcept
{
    const float x = v.x * m[0].x + v.y * m[0].y + v.z * m[0].z;
    const float y = v.x * m[1].x + v.y * m[1].y + v.z * m[1].z;
    const float z = v.x * m[2].x + v.y * m[2].y + v.z * m[2].z;

    return Vector3(x, y, z);
}

constexpr Vector4 operator*(const Matrix& m, const Vector4& v) noexcept
{
    const float x = v.x * m[0].x + v.y * m[0].y + v.z * m[0].z + v.w * m[0].w;
    const float y = v.x * m[1].x + v.y * m[1].y + v.z * m[1].z + v.w * m[1].w;
    const float z = v.x * m[2].x + v.y * m[2].y + v.z * m[2].z + v.w * m[2].w;
    const float w = v.x * m[3].x + v.y * m[3].y + v.z * m[3].z + v.w * m[3].w;
	
    return Vector4(x, y, z, w);
}

constexpr Matrix operator*(const Matrix &m1, const Matrix &m2) noexcept
{
	Matrix result;

	for (size_t i = 0; i < 4; i++)
	{
		for (size_t j = 0; j < 4; j++)
		{
			for (size_t k = 0; k < 4; k++)
				result[i][j] += m1[i][k] * m2[k][j];
		}
	}
    
	return result;
}

constexpr Matrix &operator+=(Matrix &m1, const Matrix &m2) noexcept { return m1 = m1 + m2; }

constexpr Matrix &operator-=(Matrix &m1, const Matrix &m2) noexcept { return m1 = m1 - m2; }

constexpr Matrix &operator*=(Matrix &m, const float scalar) noexcept { return m = m * scalar; }

constexpr Vector3& operator*=(const Matrix& m, Vector3& v) noexcept { return v = m * v; }

constexpr Vector4 &operator*=(const Matrix &m, Vector4& v) noexcept { return v = m * v; }

constexpr Matrix &operator*=(Matrix &m1, const Matrix &m2) noexcept { return m1 = m1 * m2; }

/// <summary>
///	Checks if two Matrices are considered equal using <code>calc::Equals</code>.
/// </summary>
[[nodiscard]]
bool operator==(Matrix a, Matrix b);

/// <summary>
///	Checks if two Matrices are considered different using <code>calc::Equals</code>.
/// </summary>
[[nodiscard]]
bool operator!=(Matrix a, Matrix b);

std::ostream& operator<<(std::ostream& out, const Matrix& m);

constexpr Matrix Matrix::Trs(const Vector3& translation, const Matrix& rotation, const Vector3& scale) noexcept
{
	Matrix result = Identity();

	result[0][3] = translation.x;
	result[1][3] = translation.y;
	result[2][3] = translation.z;

	return result * rotation * Matrix::Scaling3D(scale);
}

using mat4 = Matrix;
