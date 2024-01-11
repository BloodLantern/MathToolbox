#include "vector4.hpp"

#include <cassert>

#include "calc.hpp"
#include "..\include\matrix.hpp"
#include "vector2.hpp"
#include "vector3.hpp"

constexpr Vector4 Vector4::Zero()
{
	return Vector4();
}

constexpr Vector4 Vector4::UnitX()
{
	return Vector4(1.f, 0.f, 0.f, 0.f);
}

constexpr Vector4 Vector4::UnitY()
{
	return Vector4(0.f, 1.f, 0.f, 0.f);
}

constexpr Vector4 Vector4::UnitZ()
{
	return Vector4(0.f, 0.f, 1.f, 0.f);
}

constexpr Vector4 Vector4::UnitW()
{
	return Vector4(0.f, 0.f, 0.f, 1.f);
}

constexpr Vector4::Vector4()
	: x(0)
	, y(0)
	, z(0)
	, w(0)
{
}

constexpr Vector4::Vector4(const float xyzw)
	: x(xyzw)
	, y(xyzw)
	, z(xyzw)
	, w(xyzw)
{
}

constexpr Vector4::Vector4(const float x, const float y, const float z, const float w)
	: x(x)
	, y(y)
	, z(z)
	, w(w)
{
}

constexpr const float* Vector4::Raw() const
{
	return &x;
}

constexpr float* Vector4::Raw()
{
	return &x;
}

float Vector4::Length() const
{
	return std::sqrt(SquaredLength());
}

float Vector4::SquaredLength() const
{
	return SQ(x) + SQ(y) + SQ(z) + SQ(w);
}

Vector4 Vector4::Normalized() const
{
	const float length = Length();
	if (length == 0.f)
		return 0.f;

	__assume(length != 0.f);
	return Vector4(x / length, y / length, z / length, w / length);
}

float Vector4::Dot(const Vector4& other) const
{
	return Dot(*this, other);
}

float Vector4::Dot(const Vector4& a, const Vector4& b)
{
	return a.x * b.x
		+ a.y * b.y
		+ a.z * b.z
		+ a.w * b.w;
}

Vector4 Vector4::Lerp(const Vector4 value, const Vector4 target, const float t)
{
    return value + (target - value) * t;
}

float Vector4::operator[](const size_t i) const
{
	assert(i < 4 && "Vector4 subscript out of range");

	return *(Raw() + i);
}

float& Vector4::operator[](const size_t i)
{
	assert(i < 4 && "Vector4 subscript out of range");

	return *(Raw() + i);
}

constexpr Vector4::operator Vector2() const
{
	return Vector2(x, y);
}

constexpr Vector4::operator Vector3() const
{
	return Vector3(x, y, z);
}

constexpr Vector4::operator Matrix() const
{
	return Matrix(
		x, 0, 0, 0,
		y, 1, 0, 0,
		z, 0, 1, 0,
        w, 0, 0, 1
	);
}

Vector4 operator+(const Vector4& a, const Vector4& b)
{
	return Vector4(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w);
}

Vector4 operator-(const Vector4& a, const Vector4& b)
{
	return a + -b;
}

Vector4 operator-(const Vector4& a)
{
	return Vector4(-a.x, -a.y, -a.z, -a.w);
}

Vector4 operator*(const Vector4& a, const Vector4& b)
{
	return Vector4(a.x * b.x, a.y * b.y, a.z * b.z, a.w * b.w);
}

Vector4 operator*(const Vector4& v, const float factor)
{
	return Vector4(v.x * factor, v.y * factor, v.z * factor, v.w * factor);
}

Vector4 operator*(const Matrix& m, const Vector4& v)
{
	const float x = v.x * m[0].x + v.y * m[0].y + v.z * m[0].z + v.w * m[0].w;
    const float y = v.x * m[1].x + v.y * m[1].y + v.z * m[1].z + v.w * m[1].w;
    const float z = v.x * m[2].x + v.y * m[2].y + v.z * m[2].z + v.w * m[2].w;
    const float w = v.x * m[3].x + v.y * m[3].y + v.z * m[3].z + v.w * m[3].w;

    return Vector4(x, y, z, w);
}

Vector4 operator/(const Vector4& a, const Vector4& b)
{
	return Vector4(a.x / b.x, a.y / b.y, a.z / b.z, a.w / b.w);
}

Vector4 operator/(const Vector4& v, const float factor)
{
	return Vector4(v.x / factor, v.y / factor, v.z / factor, v.w / factor);
}

Vector4& operator+=(Vector4& a, const Vector4& b)
{
	a.x += b.x;
	a.y += b.y;
    a.z += b.z;
    a.w += b.w;
	
	return a;
}

Vector4& operator+=(Vector4& v, const float factor)
{
	v.x += factor;
	v.y += factor;
    v.z += factor;
    v.w += factor;
	
	return v;
}

Vector4 &operator-=(Vector4 &a, const Vector4& b)
{
	a.x -= b.x;
	a.y -= b.y;
    a.z -= b.z;
    a.w -= b.w;
	
	return a;
}

Vector4& operator-=(Vector4& v, const float factor)
{
	v.x -= factor;
	v.y -= factor;
    v.z -= factor;
    v.w -= factor;
	
	return v;
}

Vector4& operator*=(Vector4& a, const Vector4& b)
{
	a.x *= b.x;
	a.y *= b.y;
    a.z *= b.z;
    a.w *= b.w;
	
	return a;
}

Vector4& operator*=(Vector4& v, const float factor)
{
	v.x *= factor;
	v.y *= factor;
    v.z *= factor;
    v.w *= factor;
	
	return v;
}

Vector4 &operator*=(const Matrix &m, Vector4& v)
{
    return v = m * v;
}

Vector4 &operator/=(Vector4 &a, const Vector4& b)
{
	a.x /= b.x;
	a.y /= b.y;
    a.z /= b.z;
    a.w /= b.w;
	
	return a;
}

Vector4& operator/=(Vector4& v, const float factor)
{
	v.x /= factor;
	v.y /= factor;
    v.z /= factor;
    v.w /= factor;
	
	return v;
}

bool operator==(Vector4 a, Vector4 b)
{
	return calc::Equals(a.x, b.x)
		&& calc::Equals(a.y, b.y)
		&& calc::Equals(a.z, b.z)
		&& calc::Equals(a.w, b.w);
}

bool operator!=(Vector4 a, Vector4 b)
{
	return !(a == b);
}

std::ostream& operator<<(std::ostream& out, const Vector4& v)
{
	return out << std::format("{{{:6.3f} {:6.3f} {:6.3f} {:6.3f}}}", v.x, v.y, v.z, v.w);
}
