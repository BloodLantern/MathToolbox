#include "vector3.hpp"

#include <cassert>

#include "calc.hpp"
#include "matrix3x3.hpp"
#include "vector2.hpp"
#include "vector4.hpp"

constexpr Vector3 Vector3::Zero()
{
	return Vector3();
}

constexpr Vector3 Vector3::UnitX()
{
	return Vector3(1.f, 0.f, 0.f);
}

constexpr Vector3 Vector3::UnitY()
{
	return Vector3(0.f, 1.f, 0.f);
}

constexpr Vector3 Vector3::UnitZ()
{
	return Vector3(0.f, 0.f, 1.f);
}

constexpr Vector3::Vector3()
	: x(0)
	, y(0)
	, z(0)
{
}

constexpr Vector3::Vector3(const float xyz)
	: x(xyz)
	, y(xyz)
	, z(xyz)
{
}

constexpr Vector3::Vector3(const float x, const float y, const float z)
	: x(x)
	, y(y)
	, z(z)
{
}

constexpr const float* Vector3::Raw() const
{
	return &x;
}

constexpr float* Vector3::Raw()
{
	return &x;
}

float Vector3::Length() const
{
	return sqrt(SquaredLength());
}

float Vector3::SquaredLength() const
{
	return SQ(x) + SQ(y) + SQ(z);
}

Vector3 Vector3::Normalized() const
{
	const float length = Length();
	if (length == 0.f)
		return 0.f;

	__assume(length != 0.f);
	return Vector3(x / length, y / length, z / length);
}

float Vector3::Dot(const Vector3& other) const
{
	return x * other.x + y * other.y + z * other.z;
}

Vector3 Vector3::Cross(const Vector3& other) const
{
	return Vector3(y * other.z - z * other.y, z * other.x - x * other.z, x * other.y - y * other.x);
}

float Vector3::Dot(const Vector3& a, const Vector3& b)
{
	return a.Dot(b);
}

Vector3 Vector3::Cross(const Vector3& a, const Vector3& b)
{
	return a.Cross(b);
}

Vector3 Vector3::Lerp(const Vector3 value, const Vector3 target, const float t)
{
    return value + (target - value) * t;
}

float Vector3::operator[](const size_t i) const
{
	assert(i < 3 && "Vector3 subscript out of range");

	return *(Raw() + i);
}

float& Vector3::operator[](const size_t i)
{
	assert(i < 3 && "Vector3 subscript out of range");

	return *(Raw() + i);
}

Vector3::operator Vector2() const
{
	return Vector2(x, y);
}

Vector3::operator Vector4() const
{
	return Vector4(x, y, z, 1);
}

Vector3::operator Matrix3x3() const
{
	return Matrix3x3(
		x, 0, 0,
		y, 1, 0,
		z, 0, 1
	);
}

Vector3 operator+(const Vector3& a, const Vector3& b)
{
	return Vector3(a.x + b.x, a.y + b.y, a.z + b.z);
}

Vector3 operator-(const Vector3& a, const Vector3& b)
{
	return a + -b;
}

Vector3 operator-(const Vector3& a)
{
	return Vector3(-a.x, -a.y, -a.z);
}

Vector3 operator*(const Vector3& a, const Vector3& b)
{
	return Vector3(a.x * b.x, a.y * b.y, a.z * b.z);
}

Vector3 operator*(const Vector3& v, const float factor)
{
	return Vector3(v.x * factor, v.y * factor, v.z * factor);
}

Vector3 operator*(const Matrix3x3& m, const Vector3& v)
{
	const float x = v.x * m[0].x + v.y * m[0].y + v.z * m[0].z;
    const float y = v.x * m[1].x + v.y * m[1].y + v.z * m[1].z;
    const float z = v.x * m[2].x + v.y * m[2].y + v.z * m[2].z;

    return Vector3(x, y, z);
}

Vector3 operator/(const Vector3& a, const Vector3& b)
{
	return Vector3(a.x / b.x, a.y / b.y, a.z / b.z);
}

Vector3 operator/(const Vector3& v, const float factor)
{
	return Vector3(v.x / factor, v.y / factor, v.z / factor);
}

Vector3& operator+=(Vector3& a, const Vector3& b)
{
	a.x += b.x;
	a.y += b.y;
	a.z += b.z;
	
	return a;
}

Vector3& operator+=(Vector3& v, const float factor)
{
	v.x += factor;
	v.y += factor;
	v.z += factor;
	
	return v;
}

Vector3 &operator-=(Vector3 &a, const Vector3& b)
{
	a.x -= b.x;
	a.y -= b.y;
	a.z -= b.z;
	
	return a;
}

Vector3& operator-=(Vector3& v, const float factor)
{
	v.x -= factor;
	v.y -= factor;
	v.z -= factor;
	
	return v;
}

Vector3& operator*=(Vector3& a, const Vector3& b)
{
	a.x *= b.x;
	a.y *= b.y;
	a.z *= b.z;
	
	return a;
}

Vector3& operator*=(Vector3& v, const float factor)
{
	v.x *= factor;
	v.y *= factor;
	v.z *= factor;
	
	return v;
}

Vector3& operator*=(const Matrix3x3& m, Vector3& v)
{
	return v = m * v;
}

Vector3 &operator/=(Vector3 &a, const Vector3& b)
{
	a.x /= b.x;
	a.y /= b.y;
	a.z /= b.z;
	
	return a;
}

Vector3& operator/=(Vector3& v, const float factor)
{
	v.x /= factor;
	v.y /= factor;
	v.z /= factor;
	
	return v;
}

std::ostream& operator<<(std::ostream& out, const Vector3& v)
{
	return out << std::format("{:6.3f} {:6.3f} {:6.3f}", v.x, v.y, v.z);
}
