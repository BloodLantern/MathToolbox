#pragma once

#include <ostream>
#include <type_traits>

class Vector2;
class Vector3;
class Vector4;
class Matrix2x2;

/// @brief The Vector2i class represents either a two-dimensional vector or a point.
class Vector2i
{
public:
	int x, y;

	static constexpr Vector2i UnitX() { return Vector2i(1, 0); }
	
	static constexpr Vector2i UnitY() { return Vector2i(0, 1); }

	constexpr Vector2i() : x(0), y(0) {}
	
	/// @brief Constructs a Vector2i with both its components set to 'xy'.
	constexpr Vector2i(const int xy) : x(xy), y(xy) {}
	
	constexpr Vector2i(const int x, const int y) : x(x), y(y) {}

	/// @brief Returns the length of the vector.
	[[nodiscard]]
	float Length() const;
	
	/// @brief Returns the squared length of the vector.
	[[nodiscard]]
	float SquaredLength() const;
	
	/// @brief Returns a normalized vector.
	/// @return A vector with the same direction but a length of one.
	[[nodiscard]]
	Vector2 Normalized() const;
	
	/// @brief Returns the normal vector to this one.
	/// @return A vector with the same length but a normal direction.
	[[nodiscard]]
	Vector2 Normal() const;
	
	/// @brief Returns the dot product of this Vector2i with 'other'.
	[[nodiscard]]
	float Dot(Vector2i other) const;
	
	/// @brief Returns the cross product of this Vector2i with 'other'.
	[[nodiscard]]
	float Cross(Vector2i other) const;
	
	/// @brief Returns the determinant of this Vector2i with 'other'.
	[[nodiscard]]
	float Determinant(Vector2i other) const;
	
	/// @brief Returns the angle between the beginning and the end of this vector.
	/// @return An angle in radians.
	[[nodiscard]]
	float Angle() const;
	
	/// @brief Rotates the vector by the specified angle.
	/// @param angle The angle in radians.
	[[nodiscard]]
	Vector2 Rotate(float angle) const;
	
	/// @brief Rotates the vector by the specified angle around a center.
	/// @param angle The angle in radians.
	[[nodiscard]]
	Vector2 Rotate(float angle, Vector2i center) const;
	
	/// @brief Rotates the vector by the specified cosine and sine around a center.
	/// @param cos The cosine of the angle in radians.
	/// @param sin The sine of the angle in radians.
	[[nodiscard]]
	Vector2 Rotate(float cos, float sin) const;
	
	/// @brief Rotates the vector by the specified cosine and sine.
	/// @param cos The cosine of the angle in radians.
	/// @param sin The sine of the angle in radians.
	[[nodiscard]]
	Vector2 Rotate(Vector2i center, float cos, float sin) const;

	/// @brief Returns the angle between 'a' and 'b'.
	[[nodiscard]]
	static float Angle(Vector2i a, Vector2i b);
	
	/// @brief Returns a · b.
	[[nodiscard]]
	static float Dot(Vector2i a, Vector2i b);
	
	/// @brief Returns a x b.
	[[nodiscard]]
	static float Cross(Vector2i a, Vector2i b);
	
	/// @brief Returns the determinant of 'a' and 'b'.
	[[nodiscard]]
	static float Determinant(Vector2i a, Vector2i b);

	[[nodiscard]]
	int  operator[](size_t i) const;
	
	[[nodiscard]]
	int& operator[](size_t i);
	
    operator Vector2() const;
	
    operator Vector3() const;
	
    operator Vector4() const;
	
    explicit operator Matrix2x2() const;
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

std::ostream& operator<<(std::ostream& out, Vector2i v);

using vec2i = Vector2i;
