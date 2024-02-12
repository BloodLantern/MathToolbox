#pragma once

#include <ostream>

#include "calc.hpp"
#include "vector2.hpp"

class Vector4;
class Matrix;

/// <summary>
/// The Vector3 class represents either a three-dimensional vector or a point.
/// </summary>
class MATH_TOOLBOX Vector3
{
public:
	float x = 0.f, y = 0.f, z = 0.f;

	/// <summary>
	///	Equivalent to calling the default constructor.
	/// </summary>
	[[nodiscard]]
	static constexpr Vector3 Zero() noexcept;

	/// <summary>
	///	Equivalent to calling the default constructor.
	/// </summary>
	static constexpr void Zero(Vector3& result) noexcept;

	[[nodiscard]]
	static constexpr Vector3 UnitX() noexcept;

	static constexpr void UnitX(Vector3& result) noexcept;

	[[nodiscard]]
	static constexpr Vector3 UnitY() noexcept;

	static constexpr void UnitY(Vector3& result) noexcept;

	[[nodiscard]]
	static constexpr Vector3 UnitZ() noexcept;

	static constexpr void UnitZ(Vector3& result) noexcept;

	/// <summary>
	/// Returns a · b.
	/// </summary>
	[[nodiscard]]
	static constexpr float Dot(const Vector3& a, const Vector3& b) noexcept;

	/// <summary>
	/// Returns a x b.
	/// </summary>
	[[nodiscard]]
	static constexpr Vector3 Cross(const Vector3& a, const Vector3& b) noexcept;

	/// <summary>
	/// Returns a x b.
	/// </summary>
	static constexpr void Cross(const Vector3& a, const Vector3& b, Vector3& result) noexcept;

	/// <summary>
	/// Lerp between two positions in a 3-dimensional space.
	/// </summary>
	/// <param name="value">The current position.</param>
	/// <param name="target">The target position.</param>
	/// <param name="t">The time to lerp.</param>
	/// <returns>The lerp position.</returns>
	[[nodiscard]]
	static constexpr Vector3 Lerp(const Vector3& value, const Vector3& target, float t) noexcept;

	/// <summary>
	/// Lerp between two positions in a 3-dimensional space.
	/// </summary>
	/// <param name="value">The current position.</param>
	/// <param name="target">The target position.</param>
	/// <param name="t">The time to lerp.</param>
	/// <param name="result">The lerp position.</param>
	static constexpr void Lerp(const Vector3& value, const Vector3& target, float t, Vector3& result) noexcept;

	/// <summary>
	/// Constructs a Vector3 with both its components set to 0.
	/// </summary>
	constexpr Vector3() = default;
	
	/// <summary>
	/// Constructs a Vector3 with both its components set to 'xy'.
	/// </summary>
	/// <param name="xyz">The value to set this vector's x, y and z components to.</param>
	constexpr Vector3(float xyz) noexcept;
	
	/// <summary>
	/// Constructs a Vector2 with its components set to the data pointed by <code>data</code>.
	/// This constructor assumes that <code>data</code> is a valid pointer pointing to at least 2 float values.
	/// </summary>
	/// <param name="data">The data where the values for this vector's components are located.</param>
	constexpr explicit Vector3(const float* data) noexcept;

	/// <summary>
	/// Constructs a Vector3 with set component values.
	/// </summary>
	/// <param name="x">The value to set this vector's x components to.</param>
	/// <param name="y">The value to set this vector's y components to.</param>
	/// <param name="z">The value to set this vector's z components to.</param>
	constexpr Vector3(float x, float y, float z) noexcept;

	/// <summary>
	///	Gets a pointer to the first component of this vector.
	/// </summary>
	/// <returns>A pointer to the first component of this vector.</returns>
	[[nodiscard]]
	constexpr const float* Raw() const noexcept;

	/// <summary>
	///	Gets a pointer to the first component of this vector.
	/// </summary>
	/// <returns>A pointer to the first component of this vector.</returns>
	[[nodiscard]]
	constexpr float* Raw() noexcept;

	/// <summary>
	/// Returns the length of the vector.
	/// </summary>
	[[nodiscard]]
	float Length() const noexcept;
	
	/// <summary>
	/// Returns the squared length of the vector.
	/// </summary>
	[[nodiscard]]
	constexpr float SquaredLength() const noexcept;

	/// <summary>
	/// Returns a normalized vector.
	/// </summary>
	/// <returns>A vector with the same direction but a length of one.</returns>
	[[nodiscard]]
	Vector3 Normalized() const noexcept;

	/// <summary>
	/// Returns a normalized vector.
	/// </summary>
	/// <param name="result">
	/// A vector to store the result which is one with the same direction but a length of one.
	/// </param>
	void Normalized(Vector3& result) const noexcept;

	/// <summary>
	///	Check whether all of this vector's components are infinite.
	/// </summary>
	[[nodiscard]]
	bool IsInfinity() const noexcept;

	/// <summary>
	///	Check whether all of this vector's components are NaN.
	/// </summary>
	[[nodiscard]]
	bool IsNaN() const noexcept;

	/// <summary>
	///	Retrieves this vector's component at index i.
	/// </summary>
	/// <param name="i">
	/// The index of the component to get. It would be 0
	/// for x, 1 for y, etc...
	/// </param>
	/// <returns>The value of the component at index i.</returns>
	[[nodiscard]]
	constexpr float operator[](size_t i) const;

	/// <summary>
	///	Retrieves this vector's component at index i.
	/// </summary>
	/// <param name="i">
	/// The index of the component to get. It would be 0
	/// for x, 1 for y, etc...
	/// </param>
	/// <returns>The value of the component at index i.</returns>
	[[nodiscard]]
	constexpr float& operator[](size_t i);
	
    explicit operator Vector2() const noexcept;
	
	explicit operator Vector4() const noexcept;
};

static_assert(std::is_default_constructible_v<Vector3>, "Class Vector3 must be default constructible.");
static_assert(std::is_copy_constructible_v<Vector3>, "Class Vector3 must be copy constructible.");
static_assert(std::is_move_constructible_v<Vector3>, "Class Vector3 must be move constructible.");
static_assert(std::is_copy_assignable_v<Vector3>, "Class Vector3 must be copy assignable.");
static_assert(std::is_move_assignable_v<Vector3>, "Class Vector3 must be move assignable.");

constexpr Vector3::Vector3(const float xyz) noexcept : x(xyz), y(xyz), z(xyz) {}

constexpr Vector3::Vector3(const float* const data) noexcept : x(data[0]), y(data[1]), z(data[2]) {}

constexpr Vector3::Vector3(const float x, const float y, const float z) noexcept : x(x), y(y), z(z) {}

constexpr Vector3 Vector3::Zero() noexcept { return Vector3(); }

constexpr void Vector3::Zero(Vector3& result) noexcept { result = Vector3(); }

constexpr Vector3 Vector3::UnitX() noexcept { return Vector3(1.f, 0.f, 0.f); }

constexpr void Vector3::UnitX(Vector3& result) noexcept { result = Vector3(1.f, 0.f, 0.f); }

constexpr Vector3 Vector3::UnitY() noexcept { return Vector3(0.f, 1.f, 0.f); }

constexpr void Vector3::UnitY(Vector3& result) noexcept { result = Vector3(0.f, 1.f, 0.f); }

constexpr Vector3 Vector3::UnitZ() noexcept { return Vector3(0.f, 0.f, 1.f); }

constexpr void Vector3::UnitZ(Vector3& result) noexcept { result = Vector3(0.f, 0.f, 1.f); }

constexpr float Vector3::Dot(const Vector3& a, const Vector3& b) noexcept { return a.x * b.x + a.y * b.y + a.z * b.z; }

constexpr Vector3 Vector3::Cross(const Vector3& a, const Vector3& b) noexcept { return Vector3(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x); }

constexpr void Vector3::Cross(const Vector3& a, const Vector3& b, Vector3& result) noexcept { result = Vector3(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x); }

constexpr const float* Vector3::Raw() const noexcept { return &x; }

constexpr float* Vector3::Raw() noexcept { return &x; }

constexpr float Vector3::SquaredLength() const noexcept { return SQ(x) + SQ(y) + SQ(z); }

constexpr float Vector3::operator[](const size_t i) const
{
	if (i < 3) [[likely]]
		return *(Raw() + i);
	[[unlikely]]
		throw std::out_of_range("Vector3 subscript out of range");
}

constexpr float& Vector3::operator[](const size_t i)
{
	if (i < 3) [[likely]]
		return *(Raw() + i);
	[[unlikely]]
		throw std::out_of_range("Vector3 subscript out of range");
}

constexpr Vector3 operator+(const Vector3& a, const Vector3& b) noexcept { return Vector3(a.x + b.x, a.y + b.y, a.z + b.z); }

constexpr Vector3 operator-(const Vector3& a) noexcept { return Vector3(-a.x, -a.y, -a.z); }

constexpr Vector3 operator-(const Vector3& a, const Vector3& b) noexcept { return a + -b; }

constexpr Vector3 operator*(const Vector3& a, const Vector3& b) noexcept { return Vector3(a.x * b.x, a.y * b.y, a.z * b.z); }

constexpr Vector3 operator*(const Vector3& v, const float factor) noexcept { return Vector3(v.x * factor, v.y * factor, v.z * factor); }

constexpr Vector3 operator/(const Vector3& a, const Vector3& b) noexcept { return Vector3(a.x / b.x, a.y / b.y, a.z / b.z); }

constexpr Vector3 operator/(const Vector3& v, const float factor) noexcept { const float invFactor = 1.f / factor; return Vector3(v.x * invFactor, v.y * invFactor, v.z * invFactor); }

constexpr Vector3& operator+=(Vector3& a, const Vector3& b) noexcept
{
	a.x += b.x;
	a.y += b.y;
	a.z += b.z;
	
	return a;
}

constexpr Vector3& operator+=(Vector3& v, const float factor) noexcept
{
	v.x += factor;
	v.y += factor;
	v.z += factor;
	
	return v;
}

constexpr Vector3 &operator-=(Vector3 &a, const Vector3& b) noexcept
{
	a.x -= b.x;
	a.y -= b.y;
	a.z -= b.z;
	
	return a;
}

constexpr Vector3& operator-=(Vector3& v, const float factor) noexcept
{
	v.x -= factor;
	v.y -= factor;
	v.z -= factor;
	
	return v;
}

constexpr Vector3& operator*=(Vector3& a, const Vector3& b) noexcept
{
	a.x *= b.x;
	a.y *= b.y;
	a.z *= b.z;
	
	return a;
}

constexpr Vector3& operator*=(Vector3& v, const float factor) noexcept
{
	v.x *= factor;
	v.y *= factor;
	v.z *= factor;
	
	return v;
}

constexpr Vector3 &operator/=(Vector3 &a, const Vector3& b) noexcept
{
	a.x /= b.x;
	a.y /= b.y;
	a.z /= b.z;
	
	return a;
}

constexpr Vector3& operator/=(Vector3& v, const float factor) noexcept
{
	const float invFactor = 1.f / factor;
	
	v.x *= invFactor;
	v.y *= invFactor;
	v.z *= invFactor;
	
	return v;
}

/// <summary>
///	Checks if two Vector3 are considered equal using <code>Calc::Equals</code>.
/// </summary>
[[nodiscard]]
constexpr bool operator==(const Vector3 a, const Vector3 b) noexcept
{
	return Calc::Equals(a.x, b.x)
		&& Calc::Equals(a.y, b.y)
		&& Calc::Equals(a.z, b.z);
}

/// <summary>
///	Checks if two Vector3 are considered different using <code>Calc::Equals</code>.
/// </summary>
[[nodiscard]]
constexpr bool operator!=(const Vector3 a, const Vector3 b) noexcept { return !(a == b); }

std::ostream& operator<<(std::ostream& out, const Vector3& v) noexcept;

constexpr Vector3 Vector3::Lerp(const Vector3& value, const Vector3& target, const float t) noexcept { return value + (target - value) * t; }

constexpr void Vector3::Lerp(const Vector3& value, const Vector3& target, const float t, Vector3& result) noexcept { result = value + (target - value) * t; }

using vec3 = Vector3;
