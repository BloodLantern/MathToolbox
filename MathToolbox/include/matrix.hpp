#pragma once

#include <ostream>

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
        const Vector4& r0,
        const Vector4& r1,
        const Vector4& r2,
        const Vector4& r3
    ) noexcept;

    constexpr Matrix(
        float r00, float r01, float r02, float r03,
        float r10, float r11, float r12, float r13,
        float r20, float r21, float r22, float r23,
        float r30, float r31, float r32, float r33
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

constexpr void Matrix::Identity(Matrix& result) noexcept
{
	result = Matrix(
		1.f, 0.f, 0.f, 0.f,
		0.f, 1.f, 0.f, 0.f,
		0.f, 0.f, 1.f, 0.f,
		0.f, 0.f, 0.f, 1.f
	);
}

constexpr const float* Matrix::Raw() const noexcept { return &r0.x; }

constexpr float* Matrix::Raw() noexcept { return &r0.x; }

constexpr Vector4 Matrix::Diagonal() const noexcept { return Vector4(r0[0], r1[1], r2[2], r3[3]); }

constexpr void Matrix::Diagonal(Vector4& result) const noexcept { result = Vector4(r0[0], r1[1], r2[2], r3[3]); }

constexpr float Matrix::Trace() const noexcept { return r0[0] + r1[1] + r2[2] + r3[3]; }

constexpr float Matrix::Determinant() const noexcept
{ 
    // Definition from MonoGame/XNA: https://github.com/MonoGame/MonoGame/blob/b30122c99597eaf81b81f32ab1d467a7b4185c73/MonoGame.Framework/Matrix.cs
    
    const float det2233 = r2[2] * r3[3] - r3[2] * r2[3];
    const float det1233 = r1[2] * r3[3] - r3[2] * r1[3];
    const float det1223 = r1[2] * r2[3] - r2[2] * r1[3];
    const float det0233 = r0[2] * r3[3] - r3[2] * r0[3];
    const float det0223 = r0[2] * r2[3] - r2[2] * r0[3];
    const float det0213 = r0[2] * r1[3] - r1[2] * r0[3];
    
    return r0[0] * (r1[1] * det2233 - r2[1] * det1233 + r3[1] * det1223)
		- r1[0] * (r0[1] * det2233 - r2[1] * det0233 + r3[1] * det0223)
		+ r2[0] * (r0[1] * det1233 - r1[1] * det0233 + r3[1] * det0213)
		- r3[0] * (r0[1] * det1223 - r1[1] * det0223 + r2[1] * det0213);
}

constexpr Matrix Matrix::Transposed() noexcept
{
	return Matrix(
		r0[0], r1[0], r2[0], r3[0],
		r0[1], r1[1], r2[1], r3[1],
		r0[2], r1[2], r2[2], r3[2],
		r0[3], r1[3], r2[3], r3[3]
	);
}

constexpr void Matrix::Transposed(Matrix& result) noexcept
{
	result = Matrix(
		r0[0], r1[0], r2[0], r3[0],
		r0[1], r1[1], r2[1], r3[1],
		r0[2], r1[2], r2[2], r3[2],
		r0[3], r1[3], r2[3], r3[3]
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
        
    const float num17 = r2[2] * r3[3] - r2[3] * r3[2];
    const float num18 = r2[1] * r3[3] - r2[3] * r3[1];
    const float num19 = r2[1] * r3[2] - r2[2] * r3[1];
    const float num20 = r2[0] * r3[3] - r2[3] * r3[0];
    const float num21 = r2[0] * r3[2] - r2[2] * r3[0];
    const float num22 = r2[0] * r3[1] - r2[1] * r3[0];
    const float num23 = r1[1] * num17 - r1[2] * num18 + r1[3] * num19;
    const float num24 = -(r1[0] * num17 - r1[2] * num20 + r1[3] * num21);
    const float num25 = r1[0] * num18 - r1[1] * num20 + r1[3] * num22;
    const float num26 = -(r1[0] * num19 - r1[1] * num21 + r1[2] * num22);
    const float num27 = 1.f / (r0[0] * num23 + r0[1] * num24 + r0[2] * num25 + r0[3] * num26);
		
    result[0][0] = num23 * num27;
    result[1][0] = num24 * num27;
    result[2][0] = num25 * num27;
    result[3][0] = num26 * num27;
        
    result[0][1] = -(r0[1] * num17 - r0[2] * num18 + r0[3] * num19) * num27;
    result[1][1] = (r0[0] * num17 - r0[2] * num20 + r0[3] * num21) * num27;
    result[2][1] = -(r0[0] * num18 - r0[1] * num20 + r0[3] * num22) * num27;
    result[3][1] = (r0[0] * num19 - r0[1] * num21 + r0[2] * num22) * num27;
        
    const float num28 = r1[2] * r3[3] - r1[3] * r3[2];
    const float num29 = r1[1] * r3[3] - r1[3] * r3[1];
    const float num30 = r1[1] * r3[2] - r1[2] * r3[1];
    const float num31 = r1[0] * r3[3] - r1[3] * r3[0];
    const float num32 = r1[0] * r3[2] - r1[2] * r3[0];
    const float num33 = r1[0] * r3[1] - r1[1] * r3[0];
        
    result[0][2] = (r0[1] * num28 - r0[2] * num29 + r0[3] * num30) * num27;
    result[1][2] = -(r0[0] * num28 - r0[2] * num31 + r0[3] * num32) * num27;
    result[2][2] = (r0[0] * num29 - r0[1] * num31 + r0[3] * num33) * num27;
    result[3][2] = -(r0[0] * num30 - r0[1] * num32 + r0[2] * num33) * num27;
        
    const float num34 = r1[2] * r2[3] - r1[3] * r2[2];
    const float num35 = r1[1] * r2[3] - r1[3] * r2[1];
    const float num36 = r1[1] * r2[2] - r1[2] * r2[1];
    const float num37 = r1[0] * r2[3] - r1[3] * r2[0];
    const float num38 = r1[0] * r2[2] - r1[2] * r2[0];
    const float num39 = r1[0] * r2[1] - r1[1] * r2[0];
        
    result[0][3] = -(r0[1] * num34 - r0[2] * num35 + r0[3] * num36) * num27;
    result[1][3] = (r0[0] * num34 - r0[2] * num37 + r0[3] * num38) * num27;
    result[2][3] = -(r0[0] * num35 - r0[1] * num37 + r0[3] * num39) * num27;
    result[3][3] = (r0[0] * num36 - r0[1] * num38 + r0[2] * num39) * num27;
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

constexpr void Matrix::Translation3D(const Vector3& translation, Matrix& result) noexcept
{
	result = Matrix(
		1.f, 0.f, 0.f, translation.x,
		0.f, 1.f, 0.f, translation.y,
		0.f, 0.f, 1.f, translation.z,
		0.f, 0.f, 0.f, 1.f
	);
}

constexpr Matrix Matrix::Rotation3Dx(const float cos, const float sin) noexcept
{
	return Matrix(
		1.f,    0.f,    0.f,    0.f,
		0.f,    cos,   -sin,    0.f,
		0.f,    sin,    cos,    0.f,
		0.f,    0.f,    0.f,    1.f
	);
}

constexpr void Matrix::Rotation3Dx(float cos, float sin, Matrix& result) noexcept
{
	result = Matrix(
		1.f,    0.f,    0.f,    0.f,
		0.f,    cos,   -sin,    0.f,
		0.f,    sin,    cos,    0.f,
		0.f,    0.f,    0.f,    1.f
	);
}

constexpr Matrix Matrix::Rotation3Dy(const float cos, const float sin) noexcept
{
	return Matrix(
		 cos,    0.f,    sin,    0.f,
		 0.f,    1.f,    0.f,    0.f,
		-sin,    0.f,    cos,    0.f,
		 0.f,    0.f,    0.f,    1.f
	);
}

constexpr void Matrix::Rotation3Dy(float cos, float sin, Matrix& result) noexcept
{
	result = Matrix(
		 cos,    0.f,    sin,    0.f,
		 0.f,    1.f,    0.f,    0.f,
		-sin,    0.f,    cos,    0.f,
		 0.f,    0.f,    0.f,    1.f
	);
}

constexpr Matrix Matrix::Rotation3Dz(const float cos, const float sin) noexcept
{
	return Matrix(
		cos,   -sin,    0.f,    0.f,
		sin,    cos,    0.f,    0.f,
		0.f,    0.f,    1.f,    0.f,
		0.f,    0.f,    0.f,    1.f
	);
}

constexpr void Matrix::Rotation3Dz(float cos, float sin, Matrix& result) noexcept
{
	result = Matrix(
		cos,   -sin,    0.f,    0.f,
		sin,    cos,    0.f,    0.f,
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
		2.f / (right - left), 0.f, 0.f, -((right + left) / (right - left)),
		0.f, 2.f / (top - bottom), 0.f, -((top + bottom) / (top - bottom)),
		0.f, 0.f, -2.f / (far - near), -((far + near) / (far - near)),
		0.f, 0.f, 0.f, 1.f
	);
}

constexpr void Matrix::OrthographicProjection(const float left, const float right, const float bottom, const float top, const float near, const float far, Matrix& result)
{
	if (near > far) [[unlikely]]
		throw std::invalid_argument("Near must be smaller than far.");
	
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
	return Matrix(
		-matrix[0],
		-matrix[1],
		-matrix[2],
		-matrix[3]
	);
}

constexpr Matrix operator+(const Matrix& m1, const Matrix& m2) noexcept
{
	return Matrix(
		m1[0] + m2[0],
		m1[1] + m2[1],
		m1[2] + m2[2],
		m1[3] + m2[3]
	);
}

constexpr Matrix operator-(const Matrix& m1, const Matrix& m2) noexcept { return m1 + -m2; }

constexpr Matrix operator*(const Matrix& m, const float scalar) noexcept
{
	return Matrix(
		m[0] * scalar,
		m[1] * scalar,
		m[2] * scalar,
		m[3] * scalar
	);
}

constexpr Vector3 operator*(const Matrix& m, const Vector3& v) noexcept
{
    return Vector3(
    	v.x * m[0].x + v.y * m[0].y + v.z * m[0].z + m[0].w,
    	v.x * m[1].x + v.y * m[1].y + v.z * m[1].z + m[1].w,
    	v.x * m[2].x + v.y * m[2].y + v.z * m[2].z + m[2].w
    );
}

constexpr Vector4 operator*(const Matrix& m, const Vector4& v) noexcept
{
	return Vector4(
		v.x * m[0].x + v.y * m[0].y + v.z * m[0].z + m[0].w,
		v.x * m[1].x + v.y * m[1].y + v.z * m[1].z + m[1].w,
		v.x * m[2].x + v.y * m[2].y + v.z * m[2].z + m[2].w,
		v.x * m[3].x + v.y * m[3].y + v.z * m[3].z + m[3].w
	);
}

constexpr Matrix operator*(const Matrix& m1, const Matrix& m2) noexcept
{
	return Matrix(
		m1[0][0] * m2[0][0] + m1[0][1] * m2[1][0] + m1[0][2] * m2[2][0] + m1[0][3] * m2[3][0],
		m1[0][0] * m2[0][1] + m1[0][1] * m2[1][1] + m1[0][2] * m2[2][1] + m1[0][3] * m2[3][1],
		m1[0][0] * m2[0][2] + m1[0][1] * m2[1][2] + m1[0][2] * m2[2][2] + m1[0][3] * m2[3][2],
		m1[0][0] * m2[0][3] + m1[0][1] * m2[1][3] + m1[0][2] * m2[2][3] + m1[0][3] * m2[3][3],
		
		m1[1][0] * m2[0][0] + m1[1][1] * m2[1][0] + m1[1][2] * m2[2][0] + m1[1][3] * m2[3][0],
		m1[1][0] * m2[0][1] + m1[1][1] * m2[1][1] + m1[1][2] * m2[2][1] + m1[1][3] * m2[3][1],
		m1[1][0] * m2[0][2] + m1[1][1] * m2[1][2] + m1[1][2] * m2[2][2] + m1[1][3] * m2[3][2],
		m1[1][0] * m2[0][3] + m1[1][1] * m2[1][3] + m1[1][2] * m2[2][3] + m1[1][3] * m2[3][3],
		
		m1[2][0] * m2[0][0] + m1[2][1] * m2[1][0] + m1[2][2] * m2[2][0] + m1[2][3] * m2[3][0],
		m1[2][0] * m2[0][1] + m1[2][1] * m2[1][1] + m1[2][2] * m2[2][1] + m1[2][3] * m2[3][1],
		m1[2][0] * m2[0][2] + m1[2][1] * m2[1][2] + m1[2][2] * m2[2][2] + m1[2][3] * m2[3][2],
		m1[2][0] * m2[0][3] + m1[2][1] * m2[1][3] + m1[2][2] * m2[2][3] + m1[2][3] * m2[3][3],
		
		m1[3][0] * m2[0][0] + m1[3][1] * m2[1][0] + m1[3][2] * m2[2][0] + m1[3][3] * m2[3][0],
		m1[3][0] * m2[0][1] + m1[3][1] * m2[1][1] + m1[3][2] * m2[2][1] + m1[3][3] * m2[3][1],
		m1[3][0] * m2[0][2] + m1[3][1] * m2[1][2] + m1[3][2] * m2[2][2] + m1[3][3] * m2[3][2],
		m1[3][0] * m2[0][3] + m1[3][1] * m2[1][3] + m1[3][2] * m2[2][3] + m1[3][3] * m2[3][3]
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
		1.f, 0.f, 0.f, translation.x,
		0.f, 1.f, 0.f, translation.y,
		0.f, 0.f, 1.f, translation.z,
		0.f, 0.f, 0.f, 1.f
	);

	Matrix temp;
	Scaling3D(scale, temp);

	return result * rotation * temp;
}

constexpr void Matrix::Trs(const Vector3& translation, const Matrix& rotation, const Vector3& scale, Matrix& result) noexcept
{
	result = Matrix(
		1.f, 0.f, 0.f, translation.x,
		0.f, 1.f, 0.f, translation.y,
		0.f, 0.f, 1.f, translation.z,
		0.f, 0.f, 0.f, 1.f
	);

	Matrix temp;
	Scaling3D(scale, temp);

	result = result * rotation * temp;
}

using mat4 = Matrix;
