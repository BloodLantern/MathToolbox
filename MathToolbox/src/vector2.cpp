#include "vector2.hpp"

#include <cassert>

#include "calc.hpp"
#include "vector2i.hpp"
#include "vector3.hpp"
#include "vector4.hpp"
#include "matrix2x2.hpp"

constexpr Vector2 Vector2::Zero()
{
	return Vector2();
}

constexpr Vector2 Vector2::UnitX()
{
	return Vector2(1.f, 0.f);
}

constexpr Vector2 Vector2::UnitY()
{
	return Vector2(0.f, 1.f);
}

constexpr Vector2::Vector2(const float xy)
	: x(xy)
	, y(xy)
{
}

constexpr Vector2::Vector2(const float x, const float y)
	: x(x)
	, y(y)
{
}

constexpr const float* Vector2::Raw() const
{
	return &x;
}

constexpr float* Vector2::Raw()
{
	return &x;
}

float Vector2::Length() const
{
	return std::sqrt(SquaredLength());
}

float Vector2::SquaredLength() const
{
	return SQ(x) + SQ(y);
}

Vector2 Vector2::Normalized() const
{
	const float length = Length();
	if (calc::IsZero(length))
		return Zero();

    __assume(length != 0.f);
	return Vector2(x / length, y / length);
}

Vector2 Vector2::Normal() const
{
	return Vector2(y, -x).Normalized();
}

float Vector2::Dot(const Vector2 other) const
{
	return x * other.x + y * other.y;
}

float Vector2::Cross(const Vector2 other) const
{
	// For a Vector2 this is only the determinant
	return Determinant(other);
}

float Vector2::Determinant(const Vector2 other) const
{
	return (x * other.y) - (other.x * y);
}

float Vector2::Dot(const Vector2 a, const Vector2 b)
{
	return a.Dot(b);
}

float Vector2::Cross(const Vector2 a, const Vector2 b)
{
	// For a Vector2 this is only the determinant
	return a.Cross(b);
}

float Vector2::Determinant(const Vector2 a, const Vector2 b)
{
	return a.Determinant(b);
}

Vector2 Vector2::Lerp(const Vector2 value, const Vector2 target, const float t)
{
    return value + (target - value) * t;
}

float Vector2::operator[](const size_t i) const
{
	assert(i < 2 && "Vector2 subscript out of range");

    return *(Raw() + i);
}

float &Vector2::operator[](const size_t i)
{
	assert(i < 2 && "Vector2 subscript out of range");

    return *(Raw() + i);
}

Vector2::operator Vector2i() const
{
	return Vector2i(static_cast<int>(std::round(x)), static_cast<int>(std::round(y)));
}

Vector2::operator Vector3() const
{
	return Vector3(x, y, 0.f);
}

Vector2::operator Vector4() const
{
	return Vector4(x, y, 0.f, 1.f);
}

Vector2::operator Matrix2x2() const
{
	return Matrix2x2(
		x, 0.f,
		y, 1.f
	);
}

Vector2 operator+(const Vector2 a, const Vector2 b)
{
	return Vector2(a.x + b.x, a.y + b.y);
}

Vector2 operator-(const Vector2 a, const Vector2 b)
{
	return a + -b;
}

Vector2 operator-(const Vector2 a)
{
	return Vector2(-a.x, -a.y);
}

Vector2 operator*(const Vector2 a, const Vector2 b)
{
	return Vector2(a.x * b.x, a.y * b.y);
}

Vector2 operator*(const Vector2 v, const float factor)
{
	return Vector2(v.x * factor, v.y * factor);
}

Vector2 operator*(const Matrix2x2& m, const Vector2& v)
{
	const float x = v.x * m[0].x + v.y * m[0].y;
    const float y = v.x * m[1].x + v.y * m[1].y;

    return Vector2(x, y);
}

Vector2 operator/(const Vector2 a, const Vector2 b)
{
	return Vector2(a.x / b.x, a.y / b.y);
}

Vector2 operator/(const Vector2 v, const float factor)
{
	return Vector2(v.x / factor, v.y / factor);
}

Vector2& operator+=(Vector2& a, const Vector2 b)
{
	a.x += b.x;
	a.y += b.y;
	
	return a;
}

Vector2& operator+=(Vector2& v, const float factor)
{
	v.x += factor;
	v.y += factor;
	
	return v;
}

Vector2 &operator-=(Vector2 &a, const Vector2 b)
{
	a.x -= b.x;
	a.y -= b.y;
	
	return a;
}

Vector2& operator-=(Vector2& v, const float factor)
{
	v.x -= factor;
	v.y -= factor;
	
	return v;
}

Vector2& operator*=(Vector2& a, const Vector2 b)
{
	a.x *= b.x;
	a.y *= b.y;
	
	return a;
}

Vector2& operator*=(Vector2& v, const float factor)
{
	v.x *= factor;
	v.y *= factor;
	
	return v;
}

Vector2& operator*=(const Matrix2x2& m, Vector2& v)
{
	return v = m * v;
}

Vector2 &operator/=(Vector2 &a, const Vector2 b)
{
	a.x /= b.x;
	a.y /= b.y;
	
	return a;
}

Vector2& operator/=(Vector2& v, const float factor)
{
	v.x /= factor;
	v.y /= factor;
	
	return v;
}

std::ostream& operator<<(std::ostream& out, const Vector2 v)
{
	return out << std::format("{:6.3f} {:6.3f}", v.x, v.y);
}
