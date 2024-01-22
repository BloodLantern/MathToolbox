#pragma once

#include <ostream>

#include "quaternion.hpp"
#include "vector3.hpp"
#include "vector4.hpp"

class Vector2;

/// <summary>
/// The Matrix class represents a 4x4 array mainly used for mathematical operations.
/// Matrices are stored using the column-major convention.
/// </summary>
class Matrix
{
public:
	float m00, m01, m02, m03;
	float m10, m11, m12, m13;
	float m20, m21, m22, m23;
	float m30, m31, m32, m33;
	
	/// <summary>
	/// Returns the identity matrix.
	/// The identity matrix is a matrix with its diagonal
	/// set to one and everything else set to zero.
	/// </summary>
	[[nodiscard]]
	static constexpr Matrix Identity() noexcept;
	
	/// <summary>
	/// Returns the identity matrix.
	/// The identity matrix is a matrix with its diagonal
	/// set to one and everything else set to zero.
	/// </summary>
	static constexpr void Identity(Matrix& result) noexcept;

    /// <summary>
    /// Creates a matrix with all its values set to 0.
    /// </summary>
    constexpr Matrix() = default;

    /// <summary>
    /// Creates a matrix with all its values set to this default value.
    /// </summary>
    explicit constexpr Matrix(float defaultValue) noexcept;

    constexpr Matrix(
        const Vector4& c0,
        const Vector4& c1,
        const Vector4& c2,
        const Vector4& c3
    ) noexcept;

    constexpr Matrix(
        float m00, float m01, float m02, float m03,
        float m10, float m11, float m12, float m13,
        float m20, float m21, float m22, float m23,
        float m30, float m31, float m32, float m33
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
	/// Returns the diagonal elements of the matrix.
	/// </summary>
	constexpr void Diagonal(Vector4& result) const noexcept;
    
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
	/// Switches the matrix by its diagonal elements.
	/// </summary>
	constexpr Matrix Transposed() noexcept;
    
	/// <summary>
	/// Switches the matrix by its diagonal elements.
	/// </summary>
	constexpr void Transposed(Matrix& result) noexcept;

	/// <summary>
	/// Computes the invert of this matrix, e.g. <code>*this * Inverted() == Identity()</code> is true.
	/// </summary>
	constexpr Matrix Inverted();

	/// <summary>
	/// Computes the invert of this matrix, e.g. <code>*this * Inverted() == Identity()</code> is true.
	/// </summary>
	constexpr void Inverted(Matrix& result);
    
	/// <summary>
	/// Creates a 3D translation matrix from the given angle for each of the x, y, and z axis.
	/// </summary>
	[[nodiscard]]
	static constexpr Matrix Translation3D(const Vector3& translation) noexcept;
    
	/// <summary>
	/// Creates a 3D translation matrix from the given angle for each of the x, y, and z axis.
	/// </summary>
	static constexpr void Translation3D(const Vector3& translation, Matrix& result) noexcept;
    
	/// <summary>
	/// Creates a 3D rotation matrix from the given angle and axis.
	/// </summary>
	/// <param name="angle">The angle in radians.</param>
	/// <param name="axis">The axis around which the rotation occurs.</param>
	[[nodiscard]]
	static Matrix Rotation3D(float angle, const Vector3& axis) noexcept;
    
	/// <summary>
	/// Creates a 3D rotation matrix from the given angle and axis.
	/// </summary>
	/// <param name="angle">The angle in radians.</param>
	/// <param name="axis">The axis around which the rotation occurs.</param>
	static void Rotation3D(float angle, const Vector3& axis, Matrix& result) noexcept;
    
	/// <summary>
	/// Creates a 3D rotation matrix around the X axis from the given angle.
	/// </summary>
	/// <param name="angle">The angle in radians.</param>
	[[nodiscard]]
	static Matrix Rotation3Dx(float angle) noexcept;
    
	/// <summary>
	/// Creates a 3D rotation matrix around the X axis from the given angle.
	/// </summary>
	/// <param name="angle">The angle in radians.</param>
	static void Rotation3Dx(float angle, Matrix& result) noexcept;
    
	/// <summary>
	/// Creates a 3D rotation matrix around the X axis from the given angle.
	/// </summary>
	/// <param name="cos">The cosine of the angle in radians.</param>
	/// <param name="sin">The sine of the angle in radians.</param>
	[[nodiscard]]
	static constexpr Matrix Rotation3Dx(float cos, float sin) noexcept;
    
	/// <summary>
	/// Creates a 3D rotation matrix around the X axis from the given angle.
	/// </summary>
	/// <param name="cos">The cosine of the angle in radians.</param>
	/// <param name="sin">The sine of the angle in radians.</param>
	static constexpr void Rotation3Dx(float cos, float sin, Matrix& result) noexcept;
    
	/// <summary>
	/// Creates a 3D rotation matrix around the Y axis from the given angle.
	/// </summary>
	/// <param name="angle">The angle in radians.</param>
	[[nodiscard]]
	static Matrix Rotation3Dy(float angle) noexcept;
    
	/// <summary>
	/// Creates a 3D rotation matrix around the Y axis from the given angle.
	/// </summary>
	/// <param name="angle">The angle in radians.</param>
	static void Rotation3Dy(float angle, Matrix& result) noexcept;
    
	/// <summary>
	/// Creates a 3D rotation matrix around the Y axis from the given angle.
	/// </summary>
	/// <param name="cos">The cosine of the angle in radians.</param>
	/// <param name="sin">The sine of the angle in radians.</param>
	[[nodiscard]]
	static constexpr Matrix Rotation3Dy(float cos, float sin) noexcept;
    
	/// <summary>
	/// Creates a 3D rotation matrix around the Y axis from the given angle.
	/// </summary>
	/// <param name="cos">The cosine of the angle in radians.</param>
	/// <param name="sin">The sine of the angle in radians.</param>
	static constexpr void Rotation3Dy(float cos, float sin, Matrix& result) noexcept;
    
	/// <summary>
	/// Creates a 3D rotation matrix around the Z axis from the given angle.
	/// </summary>
	/// <param name="angle">The angle in radians.</param>
	[[nodiscard]]
	static Matrix Rotation3Dz(float angle) noexcept;
    
	/// <summary>
	/// Creates a 3D rotation matrix around the Z axis from the given angle.
	/// </summary>
	/// <param name="angle">The angle in radians.</param>
	static void Rotation3Dz(float angle, Matrix& result) noexcept;
    
	/// <summary>
	/// Creates a 3D rotation matrix around the Z axis from the given angle.
	/// </summary>
	/// <param name="cos">The cosine of the angle in radians.</param>
	/// <param name="sin">The sine of the angle in radians.</param>
	[[nodiscard]]
	static constexpr Matrix Rotation3Dz(float cos, float sin) noexcept;
    
	/// <summary>
	/// Creates a 3D rotation matrix around the Z axis from the given angle.
	/// </summary>
	/// <param name="cos">The cosine of the angle in radians.</param>
	/// <param name="sin">The sine of the angle in radians.</param>
	static constexpr void Rotation3Dz(float cos, float sin, Matrix& result) noexcept;
    
	/// <summary>
	/// Creates a 3D rotation matrix from the given angle for each of the x, y, and z axis.
	/// </summary>
	[[nodiscard]]
	static Matrix Rotation3D(const Vector3& rotation) noexcept;
    
	/// <summary>
	/// Creates a 3D rotation matrix from the given angle for each of the x, y, and z axis.
	/// </summary>
	static void Rotation3D(const Vector3& rotation, Matrix& result) noexcept;
    
	[[nodiscard]]
	static constexpr Matrix Rotation3D(const Quaternion& rotation) noexcept;
    
	static constexpr void Rotation3D(const Quaternion& rotation, Matrix& result) noexcept;
    
	/// <summary>
	/// Creates a 3D rotation matrix from the given cosine, sine and axis.
	/// </summary>
	/// <param name="cos">The cosine of the angle in radians.</param>
	/// <param name="sin">The sine of the angle in radians.</param>
	/// <param name="axis">The axis around which the rotation occurs.</param>
	[[nodiscard]]
	static Matrix Rotation3D(float cos, float sin, const Vector3& axis) noexcept;
    
	/// <summary>
	/// Creates a 3D rotation matrix from the given cosine, sine and axis.
	/// </summary>
	/// <param name="cos">The cosine of the angle in radians.</param>
	/// <param name="sin">The sine of the angle in radians.</param>
	/// <param name="axis">The axis around which the rotation occurs.</param>
	static void Rotation3D(float cos, float sin, const Vector3& axis, Matrix& result) noexcept;
    
	/// <summary>
	/// Creates a 3D scaling matrix from the given Vector3.
	/// </summary>
	[[nodiscard]]
	static constexpr Matrix Scaling3D(const Vector3& scale) noexcept;
    
	/// <summary>
	/// Creates a 3D scaling matrix from the given Vector3.
	/// </summary>
	static constexpr void Scaling3D(const Vector3& scale, Matrix& result) noexcept;
    
	/// <summary>
	/// Creates a Translation-Rotation-Scaling (TRS) matrix from the given translation, rotation and scaling.
	/// </summary>
	[[nodiscard]]
	static Matrix Trs(const Vector3& translation, const Vector3& rotation, const Vector3& scale) noexcept;
    
	/// <summary>
	/// Creates a Translation-Rotation-Scaling (TRS) matrix from the given translation, rotation and scaling.
	/// </summary>
	static void Trs(const Vector3& translation, const Vector3& rotation, const Vector3& scale, Matrix& result) noexcept;
    
	/// <summary>
	/// Creates a Translation-Rotation-Scaling (TRS) matrix from the given translation, rotation and scaling.
	/// </summary>
	[[nodiscard]]
	static Matrix Trs(const Vector3& translation, float rotationAngle, const Vector3& rotationAxis, const Vector3& scale) noexcept;
    
	/// <summary>
	/// Creates a Translation-Rotation-Scaling (TRS) matrix from the given translation, rotation and scaling.
	/// </summary>
	static void Trs(const Vector3& translation, float rotationAngle, const Vector3& rotationAxis, const Vector3& scale, Matrix& result) noexcept;
    
	/// <summary>
	/// Creates a Translation-Rotation-Scaling (TRS) matrix from the given translation, rotation and scaling.
	/// </summary>
	[[nodiscard]]
	static constexpr Matrix Trs(const Vector3& translation, const Matrix& rotation, const Vector3& scale) noexcept;
    
	/// <summary>
	/// Creates a Translation-Rotation-Scaling (TRS) matrix from the given translation, rotation and scaling.
	/// </summary>
	static constexpr void Trs(const Vector3& translation, const Matrix& rotation, const Vector3& scale, Matrix& result) noexcept;
    
	/// <summary>
	/// Creates a Translation-Rotation-Scaling (TRS) matrix from the given translation, rotation and scaling.
	/// </summary>
	[[nodiscard]]
	static constexpr Matrix Trs(const Vector3& translation, const Quaternion& rotation, const Vector3& scale) noexcept;
    
	/// <summary>
	/// Creates a Translation-Rotation-Scaling (TRS) matrix from the given translation, rotation and scaling.
	/// </summary>
	static constexpr void Trs(const Vector3& translation, const Quaternion& rotation, const Vector3& scale, Matrix& result) noexcept;
    
    static Matrix View(const Vector3& eye, const Vector3& center, const Vector3& up) noexcept;
    
    static void View(const Vector3& eye, const Vector3& center, const Vector3& up, Matrix& result) noexcept;
    
    static Matrix PerspectiveProjection(float fov, float aspectRatio, float near, float far);
    
    static void PerspectiveProjection(float fov, float aspectRatio, float near, float far, Matrix& result);
    
    static constexpr Matrix OrthographicProjection(float left, float right, float bottom, float top, float near, float far);
    
	static constexpr void OrthographicProjection(float left, float right, float bottom, float top, float near, float far, Matrix& result);

	/// <summary>
	///	Retrieves this matrix's value at position <code>[col, row]</code>.
	/// </summary>
	/// <param name="col">The index of the column to get.</param>
	/// <param name="row">The index of the row to get.</param>
	/// <returns>The value at position <code>[col, row]</code>.</returns>
	[[nodiscard]]
	constexpr float At(unsigned char col, unsigned char row) const;
    
	/// <summary>
	///	Retrieves this matrix's row at position <code>[col, row]</code>.
	/// </summary>
	/// <param name="col">The index of the column to get.</param>
	/// <param name="row">The index of the row to get.</param>
	/// <returns>The value at position <code>[col, row]</code>.</returns>
	[[nodiscard]]
	constexpr float& At(unsigned char col, unsigned char row);
    
    explicit operator Vector4() const noexcept;
};

static_assert(std::is_default_constructible_v<Matrix>, "Class Matrix must be default constructible.");
static_assert(std::is_copy_constructible_v<Matrix>, "Class Matrix must be copy constructible.");
static_assert(std::is_move_constructible_v<Matrix>, "Class Matrix must be move constructible.");
static_assert(std::is_copy_assignable_v<Matrix>, "Class Matrix must be copy assignable.");
static_assert(std::is_move_assignable_v<Matrix>, "Class Matrix must be move assignable.");

constexpr Matrix::Matrix(const float defaultValue) noexcept
    : m00(defaultValue), m01(defaultValue), m02(defaultValue), m03(defaultValue)
    , m10(defaultValue), m11(defaultValue), m12(defaultValue), m13(defaultValue)
    , m20(defaultValue), m21(defaultValue), m22(defaultValue), m23(defaultValue)
    , m30(defaultValue), m31(defaultValue), m32(defaultValue), m33(defaultValue)
{
}

constexpr Matrix::Matrix(const Vector4& c0, const Vector4& c1, const Vector4& c2, const Vector4& c3) noexcept
	: m00(c0.x), m01(c0.y), m02(c0.z), m03(c0.w)
	, m10(c1.x), m11(c1.y), m12(c1.z), m13(c1.w)
	, m20(c2.x), m21(c2.y), m22(c2.z), m23(c2.w)
	, m30(c3.x), m31(c3.y), m32(c3.z), m33(c3.w)
{
}

constexpr Matrix::Matrix(
    const float m00, const float m01, const float m02, const float m03,
    const float m10, const float m11, const float m12, const float m13,
    const float m20, const float m21, const float m22, const float m23,
    const float m30, const float m31, const float m32, const float m33
) noexcept
	: m00(m00), m01(m01), m02(m02), m03(m03)
	, m10(m10), m11(m11), m12(m12), m13(m13)
	, m20(m20), m21(m21), m22(m22), m23(m23)
	, m30(m30), m31(m31), m32(m32), m33(m33)
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

constexpr void Matrix::Identity(Matrix& result) noexcept
{
	result = Matrix(
		1.f, 0.f, 0.f, 0.f,
		0.f, 1.f, 0.f, 0.f,
		0.f, 0.f, 1.f, 0.f,
		0.f, 0.f, 0.f, 1.f
	);
}

constexpr const float* Matrix::Raw() const noexcept { return &m00; }

constexpr float* Matrix::Raw() noexcept { return &m00; }

constexpr Vector4 Matrix::Diagonal() const noexcept { return Vector4(m00, m11, m22, m33); }

constexpr void Matrix::Diagonal(Vector4& result) const noexcept { result = Vector4(m00, m11, m22, m33); }

constexpr float Matrix::Trace() const noexcept { return m00 + m11 + m22 + m33; }

constexpr float Matrix::Determinant() const noexcept
{ 
    // Definition from MonoGame/XNA: https://github.com/MonoGame/MonoGame/blob/b30122c99597eaf81b81f32ab1d467a7b4185c73/MonoGame.Framework/Matrix.cs
    
    const float det2233 = m22 * m33 - m23 * m32;
    const float det1233 = m21 * m33 - m23 * m31;
    const float det1223 = m21 * m32 - m22 * m31;
    const float det0233 = m20 * m33 - m23 * m30;
    const float det0223 = m20 * m32 - m22 * m30;
    const float det0213 = m20 * m31 - m21 * m30;
    
    return m00 * (m11 * det2233 - m12 * det1233 + m13 * det1223)
		- m01 * (m10 * det2233 - m12 * det0233 + m13 * det0223)
		+ m02 * (m10 * det1233 - m11 * det0233 + m13 * det0213)
		- m03 * (m10 * det1223 - m11 * det0223 + m12 * det0213);
}

constexpr Matrix Matrix::Transposed() noexcept
{
	return Matrix(
		m00, m10, m20, m30,
		m01, m11, m21, m31,
		m02, m12, m22, m32,
		m03, m13, m23, m33
	);
}

constexpr void Matrix::Transposed(Matrix& result) noexcept
{
	result = Matrix(
		m00, m10, m20, m30,
		m01, m11, m21, m31,
		m02, m12, m22, m32,
		m03, m13, m23, m33
	);
}

constexpr Matrix Matrix::Inverted()
{
	Matrix result;
	Inverted(result);
	return result;
}

constexpr void Matrix::Inverted(Matrix& result)
{
    if (Determinant() == 0.f) [[unlikely]]
        throw std::invalid_argument("Matrix isn't invertible");
	
	// Definition from MonoGame/XNA: https://github.com/MonoGame/MonoGame/blob/b30122c99597eaf81b81f32ab1d467a7b4185c73/MonoGame.Framework/Matrix.cs
        
    const float num17 = m22 * m33 - m23 * m32;
    const float num18 = m21 * m33 - m23 * m31;
    const float num19 = m21 * m32 - m22 * m31;
    const float num20 = m20 * m33 - m23 * m30;
    const float num21 = m20 * m32 - m22 * m30;
    const float num22 = m20 * m31 - m21 * m30;
    const float num23 = m11 * num17 - m12 * num18 + m13 * num19;
    const float num24 = -(m10 * num17 - m12 * num20 + m13 * num21);
    const float num25 = m10 * num18 - m11 * num20 + m13 * num22;
    const float num26 = -(m10 * num19 - m11 * num21 + m12 * num22);
    const float num27 = 1.f / (m00 * num23 + m01 * num24 + m02 * num25 + m03 * num26);
        
    const float num28 = m12 * m33 - m13 * m32;
    const float num29 = m11 * m33 - m13 * m31;
    const float num30 = m11 * m32 - m12 * m31;
    const float num31 = m10 * m33 - m13 * m30;
    const float num32 = m10 * m32 - m12 * m30;
    const float num33 = m10 * m31 - m11 * m30;
        
    const float num34 = m12 * m23 - m13 * m22;
    const float num35 = m11 * m23 - m13 * m21;
    const float num36 = m11 * m22 - m12 * m21;
    const float num37 = m10 * m23 - m13 * m20;
    const float num38 = m10 * m22 - m12 * m20;
    const float num39 = m10 * m21 - m11 * m20;

	result = Matrix(
		num23 * num27,
		num24 * num27,
		num25 * num27,
		num26 * num27,
		
		-(m01 * num17 - m02 * num18 + m03 * num19) * num27,
		(m00 * num17 - m02 * num20 + m03 * num21) * num27,
		-(m00 * num18 - m01 * num20 + m03 * num22) * num27,
		(m00 * num19 - m01 * num21 + m02 * num22) * num27,

		(m01 * num28 - m02 * num29 + m03 * num30) * num27,
		-(m00 * num28 - m02 * num31 + m03 * num32) * num27,
		(m00 * num29 - m01 * num31 + m03 * num33) * num27,
		-(m00 * num30 - m01 * num32 + m02 * num33) * num27,

		-(m01 * num34 - m02 * num35 + m03 * num36) * num27,
		(m00 * num34 - m02 * num37 + m03 * num38) * num27,
		-(m00 * num35 - m01 * num37 + m03 * num39) * num27,
		(m00 * num36 - m01 * num38 + m02 * num39) * num27
	);
}

constexpr Matrix Matrix::Translation3D(const Vector3 &translation) noexcept
{
    return Matrix(
        1.f, 0.f, 0.f, 0.f,
        0.f, 1.f, 0.f, 0.f,
        0.f, 0.f, 1.f, 0.f,
        translation.x, translation.y, translation.z, 1.f
    );
}

constexpr void Matrix::Translation3D(const Vector3& translation, Matrix& result) noexcept
{
	result = Matrix(
		1.f, 0.f, 0.f, 0.f,
		0.f, 1.f, 0.f, 0.f,
		0.f, 0.f, 1.f, 0.f,
		translation.x, translation.y, translation.z, 1.f
	);
}

constexpr Matrix Matrix::Rotation3Dx(const float cos, const float sin) noexcept
{
	return Matrix(
		1.f,    0.f,    0.f,    0.f,
		0.f,    cos,    sin,    0.f,
		0.f,   -sin,    cos,    0.f,
		0.f,    0.f,    0.f,    1.f
	);
}

constexpr void Matrix::Rotation3Dx(float cos, float sin, Matrix& result) noexcept
{
	result = Matrix(
		1.f,    0.f,    0.f,    0.f,
		0.f,    cos,    sin,    0.f,
		0.f,   -sin,    cos,    0.f,
		0.f,    0.f,    0.f,    1.f
	);
}

constexpr Matrix Matrix::Rotation3Dy(const float cos, const float sin) noexcept
{
	return Matrix(
		 cos,    0.f,   -sin,    0.f,
		 0.f,    1.f,    0.f,    0.f,
		 sin,    0.f,    cos,    0.f,
		 0.f,    0.f,    0.f,    1.f
	);
}

constexpr void Matrix::Rotation3Dy(float cos, float sin, Matrix& result) noexcept
{
	result = Matrix(
		 cos,    0.f,   -sin,    0.f,
		 0.f,    1.f,    0.f,    0.f,
		 sin,    0.f,    cos,    0.f,
		 0.f,    0.f,    0.f,    1.f
	);
}

constexpr Matrix Matrix::Rotation3Dz(const float cos, const float sin) noexcept
{
	return Matrix(
		cos,    sin,    0.f,    0.f,
	   -sin,    cos,    0.f,    0.f,
		0.f,    0.f,    1.f,    0.f,
		0.f,    0.f,    0.f,    1.f
	);
}

constexpr void Matrix::Rotation3Dz(float cos, float sin, Matrix& result) noexcept
{
	result = Matrix(
		cos,    sin,    0.f,    0.f,
	   -sin,    cos,    0.f,    0.f,
		0.f,    0.f,    1.f,    0.f,
		0.f,    0.f,    0.f,    1.f
	);
}

constexpr Matrix Matrix::Rotation3D(const Quaternion& rotation) noexcept
{
	Matrix result;
	Rotation3D(rotation, result);
	return result;
}

constexpr void Matrix::Rotation3D(const Quaternion& rotation, Matrix& result) noexcept
{
	const float xx = SQ(rotation.X());
	const float yy = SQ(rotation.Y());
	const float zz = SQ(rotation.Z());

	const float xy = rotation.X() * rotation.Y();
	const float wz = rotation.Z() * rotation.W();
	const float xz = rotation.Z() * rotation.X();
	const float wy = rotation.Y() * rotation.W();
	const float yz = rotation.Y() * rotation.Z();
	const float wx = rotation.X() * rotation.W();

	result = Matrix(
		1.f - 2.f * (yy + zz), 2.f * (xy - wz), 2.f * (xz + wy), 0.f,
		2.f * (xy + wz), 1.f - 2.f * (zz + xx), 2.f * (yz - wx), 0.f,
		2.f * (xz - wy), 2.f * (yz + wx), 1.f - 2.f * (yy + xx), 0.f,
		0.f, 0.f, 0.f, 1.f
	);
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

constexpr void Matrix::Scaling3D(const Vector3& scale, Matrix& result) noexcept
{
	result = Matrix(
		scale.x,       0.f,     0.f, 0.f,
			  0.f, scale.y,     0.f, 0.f,
			  0.f,     0.f, scale.z, 0.f,
			  0.f,     0.f,     0.f, 1.f
	);
}

constexpr Matrix Matrix::Trs(const Vector3& translation, const Quaternion& rotation, const Vector3& scale) noexcept { return Trs(translation, Rotation3D(rotation), scale); }

constexpr void Matrix::Trs(const Vector3& translation, const Quaternion& rotation, const Vector3& scale, Matrix& result) noexcept { Trs(translation, Rotation3D(rotation), scale, result); }

constexpr Matrix Matrix::OrthographicProjection(float left, float right, float bottom, float top, float near, float far)
{
	if (near > far) [[unlikely]]
		throw std::invalid_argument("Near must be smaller than far.");
	
	return Matrix(
		2.f / (right - left), 0.f, 0.f, 0.f,
		0.f, 2.f / (top - bottom), 0.f, 0.f,
		0.f, 0.f, -2.f / (far - near), 0.f,
		-((right + left) / (right - left)), -((top + bottom) / (top - bottom)), -((far + near) / (far - near)), 1.f
	);
}

constexpr void Matrix::OrthographicProjection(const float left, const float right, const float bottom, const float top, const float near, const float far, Matrix& result)
{
	if (near > far) [[unlikely]]
		throw std::invalid_argument("Near must be smaller than far.");
	
	result = Matrix(
		2.f / (right - left), 0.f, 0.f, 0.f,
		0.f, 2.f / (top - bottom), 0.f, 0.f,
		0.f, 0.f, -2.f / (far - near), 0.f,
		-((right + left) / (right - left)), -((top + bottom) / (top - bottom)), -((far + near) / (far - near)), 1.f
	);
}

constexpr float Matrix::At(const unsigned char col, const unsigned char row) const
{
	if (col < 4 && row < 4) [[likely]]
		return *(Raw() + (col * 4 + row));
	[[unlikely]]
		throw std::out_of_range("Matrix subscript out of range");
}

constexpr float& Matrix::At(const unsigned char col, const unsigned char row)
{
	if (col < 4 && row < 4) [[likely]]
		return *(Raw() + (col * 4 + row));
	[[unlikely]]
		throw std::out_of_range("Matrix subscript out of range");
}

constexpr Matrix operator-(const Matrix& matrix) noexcept
{
	return Matrix(
		-matrix.m00, -matrix.m10, -matrix.m20, -matrix.m30,
		-matrix.m01, -matrix.m11, -matrix.m21, -matrix.m31,
		-matrix.m02, -matrix.m12, -matrix.m22, -matrix.m32,
		-matrix.m03, -matrix.m13, -matrix.m23, -matrix.m33
	);
}

constexpr Matrix operator+(const Matrix& m1, const Matrix& m2) noexcept
{
	return Matrix(
		m1.m00 + m2.m00, m1.m10 + m2.m10, m1.m20 + m2.m20, m1.m30 + m2.m30,
		m1.m01 + m2.m01, m1.m11 + m2.m11, m1.m21 + m2.m21, m1.m31 + m2.m31,
		m1.m02 + m2.m02, m1.m12 + m2.m12, m1.m22 + m2.m22, m1.m32 + m2.m32,
		m1.m03 + m2.m03, m1.m13 + m2.m13, m1.m23 + m2.m23, m1.m33 + m2.m33
	);
}

constexpr Matrix operator-(const Matrix& m1, const Matrix& m2) noexcept { return m1 + -m2; }

constexpr Matrix operator*(const Matrix& m, const float scalar) noexcept
{
	return Matrix(
		m.m00 + scalar, m.m10 + scalar, m.m20 + scalar, m.m30 + scalar,
		m.m01 + scalar, m.m11 + scalar, m.m21 + scalar, m.m31 + scalar,
		m.m02 + scalar, m.m12 + scalar, m.m22 + scalar, m.m32 + scalar,
		m.m03 + scalar, m.m13 + scalar, m.m23 + scalar, m.m33 + scalar
	);
}

constexpr Vector3 operator*(const Matrix& m, const Vector3& v) noexcept
{
    return Vector3(
    	v.x * m.m00 + v.y * m.m10 + v.z * m.m20 + m.m30,
    	v.x * m.m01 + v.y * m.m11 + v.z * m.m21 + m.m31,
    	v.x * m.m02 + v.y * m.m12 + v.z * m.m22 + m.m32
    );
}

constexpr Vector4 operator*(const Matrix& m, const Vector4& v) noexcept
{
	return Vector4(
		v.x * m.m00 + v.y * m.m10 + v.z * m.m20 + m.m30,
		v.x * m.m01 + v.y * m.m11 + v.z * m.m21 + m.m31,
		v.x * m.m02 + v.y * m.m12 + v.z * m.m22 + m.m32,
		v.x * m.m03 + v.y * m.m13 + v.z * m.m23 + m.m33
	);
}

constexpr Matrix operator*(const Matrix& m1, const Matrix& m2) noexcept
{
	return Matrix(
		m1.m00 * m2.m00 + m1.m01 * m2.m10 + m1.m02 * m2.m20 + m1.m03 * m2.m30,
		m1.m00 * m2.m01 + m1.m01 * m2.m11 + m1.m02 * m2.m21 + m1.m03 * m2.m31,
		m1.m00 * m2.m02 + m1.m01 * m2.m12 + m1.m02 * m2.m22 + m1.m03 * m2.m32,
		m1.m00 * m2.m03 + m1.m01 * m2.m13 + m1.m02 * m2.m23 + m1.m03 * m2.m33,
		
		m1.m10 * m2.m00 + m1.m11 * m2.m10 + m1.m12 * m2.m20 + m1.m13 * m2.m30,
		m1.m10 * m2.m01 + m1.m11 * m2.m11 + m1.m12 * m2.m21 + m1.m13 * m2.m31,
		m1.m10 * m2.m02 + m1.m11 * m2.m12 + m1.m12 * m2.m22 + m1.m13 * m2.m32,
		m1.m10 * m2.m03 + m1.m11 * m2.m13 + m1.m12 * m2.m23 + m1.m13 * m2.m33,
		
		m1.m20 * m2.m00 + m1.m21 * m2.m10 + m1.m22 * m2.m20 + m1.m23 * m2.m30,
		m1.m20 * m2.m01 + m1.m21 * m2.m11 + m1.m22 * m2.m21 + m1.m23 * m2.m31,
		m1.m20 * m2.m02 + m1.m21 * m2.m12 + m1.m22 * m2.m22 + m1.m23 * m2.m32,
		m1.m20 * m2.m03 + m1.m21 * m2.m13 + m1.m22 * m2.m23 + m1.m23 * m2.m33,
		
		m1.m30 * m2.m00 + m1.m31 * m2.m10 + m1.m32 * m2.m20 + m1.m33 * m2.m30,
		m1.m30 * m2.m01 + m1.m31 * m2.m11 + m1.m32 * m2.m21 + m1.m33 * m2.m31,
		m1.m30 * m2.m02 + m1.m31 * m2.m12 + m1.m32 * m2.m22 + m1.m33 * m2.m32,
		m1.m30 * m2.m03 + m1.m31 * m2.m13 + m1.m32 * m2.m23 + m1.m33 * m2.m33
	);
}

constexpr Matrix& operator+=(Matrix& m1, const Matrix& m2) noexcept { return m1 = m1 + m2; }

constexpr Matrix& operator-=(Matrix& m1, const Matrix& m2) noexcept { return m1 = m1 - m2; }

constexpr Matrix& operator*=(Matrix& m, const float scalar) noexcept { return m = m * scalar; }

constexpr Vector3& operator*=(const Matrix& m, Vector3& v) noexcept { return v = m * v; }

constexpr Vector4 &operator*=(const Matrix& m, Vector4& v) noexcept { return v = m * v; }

constexpr Matrix& operator*=(Matrix& m1, const Matrix& m2) noexcept { return m1 = m1 * m2; }

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
	Matrix result = Matrix(
		1.f, 0.f, 0.f, 0.f,
		0.f, 1.f, 0.f, 0.f,
		0.f, 0.f, 1.f, 0.f,
		translation.x, translation.y, translation.z, 1.f
	);

	Matrix temp;
	Scaling3D(scale, temp);

	return result * rotation * temp;
}

constexpr void Matrix::Trs(const Vector3& translation, const Matrix& rotation, const Vector3& scale, Matrix& result) noexcept
{
	result = Matrix(
		1.f, 0.f, 0.f, 0.f,
		0.f, 1.f, 0.f, 0.f,
		0.f, 0.f, 1.f, 0.f,
		translation.x, translation.y, translation.z, 1.f
	);

	Matrix temp;
	Scaling3D(scale, temp);

	result = result * rotation * temp;
}

using mat4 = Matrix;
using mat = Matrix;
