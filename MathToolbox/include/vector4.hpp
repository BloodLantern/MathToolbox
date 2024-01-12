#pragma once

#include <ostream>

#include "calc.hpp"
#include "vector3.hpp"

class Vector2;
class Matrix;

/// <summary>
/// The Vector4 class represents either a four-dimensional vector or a point.
/// </summary>
class Vector4
{
public:
	float x = 0.f, y = 0.f, z = 0.f, w = 0.f;

	/// <summary>
	///	Equivalent to calling the default constructor.
	/// </summary>
	[[nodiscard]]
	static constexpr Vector4 Zero() noexcept;

	static constexpr Vector4 UnitX() noexcept;

	static constexpr Vector4 UnitY() noexcept;

	static constexpr Vector4 UnitZ() noexcept;

	static constexpr Vector4 UnitW() noexcept;

	constexpr Vector4() = default;

	/// <summary>
	/// Constructs a Vector4 with all its components set to 'xyzw'.
	/// </summary>
	constexpr Vector4(float xyzw) noexcept;

	/// <summary>
	/// Constructs a Vector3 with set component values.
	/// </summary>
	/// <param name="x">The value to set this vector's x components to.</param>
	/// <param name="y">The value to set this vector's y components to.</param>
	/// <param name="z">The value to set this vector's z components to.</param>
	constexpr Vector4(float x, float y, float z, float w) noexcept;

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
	Vector4 Normalized() const noexcept;

	/// <summary>
	/// Returns a · b.
	/// </summary>
	[[nodiscard]]
	static constexpr float Dot(const Vector4& a, const Vector4& b) noexcept;

	/// <summary>
	/// Lerp between two positions in a 4-dimensional space.
	/// </summary>
	/// <param name="value">The current position.</param>
	/// <param name="target">The target position.</param>
	/// <param name="t">The time to lerp.</param>
	/// <returns>The lerp position.</returns>
	[[nodiscard]]
	static constexpr Vector4 Lerp(const Vector4& value, const Vector4& target, float t) noexcept;

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
	
    explicit operator Vector3() const noexcept;
	
	explicit operator Matrix() const noexcept;
};

static_assert(std::is_default_constructible_v<Vector4>, "Class Vector4 must be default constructible.");
static_assert(std::is_copy_constructible_v<Vector4>, "Class Vector4 must be copy constructible.");
static_assert(std::is_move_constructible_v<Vector4>, "Class Vector4 must be move constructible.");
static_assert(std::is_copy_assignable_v<Vector4>, "Class Vector4 must be copy assignable.");
static_assert(std::is_move_assignable_v<Vector4>, "Class Vector4 must be move assignable.");

constexpr Vector4::Vector4(const float xyzw) noexcept : x(xyzw), y(xyzw), z(xyzw), w(xyzw) {}

constexpr Vector4::Vector4(const float x, const float y, const float z, const float w) noexcept : x(x), y(y), z(z), w(w) {}

constexpr Vector4 Vector4::Zero() noexcept { return Vector4(); }

constexpr Vector4 Vector4::UnitX() noexcept { return Vector4(1.f, 0.f, 0.f, 0.f); }

constexpr Vector4 Vector4::UnitY() noexcept { return Vector4(0.f, 1.f, 0.f, 0.f); }

constexpr Vector4 Vector4::UnitZ() noexcept { return Vector4(0.f, 0.f, 1.f, 0.f); }

constexpr Vector4 Vector4::UnitW() noexcept { return Vector4(0.f, 0.f, 0.f, 1.f); }

constexpr const float* Vector4::Raw() const noexcept { return &x; }

constexpr float* Vector4::Raw() noexcept { return &x; }

constexpr float Vector4::SquaredLength() const noexcept { return SQ(x) + SQ(y) + SQ(z) + SQ(w); }

constexpr float Vector4::Dot(const Vector4& a, const Vector4& b) noexcept {	return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w; }

constexpr float Vector4::operator[](const size_t i) const
{
	if (i < 4) [[likely]]
		return *(Raw() + i);
	else [[unlikely]]
		throw std::out_of_range("Vector4 subscript out of range");
}

constexpr float& Vector4::operator[](const size_t i)
{
	if (i < 4) [[likely]]
		return *(Raw() + i);
	else [[unlikely]]
		throw std::out_of_range("Vector4 subscript out of range");
}

constexpr Vector4 operator+(const Vector4& a, const Vector4& b) noexcept { return Vector4(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w); }

constexpr Vector4 operator-(const Vector4& a) noexcept { return Vector4(-a.x, -a.y, -a.z, -a.w); }

constexpr Vector4 operator-(const Vector4& a, const Vector4& b) noexcept { return a + -b; }

constexpr Vector4 operator*(const Vector4& a, const Vector4& b) noexcept { return Vector4(a.x * b.x, a.y * b.y, a.z * b.z, a.w * b.w); }

constexpr Vector4 operator*(const Vector4& v, const float factor) noexcept { return Vector4(v.x * factor, v.y * factor, v.z * factor, v.w * factor); }

constexpr Vector4 operator/(const Vector4& a, const Vector4& b) noexcept { return Vector4(a.x / b.x, a.y / b.y, a.z / b.z, a.w / b.w); }

constexpr Vector4 operator/(const Vector4& v, const float factor) noexcept { return Vector4(v.x / factor, v.y / factor, v.z / factor, v.w / factor); }

constexpr Vector4& operator+=(Vector4& a, const Vector4& b) noexcept
{
	a.x += b.x;
	a.y += b.y;
    a.z += b.z;
    a.w += b.w;
	
	return a;
}

constexpr Vector4& operator+=(Vector4& v, const float factor) noexcept
{
	v.x += factor;
	v.y += factor;
    v.z += factor;
    v.w += factor;
	
	return v;
}

constexpr Vector4 &operator-=(Vector4 &a, const Vector4& b) noexcept
{
	a.x -= b.x;
	a.y -= b.y;
    a.z -= b.z;
    a.w -= b.w;
	
	return a;
}

constexpr Vector4& operator-=(Vector4& v, const float factor) noexcept
{
	v.x -= factor;
	v.y -= factor;
    v.z -= factor;
    v.w -= factor;
	
	return v;
}

constexpr Vector4& operator*=(Vector4& a, const Vector4& b) noexcept
{
	a.x *= b.x;
	a.y *= b.y;
    a.z *= b.z;
    a.w *= b.w;
	
	return a;
}

constexpr Vector4& operator*=(Vector4& v, const float factor) noexcept
{
	v.x *= factor;
	v.y *= factor;
    v.z *= factor;
    v.w *= factor;
	
	return v;
}

constexpr Vector4 &operator/=(Vector4 &a, const Vector4& b) noexcept
{
	a.x /= b.x;
	a.y /= b.y;
    a.z /= b.z;
    a.w /= b.w;
	
	return a;
}

constexpr Vector4& operator/=(Vector4& v, const float factor) noexcept
{
	v.x /= factor;
	v.y /= factor;
    v.z /= factor;
    v.w /= factor;
	
	return v;
}

/// <summary>
///	Checks if two Vector4 are considered equal using <code>calc::Equals</code>.
/// </summary>
[[nodiscard]]
constexpr bool operator==(const Vector4 a, const Vector4 b) noexcept
{
	return calc::Equals(a.x, b.x)
		&& calc::Equals(a.y, b.y)
		&& calc::Equals(a.z, b.z)
		&& calc::Equals(a.w, b.w);
}

/// <summary>
///	Checks if two Vector4 are considered different using <code>calc::Equals</code>.
/// </summary>
[[nodiscard]]
constexpr bool operator!=(const Vector4 a, const Vector4 b) noexcept { return !(a == b); }

std::ostream& operator<<(std::ostream& out, const Vector4& v) noexcept;

constexpr Vector4 Vector4::Lerp(const Vector4& value, const Vector4& target, const float t) noexcept { return value + (target - value) * t; }

using vec4 = Vector4;
