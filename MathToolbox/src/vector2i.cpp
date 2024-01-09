#include "vector2i.hpp"

#include <cassert>

#include "calc.hpp"
#include "vector2.hpp"
#include "vector3.hpp"
#include "vector4.hpp"
#include "matrix2x2.hpp"

#define SQ(var) ((var) * (var))

float Vector2i::Length() const
{
	return sqrt(SquaredLength());
}

float Vector2i::SquaredLength() const
{
	return static_cast<float>(x * x + y * y);
}

Vector2 Vector2i::Normalized() const
{
	const float length = Length();
	if (calc::IsZero(length))
		return 0;

    __assume(length != 0.f);
	return Vector2(static_cast<float>(x) / length, static_cast<float>(y) / length);
}

Vector2 Vector2i::Normal() const
{
	return Vector2i(y, -x).Normalized();
}

float Vector2i::Dot(const Vector2i other) const
{
	return static_cast<float>(x * other.x + y * other.y);
}

float Vector2i::Cross(const Vector2i other) const
{
	// For a Vector2i this is only the determinant
	return Determinant(other);
}

float Vector2i::Determinant(const Vector2i other) const
{
	return static_cast<float>(x * other.y - other.x * y);
}

float Vector2i::Dot(const Vector2i a, const Vector2i b)
{
	return a.Dot(b);
}

float Vector2i::Cross(const Vector2i a, const Vector2i b)
{
	return a.Cross(b);
}

float Vector2i::Determinant(const Vector2i a, const Vector2i b)
{
	return a.Determinant(b);
}

int Vector2i::operator[](const size_t i) const
{
	assert(i >= 0 && i < 2 && "Vector2i subscript out of range");
    __assume(i >= 0 && i < 2);

    return *(&x + i);
}

int &Vector2i::operator[](const size_t i)
{
    
	assert(i >= 0 && i < 2 && "Vector2i subscript out of range");
    __assume(i >= 0 && i < 2);

    return *(&x + i);
}

Vector2i::operator Vector2() const
{
	return Vector2(static_cast<float>(x), static_cast<float>(y));
}

Vector2i::operator Vector3() const
{
	return Vector3(static_cast<float>(x), static_cast<float>(y), 0.f);
}

Vector2i::operator Vector4() const
{
	return Vector4(static_cast<float>(x), static_cast<float>(y), 0.f, 0.f);
}

Vector2i::operator Matrix2x2() const
{
	return Matrix2x2(
		static_cast<float>(x), 0.f,
		static_cast<float>(y), 1.f
	);
}

Vector2i operator+(const Vector2i a, const Vector2i b)
{
	return Vector2i(a.x + b.x, a.y + b.y);
}

Vector2i operator-(const Vector2i a, const Vector2i b)
{
	return a + -b;
}

Vector2i operator-(const Vector2i a)
{
	return Vector2i(-a.x, -a.y);
}

Vector2i operator*(const Vector2i a, const Vector2i b)
{
	return Vector2i(a.x * b.x, a.y * b.y);
}

Vector2i operator*(const Vector2i a, const int s)
{
	return Vector2i(a.x * s, a.y * s);
}

Vector2 operator/(const Vector2i a, const Vector2i b)
{
	return Vector2(a.x / static_cast<float>(b.x), a.y / static_cast<float>(b.y));
}

Vector2 operator/(const Vector2i v, const float factor)
{
	return Vector2(v.x / factor, v.y / factor);
}

Vector2i& operator+=(Vector2i& a, const Vector2i b)
{
	a.x += b.x;
	a.y += b.y;
	return a;
}

Vector2i& operator+=(Vector2i& v, const int factor)
{
	v.x += factor;
	v.y += factor;
	return v;
}

Vector2i &operator-=(Vector2i &a, const Vector2i b)
{
	a.x -= b.x;
	a.y -= b.y;
	return a;
}

Vector2i& operator-=(Vector2i& v, const int factor)
{
	v.x -= factor;
	v.y -= factor;
	return v;
}

Vector2i& operator*=(Vector2i& a, const Vector2i b)
{
	a.x *= b.x;
	a.y *= b.y;
	return a;
}

Vector2i& operator*=(Vector2i& v, const int factor)
{
	v.x *= factor;
	v.y *= factor;
	return v;
}

bool operator==(const Vector2i &v, const int i)
{
    return v.x == i && v.y == i;
}

bool operator!=(const Vector2i &v, const int i)
{
    return !(v == i);
}

bool operator<(const Vector2i &v, const int i)
{
    return v.x < i && v.y < i;
}

bool operator>(const Vector2i &v, const int i)
{
    return v.x > i && v.y > i;
}

bool operator<=(const Vector2i &v, const int i)
{
    return v < i || v == i;
}

bool operator>=(const Vector2i &v, const int i)
{
    return v > i || v == i;
}

std::ostream& operator<<(std::ostream& out, const Vector2i v)
{
	return out << std::format("%6d %6d", v.x, v.y);
}
