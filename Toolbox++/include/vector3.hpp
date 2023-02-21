#pragma once

#include <ostream>
#include <compare>
#include <cassert>

/// @brief The Vector3 class represents either a two-dimensional vector or a point.
class Vector3
{
public:
	float x, y, z;

	constexpr Vector3()	: x(0), y(0), z(0) {}
	/// @brief Constructs a Vector3 with both its components set to 'xy'.
	constexpr Vector3(const float xyz) : x(xyz), y(xyz), z(xyz) {}
	constexpr Vector3(const float x, const float y, const float z) : x(x), y(y), z(z) {}
	constexpr Vector3(const std::initializer_list<float>& values)
	{
		assert(values.size() == 3 && "Cannot initialize Vector3 from initializer list with size != 3");

		const float* it = values.begin();
		x = it[0];
		y = it[1];
		z = it[2];
	}
	/// @brief Constructs a Vector3 from point 'p1' to point 'p2'
	Vector3(const Vector3& p1, const Vector3& p2);
	~Vector3() {}

	/// @brief Returns the length of the vector.
	float Norm() const;
	/// @brief Returns the squared length of the vector.
	float SquaredNorm() const;
	/// @brief Normalizes the vector.
	/// @return A vector with the same direction but a length of one.
	Vector3 Normalize() const;

	/// @brief Returns the angle between 'a' and 'b'.
	static float Angle(const Vector3& a, const Vector3& b);
	/// @brief Returns a · b.
	static float DotProduct(const Vector3& a, const Vector3& b);
	/// @brief Returns a x b.
	static Vector3 CrossProduct(const Vector3& a, const Vector3& b);
	/// @brief Returns the determinant of 'a' and 'b'.
	static float Determinant(const Vector3& a, const Vector3& b);

	friend auto operator<=>(const Vector3& a, const Vector3& b) = default;
};

Vector3 operator+(const Vector3& a, const Vector3& b);
Vector3 operator-(const Vector3& a, const Vector3& b);
Vector3 operator-(const Vector3& a);
Vector3 operator*(const Vector3& a, const Vector3& b);
Vector3 operator*(const Vector3& v, const float factor);
Vector3 operator/(const Vector3& a, const Vector3& b);
Vector3 operator/(const Vector3& v, const float factor);

Vector3& operator+=(Vector3& a, const Vector3& b);
Vector3& operator+=(Vector3& v, const float factor);
Vector3& operator-=(Vector3& a, const Vector3& b);
Vector3& operator-=(Vector3& v, const float factor);
Vector3& operator*=(Vector3& a, const Vector3& b);
Vector3& operator*=(Vector3& v, const float factor);
Vector3& operator/=(Vector3& a, const Vector3& b);
Vector3& operator/=(Vector3& v, const float factor);

std::ostream& operator<<(std::ostream& out, const Vector3& v);
