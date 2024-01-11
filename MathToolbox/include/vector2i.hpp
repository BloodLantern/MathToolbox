#pragma once

#include <ostream>
#include <type_traits>

class Vector2;
class Vector3;
class Vector4;

/// <summary>
/// The Vector2i class represents either a two-dimensional vector or a point.
/// </summary>
class Vector2i
{
public:
	int x, y;

	/// <summary>
	///	Equivalent to calling the default constructor.
	/// </summary>
	[[nodiscard]]
	
	static constexpr Vector2i Zero();

	[[nodiscard]]
	
	static constexpr Vector2i UnitX();

	[[nodiscard]]
	
	static constexpr Vector2i UnitY();

	constexpr Vector2i();

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
	
	constexpr const int* Raw() const;

	/// <summary>
	///	Gets a pointer to the first component of this vector.
	/// </summary>
	/// <returns>A pointer to the first component of this vector.</returns>
	[[nodiscard]]
	
	constexpr int* Raw();

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
	/// Returns the dot product of this Vector2i with 'other'.
	/// </summary>
	[[nodiscard]]
	float Dot(Vector2i other) const;
	
	/// <summary>
	/// Returns the cross product of this Vector2i with 'other'.
	/// </summary>
	[[nodiscard]]
	float Cross(Vector2i other) const;
	
	/// <summary>
	/// Returns the determinant of this Vector2i with 'other'.
	/// </summary>
	[[nodiscard]]
	float Determinant(Vector2i other) const;
	
	/// <summary>
	/// Returns a · b.
	/// </summary>
	[[nodiscard]]
	static float Dot(Vector2i a, Vector2i b);
	
	/// <summary>
	/// Returns a x b.
	/// </summary>
	[[nodiscard]]
	static float Cross(Vector2i a, Vector2i b);
	
	/// <summary>
	/// Returns the determinant of 'a' and 'b'.
	/// </summary>
	[[nodiscard]]
	static float Determinant(Vector2i a, Vector2i b);

	/// <summary>
	///	Retrieves this vector's component at index i.
	/// </summary>
	/// <param name="i">
	/// The index of the component to get. It would be 0
	/// for x, 1 for y, etc...
	/// </param>
	/// <returns>The value of the component at index i.</returns>
	[[nodiscard]]
	int operator[](size_t i) const;
	
	
	/// <summary>
	///	Retrieves this vector's component at index i.
	/// </summary>
	/// <param name="i">
	/// The index of the component to get. It would be 0
	/// for x, 1 for y, etc...
	/// </param>
	/// <returns>The value of the component at index i.</returns>
	[[nodiscard]]
	int& operator[](size_t i);
	
    explicit operator Vector2() const;
	
    explicit operator Vector3() const;
	
    explicit operator Vector4() const;
};

static_assert(std::is_default_constructible_v<Vector2i>, "Class Vector2i must be default constructible.");
static_assert(std::is_copy_constructible_v<Vector2i>, "Class Vector2i must be copy constructible.");
static_assert(std::is_move_constructible_v<Vector2i>, "Class Vector2i must be move constructible.");
static_assert(std::is_copy_assignable_v<Vector2i>, "Class Vector2i must be copy assignable.");
static_assert(std::is_move_assignable_v<Vector2i>, "Class Vector2i must be move assignable.");

[[nodiscard]]
Vector2i operator+(Vector2i a, Vector2i b);

[[nodiscard]]
Vector2i operator-(Vector2i a, Vector2i b);

[[nodiscard]]
Vector2i operator-(Vector2i a);

[[nodiscard]]
Vector2i operator*(Vector2i a, Vector2i b);

[[nodiscard]]
Vector2i operator*(Vector2i v, int factor);

[[nodiscard]]
Vector2 operator/(Vector2i a, Vector2i b);

[[nodiscard]]
Vector2 operator/(Vector2i v, float factor);

Vector2i& operator+=(Vector2i& a, Vector2i b);

Vector2i& operator+=(Vector2i& v, int factor);

Vector2i& operator-=(Vector2i& a, Vector2i b);

Vector2i& operator-=(Vector2i& v, int factor);

Vector2i& operator*=(Vector2i& a, Vector2i b);

Vector2i& operator*=(Vector2i& v, int factor);

bool operator==(Vector2i a, Vector2i b);

bool operator!=(Vector2i a, Vector2i b);

std::ostream& operator<<(std::ostream& out, Vector2i v);

using vec2i = Vector2i;
