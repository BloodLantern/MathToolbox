#pragma once

#include <ostream>
#include <type_traits>

class Vector2i;
class Vector3;
class Vector4;
class Matrix2x2;

/// <summary>
/// The Vector2 class represents either a two-dimensional vector or a point.
/// </summary>
class Vector2
{
public:
	float x, y;

	static constexpr Vector2 Zero();
	
	static constexpr Vector2 UnitX();
	
	static constexpr Vector2 UnitY();

	/// <summary>
	/// Constructs a Vector2 with both its components set to 0.
	/// </summary>
	constexpr Vector2() = default;
	
	/// <summary>
	/// Constructs a Vector2 with both its components set to 'xy'.
	/// </summary>
	/// <param name="xy">The value to set this vector's x and y components to.</param>
	constexpr Vector2(float xy);
	
	/// <summary>
	/// Constructs a Vector2 with set component values.
	/// </summary>
	/// <param name="x">The value to set this vector's x components to.</param>
	/// <param name="y">The value to set this vector's y components to.</param>
	constexpr Vector2(float x, float y);

	/// <summary>
	///	Gets a pointer to the first component of this vector.
	/// </summary>
	/// <returns>A pointer to the first component of this vector.</returns>
	[[nodiscard]]
	__forceinline
	constexpr const float* Raw() const;

	/// <summary>
	///	Gets a pointer to the first component of this vector.
	/// </summary>
	/// <returns>A pointer to the first component of this vector.</returns>
	[[nodiscard]]
	__forceinline
	constexpr float* Raw();

	/// <summary>
	/// Returns the length of the vector.
	/// </summary>
	[[nodiscard]]
	float Length() const;
	
	/// <summary>
	/// Returns the squared length of the vector.
	/// </summary>
	[[nodiscard]]
	float SquaredLength() const;
	
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
	/// Returns the dot product of this Vector2 with 'other'.
	/// </summary>
	[[nodiscard]]
	float Dot(Vector2 other) const;
	
	/// <summary>
	/// Returns the cross product of this Vector2 with 'other'.
	/// </summary>
	[[nodiscard]]
	float Cross(Vector2 other) const;
	
	/// <summary>
	/// Returns the determinant of this Vector2 with 'other'.
	/// </summary>
	[[nodiscard]]
	float Determinant(Vector2 other) const;

	/// <summary>
	/// Returns a · b.
	/// </summary>
	[[nodiscard]]
	static float Dot(Vector2 a, Vector2 b);
	
	/// <summary>
	/// Returns a x b.
	/// </summary>
	[[nodiscard]]
	static float Cross(Vector2 a, Vector2 b);
	
	/// <summary>
	/// Returns the determinant of 'a' and 'b'.
	/// </summary>
	[[nodiscard]]
	static float Determinant(Vector2 a, Vector2 b);

	/// <summary>
	/// Lerp between two positions in a 2-dimensional space.
	/// </summary>
	/// <param name="value">The current position.</param>
	/// <param name="target">The target position.</param>
	/// <param name="t">The time to lerp.</param>
	/// <returns>The lerp position.</returns>
	[[nodiscard]]
	static Vector2 Lerp(Vector2 value, Vector2 target, float t);

	/// <summary>
	///	Retrieves this vector's component at index i.
	/// </summary>
	/// <param name="i">The index of the component to get. It would be 0
	/// for x, 1 for y, etc...</param>
	/// <returns>The value of the component at index i.</returns>
	[[nodiscard]]
	float operator[](size_t i) const;
	
	/// <summary>
	///	Retrieves this vector's component at index i.
	/// </summary>
	/// <param name="i">The index of the component to get. It would be 0
	/// for x, 1 for y, etc...</param>
	/// <returns>The value of the component at index i.</returns>
	[[nodiscard]]
	float& operator[](size_t i);
	
	explicit operator Vector2i() const;
	
	explicit operator Vector3() const;
	
	explicit operator Vector4() const;
	
	explicit operator Matrix2x2() const;
};

static_assert(std::is_default_constructible_v<Vector2>, "Class Vector2 must be default constructible.");
static_assert(std::is_copy_constructible_v<Vector2>, "Class Vector2 must be copy constructible.");
static_assert(std::is_move_constructible_v<Vector2>, "Class Vector2 must be move constructible.");
static_assert(std::is_copy_assignable_v<Vector2>, "Class Vector2 must be copy assignable.");
static_assert(std::is_move_assignable_v<Vector2>, "Class Vector2 must be move assignable.");

[[nodiscard]]
Vector2 operator+(Vector2 a, Vector2 b);

[[nodiscard]]
Vector2 operator-(Vector2 a, Vector2 b);

[[nodiscard]]
Vector2 operator-(Vector2 a);

[[nodiscard]]
Vector2 operator*(Vector2 a, Vector2 b);

[[nodiscard]]
Vector2 operator*(Vector2 v, float factor);

[[nodiscard]]
Vector2 operator*(const Matrix2x2& m, const Vector2& v);

[[nodiscard]]
Vector2 operator/(Vector2 a, Vector2 b);

[[nodiscard]]
Vector2 operator/(Vector2 v, float factor);

Vector2& operator+=(Vector2& a, Vector2 b);

Vector2& operator+=(Vector2& v, float factor);

Vector2& operator-=(Vector2& a, Vector2 b);

Vector2& operator-=(Vector2& v, float factor);

Vector2& operator*=(Vector2& a, Vector2 b);

Vector2& operator*=(Vector2& v, float factor);

Vector2& operator*=(const Matrix2x2& m, Vector2& v);

Vector2& operator/=(Vector2& a, Vector2 b);

Vector2& operator/=(Vector2& v, float factor);

std::ostream& operator<<(std::ostream& out, Vector2 v);

using vec2 = Vector2;
