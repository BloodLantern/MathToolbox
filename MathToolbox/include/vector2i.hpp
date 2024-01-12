#pragma once

#include <ostream>

#include "vector2.hpp"

class Vector3;
class Vector4;

/// <summary>
/// The Vector2i class represents either a two-dimensional vector or a point.
/// </summary>
class Vector2i
{
public:
	int x = 0, y = 0;

	/// <summary>
	///	Equivalent to calling the default constructor.
	/// </summary>
	[[nodiscard]]
	static constexpr Vector2i Zero() noexcept;

	[[nodiscard]]
	static constexpr Vector2i UnitX() noexcept;

	[[nodiscard]]
	static constexpr Vector2i UnitY() noexcept;

	constexpr Vector2i() = default;

	/// <summary>
	/// Constructs a Vector2i with both its components set to 'xy'.
	/// </summary>
	constexpr Vector2i(int xy);

	constexpr Vector2i(int x, int y);

	/// <summary>
	///	Gets a pointer to the first component of this vector.
	/// </summary>
	/// <returns>A pointer to the first component of this vector.</returns>
	[[nodiscard]]
	constexpr const int* Raw() const noexcept;

	/// <summary>
	///	Gets a pointer to the first component of this vector.
	/// </summary>
	/// <returns>A pointer to the first component of this vector.</returns>
	[[nodiscard]]
	constexpr int* Raw() noexcept;

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
	Vector2 Normalized() const;
	
	/// <summary>
	/// Returns the normal vector to this one.
	/// </summary>
	/// <returns>A vector with the same length but a normal direction.</returns>
	[[nodiscard]]
	Vector2 Normal() const;
	
	/// <summary>
	/// Returns a · b.
	/// </summary>
	[[nodiscard]]
	static constexpr float Dot(Vector2i a, Vector2i b) noexcept;
	
	/// <summary>
	/// Returns a x b.
	/// For a Vector2i this is only the determinant.
	/// </summary>
	[[nodiscard]]
	static constexpr float Cross(Vector2i a, Vector2i b) noexcept;
	
	/// <summary>
	/// Returns the determinant of 'a' and 'b'.
	/// </summary>
	[[nodiscard]]
	static constexpr float Determinant(Vector2i a, Vector2i b) noexcept;

	/// <summary>
	///	Retrieves this vector's component at index i.
	/// </summary>
	/// <param name="i">
	/// The index of the component to get. It would be 0
	/// for x, 1 for y, etc...
	/// </param>
	/// <returns>The value of the component at index i.</returns>
	[[nodiscard]]
	constexpr int operator[](size_t i) const;
	
	
	/// <summary>
	///	Retrieves this vector's component at index i.
	/// </summary>
	/// <param name="i">
	/// The index of the component to get. It would be 0
	/// for x, 1 for y, etc...
	/// </param>
	/// <returns>The value of the component at index i.</returns>
	[[nodiscard]]
	constexpr int& operator[](size_t i);
	
    explicit operator Vector2() const;
	
    explicit operator Vector3() const;
	
    explicit operator Vector4() const;
};

static_assert(std::is_default_constructible_v<Vector2i>, "Class Vector2i must be default constructible.");
static_assert(std::is_copy_constructible_v<Vector2i>, "Class Vector2i must be copy constructible.");
static_assert(std::is_move_constructible_v<Vector2i>, "Class Vector2i must be move constructible.");
static_assert(std::is_copy_assignable_v<Vector2i>, "Class Vector2i must be copy assignable.");
static_assert(std::is_move_assignable_v<Vector2i>, "Class Vector2i must be move assignable.");

constexpr Vector2i::Vector2i(const int xy): x(xy), y(xy) {}

constexpr Vector2i::Vector2i(const int x, const int y): x(x), y(y) {}

constexpr Vector2i Vector2i::Zero() noexcept { return Vector2i(); }

constexpr Vector2i Vector2i::UnitX() noexcept { return Vector2i(1, 0); }

constexpr Vector2i Vector2i::UnitY() noexcept { return Vector2i(0, 1); }

constexpr const int* Vector2i::Raw() const noexcept { return &x; }

constexpr int* Vector2i::Raw() noexcept { return &x; }

constexpr float Vector2i::SquaredLength() const noexcept { return static_cast<float>(x * x + y * y); }

constexpr float Vector2i::Dot(const Vector2i a, const Vector2i b) noexcept { return static_cast<float>(a.x * b.x + a.y * b.y); }

constexpr float Vector2i::Cross(const Vector2i a, const Vector2i b) noexcept { return Determinant(a, b); }

constexpr float Vector2i::Determinant(const Vector2i a, const Vector2i b) noexcept { return static_cast<float>(a.x * b.y - b.x * a.y); }

constexpr int Vector2i::operator[](size_t i) const
{
	if (i < 2) [[likely]]
		return *(Raw() + i);
	else [[unlikely]]
		throw std::out_of_range("Vector2i subscript out of range");
}

constexpr int& Vector2i::operator[](size_t i)
{
	if (i < 2) [[likely]]
		return *(Raw() + i);
	else [[unlikely]]
		throw std::out_of_range("Vector2i subscript out of range");
}

constexpr Vector2i operator+(const Vector2i a, const Vector2i b) noexcept { return Vector2i(a.x + b.x, a.y + b.y); }

constexpr Vector2i operator-(const Vector2i a) noexcept { return Vector2i(-a.x, -a.y); }

constexpr Vector2i operator-(const Vector2i a, const Vector2i b) noexcept { return a + -b; }

constexpr Vector2i operator*(const Vector2i a, const Vector2i b) noexcept { return Vector2i(a.x * b.x, a.y * b.y); }

constexpr Vector2i operator*(const Vector2i v, const int factor) noexcept { return Vector2i(v.x * factor, v.y * factor); }

constexpr Vector2 operator/(const Vector2i a, const Vector2i b) noexcept { return Vector2(static_cast<float>(a.x) / static_cast<float>(b.x), static_cast<float>(a.y) / static_cast<float>(b.y)); }

constexpr Vector2 operator/(const Vector2i v, const float factor) noexcept { return Vector2(static_cast<float>(v.x) / factor, static_cast<float>(v.y) / factor); }

constexpr Vector2i& operator+=(Vector2i& a, const Vector2i b) noexcept
{
	a.x += b.x;
	a.y += b.y;
	
	return a;
}

constexpr Vector2i& operator+=(Vector2i& v, const int factor) noexcept
{
	v.x += factor;
	v.y += factor;
	
	return v;
}

constexpr Vector2i &operator-=(Vector2i &a, const Vector2i b) noexcept
{
	a.x -= b.x;
	a.y -= b.y;
	
	return a;
}

constexpr Vector2i& operator-=(Vector2i& v, const int factor) noexcept
{
	v.x -= factor;
	v.y -= factor;
	
	return v;
}

constexpr Vector2i& operator*=(Vector2i& a, const Vector2i b) noexcept
{
	a.x *= b.x;
	a.y *= b.y;
	
	return a;
}

constexpr Vector2i& operator*=(Vector2i& v, const int factor) noexcept
{
	v.x *= factor;
	v.y *= factor;
	
	return v;
}

bool operator==(Vector2i a, Vector2i b) noexcept;

bool operator!=(Vector2i a, Vector2i b) noexcept;

std::ostream& operator<<(std::ostream& out, Vector2i v) noexcept;

using vec2i = Vector2i;
