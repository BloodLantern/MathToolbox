#pragma once

#ifdef MATH_DEFINE_FORMATTER
#include <format>
#include <sstream>
#endif

#include "calc.hpp"
#include "vector3.hpp"
#include "vector4.hpp"
#include "quaternion.hpp"

/// <summary>
/// The Matrix class represents a 4x4 array mainly used for mathematical operations.
/// Matrices are stored using the column-major convention.
/// </summary>
class MATH_TOOLBOX Matrix
{
public:
	float m00 = 0.f; float m10 = 0.f; float m20 = 0.f; float m30 = 0.f;
	float m01 = 0.f; float m11 = 0.f; float m21 = 0.f; float m31 = 0.f;
	float m02 = 0.f; float m12 = 0.f; float m22 = 0.f; float m32 = 0.f;
	float m03 = 0.f; float m13 = 0.f; float m23 = 0.f; float m33 = 0.f;
	
	/// <summary>
	/// Returns the identity Matrix.
	/// The identity Matrix is one with its diagonal
	/// set to one and everything else set to zero.
	/// </summary>
	[[nodiscard]]
	static constexpr Matrix Identity() noexcept;
	
	/// <summary>
	/// Returns the identity Matrix.
	/// The identity Matrix is one with its diagonal
	/// set to one and everything else set to zero.
	/// </summary>
	static constexpr void Identity(Matrix& result) noexcept;
    
	/// <summary>
	/// Creates a 3D translation Matrix from the given angle for each of the x, y, and z axis.
	/// </summary>
	[[nodiscard]]
	static constexpr Matrix Translation(const Vector3& translation) noexcept;
    
	/// <summary>
	/// Creates a 3D translation Matrix from the given angle for each of the x, y, and z axis.
	/// </summary>
	static constexpr void Translation(const Vector3& translation, Matrix& result) noexcept;
    
	/// <summary>
	/// Creates a 3D rotation Matrix from the given angle and axis.
	/// </summary>
	/// <param name="angle">The angle in radians.</param>
	/// <param name="axis">The axis around which the rotation occurs.</param>
	[[nodiscard]]
	static Matrix Rotation(float angle, const Vector3& axis) noexcept;
    
	/// <summary>
	/// Creates a 3D rotation Matrix from the given angle and axis.
	/// </summary>
	/// <param name="angle">The angle in radians.</param>
	/// <param name="axis">The axis around which the rotation occurs.</param>
	/// <param name="result">The output of the function.</param>
	static void Rotation(float angle, const Vector3& axis, Matrix& result) noexcept;
    
	/// <summary>
	/// Creates a 3D rotation Matrix around the X axis from the given angle.
	/// </summary>
	/// <param name="angle">The angle in radians.</param>
	[[nodiscard]]
	static Matrix RotationX(float angle) noexcept;
    
	/// <summary>
	/// Creates a 3D rotation Matrix around the X axis from the given angle.
	/// </summary>
	/// <param name="angle">The angle in radians.</param>
	/// <param name="result">The output of the function.</param>
	static void RotationX(float angle, Matrix& result) noexcept;
    
	/// <summary>
	/// Creates a 3D rotation Matrix around the X axis from the given angle.
	/// </summary>
	/// <param name="cos">The cosine of the angle in radians.</param>
	/// <param name="sin">The sine of the angle in radians.</param>
	[[nodiscard]]
	static constexpr Matrix RotationX(float cos, float sin) noexcept;
    
	/// <summary>
	/// Creates a 3D rotation Matrix around the X axis from the given angle.
	/// </summary>
	/// <param name="cos">The cosine of the angle in radians.</param>
	/// <param name="sin">The sine of the angle in radians.</param>
	/// <param name="result">The output of the function.</param>
	static constexpr void RotationX(float cos, float sin, Matrix& result) noexcept;
    
	/// <summary>
	/// Creates a 3D rotation Matrix around the Y axis from the given angle.
	/// </summary>
	/// <param name="angle">The angle in radians.</param>
	[[nodiscard]]
	static Matrix RotationY(float angle) noexcept;
    
	/// <summary>
	/// Creates a 3D rotation Matrix around the Y axis from the given angle.
	/// </summary>
	/// <param name="angle">The angle in radians.</param>
	/// <param name="result">The output of the function.</param>
	static void RotationY(float angle, Matrix& result) noexcept;
    
	/// <summary>
	/// Creates a 3D rotation Matrix around the Y axis from the given angle.
	/// </summary>
	/// <param name="cos">The cosine of the angle in radians.</param>
	/// <param name="sin">The sine of the angle in radians.</param>
	[[nodiscard]]
	static constexpr Matrix RotationY(float cos, float sin) noexcept;
    
	/// <summary>
	/// Creates a 3D rotation Matrix around the Y axis from the given angle.
	/// </summary>
	/// <param name="cos">The cosine of the angle in radians.</param>
	/// <param name="sin">The sine of the angle in radians.</param>
	/// <param name="result">The output of the function.</param>
	static constexpr void RotationY(float cos, float sin, Matrix& result) noexcept;
    
	/// <summary>
	/// Creates a 3D rotation Matrix around the Z axis from the given angle.
	/// </summary>
	/// <param name="angle">The angle in radians.</param>
	[[nodiscard]]
	static Matrix RotationZ(float angle) noexcept;
    
	/// <summary>
	/// Creates a 3D rotation Matrix around the Z axis from the given angle.
	/// </summary>
	/// <param name="angle">The angle in radians.</param>
	/// <param name="result">The output of the function.</param>
	static void RotationZ(float angle, Matrix& result) noexcept;
    
	/// <summary>
	/// Creates a 3D rotation Matrix around the Z axis from the given angle.
	/// </summary>
	/// <param name="cos">The cosine of the angle in radians.</param>
	/// <param name="sin">The sine of the angle in radians.</param>
	[[nodiscard]]
	static constexpr Matrix RotationZ(float cos, float sin) noexcept;
    
	/// <summary>
	/// Creates a 3D rotation Matrix around the Z axis from the given angle.
	/// </summary>
	/// <param name="cos">The cosine of the angle in radians.</param>
	/// <param name="sin">The sine of the angle in radians.</param>
	/// <param name="result">The output of the function.</param>
	static constexpr void RotationZ(float cos, float sin, Matrix& result) noexcept;
    
	/// <summary>
	/// Creates a 3D rotation Matrix from the given angle for each of the x, y, and z axis.
	/// </summary>
	[[nodiscard]]
	static Matrix Rotation(const Vector3& rotation) noexcept;
    
	/// <summary>
	/// Creates a 3D rotation Matrix from the given angle for each of the x, y, and z axis.
	/// </summary>
	static void Rotation(const Vector3& rotation, Matrix& result) noexcept;

	/// <summary>
	///	Creates a 3D rotation Matrix from the given rotation Quaternion.
	/// </summary>
	[[nodiscard]]
	static constexpr Matrix Rotation(const Quaternion& rotation) noexcept;
    
	/// <summary>
	///	Creates a 3D rotation Matrix from the given rotation Quaternion.
	/// </summary>
	static constexpr void Rotation(const Quaternion& rotation, Matrix& result) noexcept;
    
	/// <summary>
	/// Creates a 3D rotation matrix from the given cosine, sine and axis.
	/// </summary>
	/// <param name="cos">The cosine of the angle in radians.</param>
	/// <param name="sin">The sine of the angle in radians.</param>
	/// <param name="axis">The axis around which the rotation occurs.</param>
	[[nodiscard]]
	static Matrix Rotation(float cos, float sin, const Vector3& axis) noexcept;
    
	/// <summary>
	/// Creates a 3D rotation matrix from the given cosine, sine and axis.
	/// </summary>
	/// <param name="cos">The cosine of the angle in radians.</param>
	/// <param name="sin">The sine of the angle in radians.</param>
	/// <param name="axis">The axis around which the rotation occurs.</param>
	/// <param name="result">The output of the function.</param>
	static void Rotation(float cos, float sin, const Vector3& axis, Matrix& result) noexcept;
    
	/// <summary>
	/// Creates a 3D scaling matrix from the given Vector3.
	/// </summary>
	[[nodiscard]]
	static constexpr Matrix Scaling(const Vector3& scale) noexcept;
    
	/// <summary>
	/// Creates a 3D scaling matrix from the given Vector3.
	/// </summary>
	static constexpr void Scaling(const Vector3& scale, Matrix& result) noexcept;
    
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

	/// <summary>
	///	Creates a view Matrix, looking from an <c>eye</c> to a <c>center</c> using an <c>up</c> vector.
	/// </summary>
	[[nodiscard]]
	static Matrix LookAt(const Vector3& eye, const Vector3& center, const Vector3& up) noexcept;
    
	/// <summary>
	///	Creates a view Matrix, looking from an <c>eye</c> to a <c>center</c> using an <c>up</c> vector.
	/// </summary>
    static void LookAt(const Vector3& eye, const Vector3& center, const Vector3& up, Matrix& result) noexcept;

	/// <summary>
	///	Creates a perspective projection Matrix from the given <c>fov</c> (Field Of View) and aspect ratio.
	///	Anything closer than <c>near</c> or further than <c>far</c> is discarded.
	/// </summary>
	[[nodiscard]]
	static Matrix Perspective(float fov, float aspectRatio, float near, float far);
    
	/// <summary>
	///	Creates a perspective projection Matrix from the given <c>fov</c> (Field Of View) and aspect ratio.
	///	Anything closer than <c>near</c> or further than <c>far</c> is discarded.
	/// </summary>
    static void Perspective(float fov, float aspectRatio, float near, float far, Matrix& result);

	/// <summary>
	///	Creates an orthographic projection Matrix from the given <c>left</c>, <c>right</c>, <c>bottom</c>, and <c>top</c>
	///	screen positions.
	///	Anything closer than <c>near</c> or further than <c>far</c> is discarded.
	/// </summary>
	[[nodiscard]]
	static constexpr Matrix Orthographic(float left, float right, float bottom, float top, float near, float far);
    
	/// <summary>
	///	Creates an orthographic projection Matrix from the given <c>left</c>, <c>right</c>, <c>bottom</c>, and <c>top</c>
	///	screen positions.
	///	Anything closer than <c>near</c> or further than <c>far</c> is discarded.
	/// </summary>
	static constexpr void Orthographic(float left, float right, float bottom, float top, float near, float far, Matrix& result);

    /// <summary>
    /// Creates a Matrix with all its values set to 0.
    /// </summary>
    constexpr Matrix() = default;

    /// <summary>
    /// Creates a Matrix with all its values set to this default value.
    /// </summary>
	constexpr explicit Matrix(float defaultValue) noexcept;
	
	/// <summary>
	/// Constructs a Matrix with its components set to the data pointed by <c>data</c>.
	/// This constructor assumes that <c>data</c> is a valid pointer pointing to at least 16 float values.
	/// </summary>
	/// <param name="data">The data where the values for this matrix's components are located.</param>
	constexpr explicit Matrix(const float* data) noexcept;

	/// <summary>
	///	Constructs a Matrix with 4 column vectors.
	/// </summary>
    constexpr Matrix(
        const Vector4& c0,
        const Vector4& c1,
        const Vector4& c2,
        const Vector4& c3
    ) noexcept;

	/// <summary>
	///	Constructs a Matrix with 16 float values.
	/// </summary>
	constexpr Matrix(
		float m00, float m01, float m02, float m03,
		float m10, float m11, float m12, float m13,
		float m20, float m21, float m22, float m23,
		float m30, float m31, float m32, float m33
    ) noexcept;

    /// <summary>
    ///	Gets a pointer to the first value of this Matrix.
    /// </summary>
    /// <returns>A pointer to the first value of this Matrix.</returns>
    [[nodiscard]]
    constexpr const float* Raw() const noexcept;

    /// <summary>
    ///	Gets a pointer to the first value of this Matrix.
    /// </summary>
    /// <returns>A pointer to the first value of this Matrix.</returns>
    [[nodiscard]]
    constexpr float* Raw() noexcept;

	/// <summary>
	///	Uses the <c>std::cout</c> stream to print the values of this matrix
	///	in a square-like shape, e.g. by using newlines to make it easier to read.
	/// </summary>
	void DebugPrint() const noexcept;

    /// <summary>
    /// Returns whether the Matrix has everything except its diagonal set to zero.
    /// </summary>
    [[nodiscard]]
    constexpr bool IsDiagonal() const noexcept;
    
    /// <summary>
    /// Returns whether the Matrix is the identity matrix.
    /// If this returns true, Matrix::Identity() == *this should be true.
    /// </summary>
    [[nodiscard]]
    constexpr bool IsIdentity() const noexcept;
    
    /// <summary>
    /// Returns whether this Matrix has everything set to zero.
    /// </summary>
    [[nodiscard]]
    constexpr bool IsNull() const noexcept;
    
    /// <summary>
    /// Returns whether the Matrix is symmetric by its diagonal elements.
    /// </summary>
    [[nodiscard]]
    constexpr bool IsSymmetric() const noexcept;
    
    /// <summary>
    /// Returns whether the Matrix is symmetric by its diagonal elements
    /// but one of the sides is the opposite of the other.
    /// </summary>
    [[nodiscard]]
	constexpr bool IsAntisymmetric() const noexcept;
    
	/// <summary>
	/// Returns the diagonal elements of the Matrix.
	/// </summary>
	[[nodiscard]]
	constexpr Vector4 Diagonal() const noexcept;
    
	/// <summary>
	/// Returns the diagonal elements of the Matrix.
	/// </summary>
	constexpr void Diagonal(Vector4& result) const noexcept;
    
    /// <summary>
    /// Returns the sum of the diagonal elements of the Matrix.
    /// </summary>
    [[nodiscard]]
    constexpr float Trace() const noexcept;
    
    /// <summary>
    /// Returns the determinant of this Matrix.
    /// </summary>
    [[nodiscard]]
	constexpr float Determinant() const noexcept;
    
	/// <summary>
	/// Switches the Matrix by its diagonal elements.
	/// </summary>
	[[nodiscard]]
	constexpr Matrix Transposed() const noexcept;
    
	/// <summary>
	/// Switches the Matrix by its diagonal elements.
	/// </summary>
	constexpr void Transposed(Matrix& result) const noexcept;

	/// <summary>
	/// Computes the invert of this Matrix, e.g. <c>*this * Inverted() == Identity()</c> is true.
	/// </summary>
	[[nodiscard]]
	constexpr Matrix Inverted() const;

	/// <summary>
	/// Computes the invert of this Matrix, e.g. <c>*this * Inverted() == Identity()</c> is true.
	/// </summary>
	constexpr void Inverted(Matrix& result) const;

	/// <summary>
	///	Retrieves this matrix's value at position <c>[col, row]</c>.
	/// </summary>
	/// <param name="col">The index of the row to get.</param>
	/// <param name="row">The index of the column to get.</param>
	/// <returns>The value at position <c>[col, row]</c>.</returns>
	[[nodiscard]]
	constexpr float At(unsigned char col, unsigned char row) const;
    
	/// <summary>
	///	Retrieves this matrix's row at position <c>[col, row]</c>.
	/// </summary>
	/// <param name="col">The index of the row to get.</param>
	/// <param name="row">The index of the column to get.</param>
	/// <returns>The value at position <c>[col, row]</c>.</returns>
	[[nodiscard]]
	constexpr float& At(unsigned char col, unsigned char row);
    
	/// <summary>
	///	Retrieves this matrix's column vector at position <c>col</c>.
	///	If you want to get a value of this matrix, consider using <see cref="At(unsigned char, unsigned char)"/>
	///	instead, as it is optimized for direct-value access.
	/// </summary>
	/// <param name="col">The index of the column to get.</param>
	/// <returns>The column vector at index <c>col</c>.</returns>
	[[nodiscard]]
	constexpr Vector4 operator[](unsigned char col);

	/// <summary>
	///	Converts this Matrix to a Vector4 by retrieving its first column.
	/// </summary>
    explicit operator Vector4() const noexcept;
};

static_assert(std::is_default_constructible_v<Matrix>, "Class Matrix must be default constructible.");
static_assert(std::is_copy_constructible_v<Matrix>, "Class Matrix must be copy constructible.");
static_assert(std::is_move_constructible_v<Matrix>, "Class Matrix must be move constructible.");
static_assert(std::is_copy_assignable_v<Matrix>, "Class Matrix must be copy assignable.");
static_assert(std::is_move_assignable_v<Matrix>, "Class Matrix must be move assignable.");

constexpr Matrix::Matrix(const float defaultValue) noexcept
    : m00(defaultValue), m10(defaultValue), m20(defaultValue), m30(defaultValue)
    , m01(defaultValue), m11(defaultValue), m21(defaultValue), m31(defaultValue)
    , m02(defaultValue), m12(defaultValue), m22(defaultValue), m32(defaultValue)
    , m03(defaultValue), m13(defaultValue), m23(defaultValue), m33(defaultValue)
{
}

constexpr Matrix::Matrix(const float* const data) noexcept
	: m00(data[0]), m10(data[1]), m20(data[2]), m30(data[3])
	, m01(data[4]), m11(data[5]), m21(data[6]), m31(data[7])
	, m02(data[8]), m12(data[9]), m22(data[10]), m32(data[11])
	, m03(data[12]), m13(data[13]), m23(data[14]), m33(data[15])
{
}

constexpr Matrix::Matrix(const Vector4& c0, const Vector4& c1, const Vector4& c2, const Vector4& c3) noexcept
	: m00(c0.x), m10(c1.x), m20(c2.x), m30(c3.x)
	, m01(c0.y), m11(c1.y), m21(c2.y), m31(c3.y)
	, m02(c0.z), m12(c1.z), m22(c2.z), m32(c3.z)
	, m03(c0.w), m13(c1.w), m23(c2.w), m33(c3.w)
{
}

constexpr Matrix::Matrix(
	const float m00, const float m01, const float m02, const float m03,
	const float m10, const float m11, const float m12, const float m13,
	const float m20, const float m21, const float m22, const float m23,
	const float m30, const float m31, const float m32, const float m33
) noexcept
	: m00(m00), m10(m10), m20(m20), m30(m30)
	, m01(m01), m11(m11), m21(m21), m31(m31)
	, m02(m02), m12(m12), m22(m22), m32(m32)
	, m03(m03), m13(m13), m23(m23), m33(m33)
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

constexpr Matrix Matrix::Translation(const Vector3 &translation) noexcept
{
	return Matrix(
		1.f, 0.f, 0.f, translation.x,
		0.f, 1.f, 0.f, translation.y,
		0.f, 0.f, 1.f, translation.z,
		0.f, 0.f, 0.f, 1.f
    );
}

constexpr void Matrix::Translation(const Vector3& translation, Matrix& result) noexcept
{
	result = Matrix(
		1.f, 0.f, 0.f, translation.x,
		0.f, 1.f, 0.f, translation.y,
		0.f, 0.f, 1.f, translation.z,
		0.f, 0.f, 0.f, 1.f
	);
}

constexpr Matrix Matrix::RotationX(const float cos, const float sin) noexcept
{
	return Matrix(
		1.f,    0.f,    0.f,    0.f,
		0.f,    cos,   -sin,    0.f,
		0.f,    sin,    cos,    0.f,
		0.f,    0.f,    0.f,    1.f
	);
}

constexpr void Matrix::RotationX(const float cos, const float sin, Matrix& result) noexcept
{
	result = Matrix(
		1.f,    0.f,    0.f,    0.f,
		0.f,    cos,   -sin,    0.f,
		0.f,    sin,    cos,    0.f,
		0.f,    0.f,    0.f,    1.f
	);
}

constexpr Matrix Matrix::RotationY(const float cos, const float sin) noexcept
{
	return Matrix(
		 cos,    0.f,    sin,    0.f,
		 0.f,    1.f,    0.f,    0.f,
		-sin,    0.f,    cos,    0.f,
		 0.f,    0.f,    0.f,    1.f
	);
}

constexpr void Matrix::RotationY(const float cos, const float sin, Matrix& result) noexcept
{
	result = Matrix(
		 cos,    0.f,    sin,    0.f,
		 0.f,    1.f,    0.f,    0.f,
		-sin,    0.f,    cos,    0.f,
		 0.f,    0.f,    0.f,    1.f
	);
}

constexpr Matrix Matrix::RotationZ(const float cos, const float sin) noexcept
{
	return Matrix(
		cos,   -sin,    0.f,    0.f,
	    sin,    cos,    0.f,    0.f,
		0.f,    0.f,    1.f,    0.f,
		0.f,    0.f,    0.f,    1.f
	);
}

constexpr void Matrix::RotationZ(const float cos, const float sin, Matrix& result) noexcept
{
	result = Matrix(
		cos,   -sin,    0.f,    0.f,
	    sin,    cos,    0.f,    0.f,
		0.f,    0.f,    1.f,    0.f,
		0.f,    0.f,    0.f,    1.f
	);
}

constexpr Matrix Matrix::Rotation(const Quaternion& rotation) noexcept
{
	Matrix result;
	Rotation(rotation, result);
	return result;
}

constexpr void Matrix::Rotation(const Quaternion& rotation, Matrix& result) noexcept
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

constexpr Matrix Matrix::Scaling(const Vector3 &scale) noexcept
{
	return Matrix(
		scale.x,       0.f,     0.f, 0.f,
			  0.f, scale.y,     0.f, 0.f,
			  0.f,     0.f, scale.z, 0.f,
			  0.f,     0.f,     0.f, 1.f
	);
}

constexpr void Matrix::Scaling(const Vector3& scale, Matrix& result) noexcept
{
	result = Matrix(
		scale.x,       0.f,     0.f, 0.f,
			  0.f, scale.y,     0.f, 0.f,
			  0.f,     0.f, scale.z, 0.f,
			  0.f,     0.f,     0.f, 1.f
	);
}

constexpr Matrix Matrix::Trs(const Vector3& translation, const Quaternion& rotation, const Vector3& scale) noexcept { return Trs(translation, Rotation(rotation), scale); }

constexpr void Matrix::Trs(const Vector3& translation, const Quaternion& rotation, const Vector3& scale, Matrix& result) noexcept { Trs(translation, Rotation(rotation), scale, result); }

constexpr Matrix Matrix::Orthographic(const float left, const float right, const float bottom, const float top, const float near, const float far)
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

constexpr void Matrix::Orthographic(const float left, const float right, const float bottom, const float top, const float near, const float far, Matrix& result)
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

constexpr const float* Matrix::Raw() const noexcept { return &m00; }

constexpr float* Matrix::Raw() noexcept { return &m00; }

constexpr bool Matrix::IsDiagonal() const noexcept
{
    return                      Calc::IsZero(m01) && Calc::IsZero(m02) && Calc::IsZero(m03)
        && Calc::IsZero(m10)                      && Calc::IsZero(m12) && Calc::IsZero(m13)
        && Calc::IsZero(m20) && Calc::IsZero(m21)                      && Calc::IsZero(m23)
        && Calc::IsZero(m30) && Calc::IsZero(m31) && Calc::IsZero(m32);
}

constexpr bool Matrix::IsIdentity() const noexcept
{
    if (!IsDiagonal())
        return false;
    
    return Calc::Equals(m00, 1.f) && Calc::Equals(m11, 1.f) && Calc::Equals(m22, 1.f) && Calc::Equals(m33, 1.f);
}

constexpr bool Matrix::IsNull() const noexcept
{
    if (!IsDiagonal())
        return false;

    return Calc::IsZero(m00) && Calc::IsZero(m11) && Calc::IsZero(m22) && Calc::IsZero(m33);
}

constexpr bool Matrix::IsSymmetric() const noexcept
{
    return Calc::Equals(m01, m10) && Calc::Equals(m02, m20) && Calc::Equals(m03, m30)
        && Calc::Equals(m12, m21) && Calc::Equals(m13, m31)
        && Calc::Equals(m23, m32);
}

constexpr bool Matrix::IsAntisymmetric() const noexcept
{
    return Calc::Equals(m01, -m10) && Calc::Equals(m02, -m20) && Calc::Equals(m03, -m30)
        && Calc::Equals(m12, -m21) && Calc::Equals(m13, -m31)
        && Calc::Equals(m23, -m32);
}

constexpr Vector4 Matrix::Diagonal() const noexcept { return Vector4(m00, m11, m22, m33); }

constexpr void Matrix::Diagonal(Vector4& result) const noexcept { result = Vector4(m00, m11, m22, m33); }

constexpr float Matrix::Trace() const noexcept { return m00 + m11 + m22 + m33; }

constexpr float Matrix::Determinant() const noexcept
{ 
    // Definition from MonoGame/XNA: https://github.com/MonoGame/MonoGame/blob/b30122c99597eaf81b81f32ab1d467a7b4185c73/MonoGame.Framework/Matrix.cs
    
    const float det2233 = m22 * m33 - m32 * m23;
    const float det1233 = m12 * m33 - m32 * m13;
    const float det1223 = m12 * m23 - m22 * m13;
    const float det0233 = m02 * m33 - m32 * m03;
    const float det0223 = m02 * m23 - m22 * m03;
    const float det0213 = m02 * m13 - m12 * m03;
    
    return m00 * (m11 * det2233 - m21 * det1233 + m31 * det1223)
		- m10 * (m01 * det2233 - m21 * det0233 + m31 * det0223)
		+ m20 * (m01 * det1233 - m11 * det0233 + m31 * det0213)
		- m30 * (m01 * det1223 - m11 * det0223 + m21 * det0213);
}

constexpr Matrix Matrix::Transposed() const noexcept
{
	return Matrix(
		m00, m10, m20, m30,
		m01, m11, m21, m31,
		m02, m12, m22, m32,
		m03, m13, m23, m33
	);
}

constexpr void Matrix::Transposed(Matrix& result) const noexcept
{
	result = Matrix(
		m00, m10, m20, m30,
		m01, m11, m21, m31,
		m02, m12, m22, m32,
		m03, m13, m23, m33
	);
}

constexpr Matrix Matrix::Inverted() const
{
	Matrix result;
	Inverted(result);
	return result;
}

constexpr void Matrix::Inverted(Matrix& result) const
{
    if (Determinant() == 0.f) [[unlikely]]
        throw std::invalid_argument("Matrix isn't invertible");
	
	// Definition from MonoGame/XNA: https://github.com/MonoGame/MonoGame/blob/b30122c99597eaf81b81f32ab1d467a7b4185c73/MonoGame.Framework/Matrix.cs
        
    const float val17 = m22 * m33 - m23 * m32;
    const float val18 = m21 * m33 - m23 * m31;
    const float val19 = m21 * m32 - m22 * m31;
    const float val20 = m20 * m33 - m23 * m30;
    const float val21 = m20 * m32 - m22 * m30;
    const float val22 = m20 * m31 - m21 * m30;
    const float val23 = m11 * val17 - m12 * val18 + m13 * val19;
    const float val24 = -(m10 * val17 - m12 * val20 + m13 * val21);
    const float val25 = m10 * val18 - m11 * val20 + m13 * val22;
    const float val26 = -(m10 * val19 - m11 * val21 + m12 * val22);
    const float val27 = 1.f / (m00 * val23 + m01 * val24 + m02 * val25 + m03 * val26);
        
    const float val28 = m12 * m33 - m13 * m32;
    const float val29 = m11 * m33 - m13 * m31;
    const float val30 = m11 * m32 - m12 * m31;
    const float val31 = m10 * m33 - m13 * m30;
    const float val32 = m10 * m32 - m12 * m30;
    const float val33 = m10 * m31 - m11 * m30;
        
    const float val34 = m12 * m23 - m13 * m22;
    const float val35 = m11 * m23 - m13 * m21;
    const float val36 = m11 * m22 - m12 * m21;
    const float val37 = m10 * m23 - m13 * m20;
    const float val38 = m10 * m22 - m12 * m20;
    const float val39 = m10 * m21 - m11 * m20;

	result = Matrix(
		val23 * val27,
		-(m01 * val17 - m02 * val18 + m03 * val19) * val27,
		(m01 * val28 - m02 * val29 + m03 * val30) * val27,
		-(m01 * val34 - m02 * val35 + m03 * val36) * val27,

		val24 * val27,
		(m00 * val17 - m02 * val20 + m03 * val21) * val27,
		-(m00 * val28 - m02 * val31 + m03 * val32) * val27,
		(m00 * val34 - m02 * val37 + m03 * val38) * val27,

		val25 * val27,
		-(m00 * val18 - m01 * val20 + m03 * val22) * val27,
		(m00 * val29 - m01 * val31 + m03 * val33) * val27,
		-(m00 * val35 - m01 * val37 + m03 * val39) * val27,

		val26 * val27,
		(m00 * val19 - m01 * val21 + m02 * val22) * val27,
		-(m00 * val30 - m01 * val32 + m02 * val33) * val27,
		(m00 * val36 - m01 * val38 + m02 * val39) * val27
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

constexpr Vector4 Matrix::operator[](const unsigned char col)
{
	return Vector4(Raw() + static_cast<ptrdiff_t>(col) * 4);
}

[[nodiscard]]
constexpr Matrix operator-(const Matrix& matrix) noexcept
{
	return Matrix(
		-matrix.m00, -matrix.m01, -matrix.m02, -matrix.m03,
		-matrix.m10, -matrix.m11, -matrix.m12, -matrix.m13,
		-matrix.m20, -matrix.m21, -matrix.m22, -matrix.m23,
		-matrix.m30, -matrix.m31, -matrix.m32, -matrix.m33
	);
}

[[nodiscard]]
constexpr Matrix operator+(const Matrix& m1, const Matrix& m2) noexcept
{
	return Matrix(
		m1.m00 + m2.m00, m1.m01 + m2.m01, m1.m02 + m2.m02, m1.m03 + m2.m03,
		m1.m10 + m2.m10, m1.m11 + m2.m11, m1.m12 + m2.m12, m1.m13 + m2.m13,
		m1.m20 + m2.m20, m1.m21 + m2.m21, m1.m22 + m2.m22, m1.m23 + m2.m23,
		m1.m30 + m2.m30, m1.m31 + m2.m31, m1.m32 + m2.m32, m1.m33 + m2.m33
	);
}

[[nodiscard]]
constexpr Matrix operator-(const Matrix& m1, const Matrix& m2) noexcept { return m1 + -m2; }

[[nodiscard]]
constexpr Matrix operator*(const Matrix& m, const float scalar) noexcept
{
	return Matrix(
		m.m00 + scalar, m.m01 + scalar, m.m02 + scalar, m.m03 + scalar,
		m.m10 + scalar, m.m11 + scalar, m.m12 + scalar, m.m13 + scalar,
		m.m20 + scalar, m.m21 + scalar, m.m22 + scalar, m.m23 + scalar,
		m.m30 + scalar, m.m31 + scalar, m.m32 + scalar, m.m33 + scalar
	);
}

[[nodiscard]]
constexpr Matrix operator*(const float factor, const Matrix m) noexcept { return m * factor; }

[[nodiscard]]
constexpr Vector3 operator*(const Matrix& m, const Vector3& v) noexcept
{
    return Vector3(
    	v.x * m.m00 + v.y * m.m01 + v.z * m.m02 + m.m03,
    	v.x * m.m10 + v.y * m.m11 + v.z * m.m12 + m.m13,
    	v.x * m.m20 + v.y * m.m21 + v.z * m.m22 + m.m23
    );
}

[[nodiscard]]
constexpr Vector4 operator*(const Matrix& m, const Vector4& v) noexcept
{
	return Vector4(
		v.x * m.m00 + v.y * m.m01 + v.z * m.m02 + m.m03,
		v.x * m.m10 + v.y * m.m11 + v.z * m.m12 + m.m13,
		v.x * m.m20 + v.y * m.m21 + v.z * m.m22 + m.m23,
		v.x * m.m30 + v.y * m.m31 + v.z * m.m32 + m.m33
	);
}

[[nodiscard]]
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
///	Checks if two Matrices are considered equal using <c>Calc::Equals</c>.
/// </summary>
[[nodiscard]]
constexpr bool operator==(const Matrix& a, const Matrix& b)
{
	return Calc::Equals(a.m00, b.m00) && Calc::Equals(a.m01, b.m01) && Calc::Equals(a.m02, b.m02) && Calc::Equals(a.m03, b.m03)
		&& Calc::Equals(a.m10, b.m10) && Calc::Equals(a.m11, b.m11) && Calc::Equals(a.m12, b.m12) && Calc::Equals(a.m13, b.m13)
		&& Calc::Equals(a.m20, b.m20) && Calc::Equals(a.m21, b.m21) && Calc::Equals(a.m22, b.m22) && Calc::Equals(a.m23, b.m23)
		&& Calc::Equals(a.m30, b.m30) && Calc::Equals(a.m31, b.m31) && Calc::Equals(a.m32, b.m32) && Calc::Equals(a.m33, b.m33);
}

/// <summary>
///	Checks if two Matrices are considered different using <c>Calc::Equals</c>.
/// </summary>
[[nodiscard]]
constexpr bool operator!=(const Matrix& a, const Matrix& b) { return !(a == b); }

std::ostream& operator<<(std::ostream& out, const Matrix& m);

constexpr Matrix Matrix::Trs(const Vector3& translation, const Matrix& rotation, const Vector3& scale) noexcept
{
	const Matrix result = Matrix(
		1.f, 0.f, 0.f, translation.x,
		0.f, 1.f, 0.f, translation.y,
		0.f, 0.f, 1.f, translation.z,
		0.f, 0.f, 0.f, 1.f
	);

	Matrix temp;
	Scaling(scale, temp);

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
	Scaling(scale, temp);

	result = result * rotation * temp;
}

#ifdef MATH_DEFINE_FORMATTER
template<>
struct std::formatter<Matrix>
{
    template<class ParseContext>
    constexpr typename ParseContext::iterator parse(ParseContext& ctx);

    template<class FmtContext>
    typename FmtContext::iterator format(Matrix m, FmtContext& ctx) const;

private:
    std::string m_Format;
    bool m_Multiline = false;
};

template<class ParseContext>
constexpr typename ParseContext::iterator std::formatter<Matrix, char>::parse(ParseContext& ctx)
{
    auto it = ctx.begin();
    if (it == ctx.end())
        return it;

    if (*it == 'm')
    {
        m_Multiline = true;
        it++;
    }

    while (*it != '}' && it != ctx.end())
        m_Format += *it++;

    return it;
}

template<class FmtContext>
typename FmtContext::iterator std::formatter<Matrix>::format(Matrix m, FmtContext &ctx) const
{
    std::ostringstream out;
    
    const char separator = m_Multiline ? '\n' : ' ';

    out << std::vformat(
            "[ {:" + m_Format + "} ; {:" + m_Format + "} ; {:" + m_Format + "} ; {:" + m_Format + "} ]" + separator
            + "[ {:" + m_Format + "} ; {:" + m_Format + "} ; {:" + m_Format + "} ; {:" + m_Format + "} ]" + separator
            + "[ {:" + m_Format + "} ; {:" + m_Format + "} ; {:" + m_Format + "} ; {:" + m_Format + "} ]" + separator
            + "[ {:" + m_Format + "} ; {:" + m_Format + "} ; {:" + m_Format + "} ; {:" + m_Format + "} ]",
            std::make_format_args(
                    m.m00, m.m01, m.m02, m.m03,
                    m.m10, m.m11, m.m12, m.m13,
                    m.m20, m.m21, m.m22, m.m23,
                    m.m30, m.m31, m.m32, m.m33
            )
    );

    return std::ranges::copy(std::move(out).str(), ctx.out()).out;
}
#endif

using mat4 = Matrix;
using mat = Matrix;
