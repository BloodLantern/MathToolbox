#pragma once

#include "vector3.hpp"
#include "vector4.hpp"

#include <ostream>

class Quaternion
{
public:
	Vector3 imaginary;
	float real;

	static Quaternion Zero();
	static Quaternion UnitX();
	static Quaternion UnitY();
	static Quaternion UnitZ();
	static Quaternion UnitW();
	static Quaternion Identity();

	Quaternion();
	explicit Quaternion(const Vector4& values);
	Quaternion(const Vector3& imaginary, float real);
	explicit Quaternion(float xyzw);
	Quaternion(float x, float y, float z, float w);

	[[nodiscard]]
	__forceinline float X() const;
	[[nodiscard]]
	__forceinline float Y() const;
	[[nodiscard]]
	__forceinline float Z() const;
	[[nodiscard]]
	__forceinline float W() const;

	[[nodiscard]]
	__forceinline float& X();
	[[nodiscard]]
	__forceinline float& Y();
	[[nodiscard]]
	__forceinline float& Z();
	[[nodiscard]]
	__forceinline float& W();

	[[nodiscard]]
	Quaternion Conjugate() const;
	[[nodiscard]]
	float Length() const;
	[[nodiscard]]
	float SquaredLength() const;
	[[nodiscard]]
	Quaternion Inverse() const;
	[[nodiscard]]
	float Dot(const Quaternion& other) const;
	[[nodiscard]]
	Vector3 Rotate(const Vector3& point) const;

	[[nodiscard]]
	float operator[](size_t i) const;
	[[nodiscard]]
	float& operator[](size_t i);
	explicit operator Vector3() const;
	explicit operator Vector4() const;

	[[nodiscard]]
	static Quaternion FromAxisAngle(const Vector3& axis, float angle);
	[[nodiscard]]
	static Quaternion FromEuler(const Vector3& rotation);
	[[nodiscard]]
	static Quaternion FromRotationMatrix(const Matrix4x4& rotation);
	[[nodiscard]]
	static float Dot(const Quaternion& a, const Quaternion& b);
	[[nodiscard]]
	static Quaternion Lerp(const Quaternion& a, const Quaternion& b, float t);
	[[nodiscard]]
	static Quaternion Slerp(const Quaternion& a, const Quaternion& b, float t);
	[[nodiscard]]
	static Vector3 Rotate(const Vector3& point, const Quaternion& rotation);
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
Quaternion operator*(const Quaternion& q, const Vector3& v);
[[nodiscard]]
Quaternion operator*(const Quaternion& v, float factor);
[[nodiscard]]
Quaternion operator/(const Quaternion& v, float factor);

Quaternion& operator+=(Quaternion& a, const Quaternion& b);
Quaternion& operator-=(Quaternion& a, const Quaternion& b);
Quaternion& operator*=(Quaternion& a, const Quaternion& b);
Quaternion& operator*=(Quaternion& v, float factor);
Quaternion& operator/=(Quaternion& v, float factor);

std::ostream& operator<<(std::ostream& out, const Quaternion& v);

using quat = Quaternion;
