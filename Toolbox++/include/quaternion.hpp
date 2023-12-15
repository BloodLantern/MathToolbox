#pragma once

#include "vector3.hpp"
#include "vector4.hpp"
#include "vector.hpp"

#include <ostream>

class Quaternion
{
public:
	Vector3 imaginary;
	float real;

	static constexpr Quaternion Zero();
	static constexpr Quaternion UnitX();
	static constexpr Quaternion UnitY();
	static constexpr Quaternion UnitZ();
	static constexpr Quaternion UnitW();
	static constexpr Quaternion Identity();

	constexpr Quaternion();
	constexpr Quaternion(const Vector4& values);
	constexpr Quaternion(const Vector3& imaginary, const float real);
	constexpr Quaternion(const float xyzw);
	constexpr Quaternion(const float x, const float y, const float z, const float w);
	/// @brief Used to create a Quaternion from an euler rotation if 3 floats are given
	/// or an exact Quaternion if 4 floats are given instead.
	constexpr Quaternion(const std::initializer_list<float>& values);
	constexpr Quaternion(const Vector3& rotation);
	constexpr Quaternion(const float xRotation, const float yRotation, const float zRotation);

	__forceinline constexpr float X() const;
	__forceinline constexpr float Y() const;
	__forceinline constexpr float Z() const;
	__forceinline constexpr float W() const;

	__forceinline constexpr float& X();
	__forceinline constexpr float& Y();
	__forceinline constexpr float& Z();
	__forceinline constexpr float& W();

	constexpr Quaternion Conjugate() const;
	float Length() const;
	constexpr float SquaredLength() const;
	constexpr Quaternion Inverse() const;

	[[nodiscard]]
	constexpr float  operator[](const size_t i) const;
	[[nodiscard]]
	constexpr float& operator[](const size_t i);
	constexpr explicit operator Vector<4>() const;
	constexpr explicit operator Vector4() const;

	// Automatically generates all comparison operators
	[[nodiscard]]
	friend auto operator<=>(const Quaternion& a, const Quaternion& b) = default;
};

[[nodiscard]]
Quaternion operator+(const Quaternion& a, const Quaternion& b);
[[nodiscard]]
Quaternion operator-(const Quaternion& a, const Quaternion& b);
[[nodiscard]]
Quaternion operator-(const Quaternion& a);
[[nodiscard]]
Quaternion operator*(const Quaternion& a, const Quaternion& b);
[[nodiscard]]
Quaternion operator*(const Quaternion& v, const float factor);
[[nodiscard]]
Quaternion operator/(const Quaternion& a, const Quaternion& b);
[[nodiscard]]
Quaternion operator/(const Quaternion& v, const float factor);

Quaternion& operator+=(Quaternion& a, const Quaternion& b);
Quaternion& operator-=(Quaternion& a, const Quaternion& b);
Quaternion& operator*=(Quaternion& a, const Quaternion& b);
Quaternion& operator*=(Quaternion& v, const float factor);
Quaternion& operator/=(Quaternion& a, const Quaternion& b);
Quaternion& operator/=(Quaternion& v, const float factor);

std::ostream& operator<<(std::ostream& out, const Quaternion& v);

using quat = Quaternion;
