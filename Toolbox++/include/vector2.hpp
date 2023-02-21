#pragma once

#include <ostream>
#include <compare>
#include <cassert>

/// @brief The Vector2 class represents either a two-dimensional vector or a point.
class Vector2
{
public:
	float x, y;

	constexpr Vector2()	: x(0), y(0) {}
	/// @brief Constructs a Vector2 with both its components set to 'xy'.
	constexpr Vector2(const float xy) : x(xy), y(xy) {}
	constexpr Vector2(const float x, const float y) : x(x), y(y) {}
	constexpr Vector2(const std::initializer_list<float>& values)
	{
		assert(values.size() == 2 && "Cannot initialize Vector2 from initializer list with size != 2");

		const float* it = values.begin();
		x = it[0];
		y = it[1];
	}
	/// @brief Constructs a Vector2 from point 'p1' to point 'p2'
	Vector2(const Vector2 p1, const Vector2 p2);
	~Vector2() {}

	/// @brief Returns the length of the vector.
	float Norm() const;
	/// @brief Returns the squared length of the vector.
	float SquaredNorm() const;
	/// @brief Normalizes the vector.
	/// @return A vector with the same direction but a length of one.
	Vector2 Normalize() const;
	/// @brief Returns the normal vector to this one.
	/// @return A vector with the same length but a normal direction.
	Vector2 Normal() const;
	/// @brief Returns the angle between the beginning and the end of this vector.
	/// @return An angle in radians.
	float Angle() const;
	/// @brief Rotates the vector by the specified angle.
	/// @param angle The angle in radians.
	Vector2 Rotate(const float angle) const;
	/// @brief Rotates the vector by the specified angle around a center.
	/// @param angle The angle in radians.
	Vector2 Rotate(const float angle, const Vector2 center) const;
	Vector2 Rotate(const float cos, const float sin) const;
	Vector2 Rotate(const Vector2 center, const float cos, const float sin) const;

	/// @brief Returns the angle between 'a' and 'b'.
	static float Angle(const Vector2 a, const Vector2 b);
	/// @brief Returns a · b.
	static float DotProduct(const Vector2 a, const Vector2 b);
	/// @brief Returns a x b.
	static float CrossProduct(const Vector2 a, const Vector2 b);
	/// @brief Returns the determinant of 'a' and 'b'.
	static float Determinant(const Vector2 a, const Vector2 b);

	friend auto operator<=>(const Vector2& a, const Vector2& b) = default;
};

Vector2 operator+(const Vector2 a, const Vector2 b);
Vector2 operator-(const Vector2 a, const Vector2 b);
Vector2 operator-(const Vector2 a);
Vector2 operator*(const Vector2 a, const Vector2 b);
Vector2 operator*(const Vector2 v, const float factor);
Vector2 operator/(const Vector2 a, const Vector2 b);
Vector2 operator/(const Vector2 v, const float factor);

Vector2& operator+=(Vector2& a, const Vector2 b);
Vector2& operator+=(Vector2& v, const float factor);
Vector2& operator-=(Vector2& a, const Vector2 b);
Vector2& operator-=(Vector2& v, const float factor);
Vector2& operator*=(Vector2& a, const Vector2 b);
Vector2& operator*=(Vector2& v, const float factor);
Vector2& operator/=(Vector2& a, const Vector2 b);
Vector2& operator/=(Vector2& v, const float factor);

std::ostream& operator<<(std::ostream& out, const Vector2 v);
