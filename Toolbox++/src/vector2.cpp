#include "vector2.hpp"

#pragma region defines
#define SQ(var) ((var) * (var))
#pragma endregion

#pragma region constants
const Vector2 Vector2::Zero = { 0, 0 };
const Vector2 Vector2::Unit = { 1, 1 };
#pragma endregion

#pragma region constructors
Vector2::Vector2(const float xy)
	: x(xy), y(xy)
{
}

Vector2::Vector2()
{
	*this = Zero;
}

Vector2::Vector2(const float x, const float y)
	: x(x), y(y)
{
}

Vector2::Vector2(const Vector2& p)
	: x(p.x), y(p.y)
{
}

Vector2::Vector2(const Vector2& p1, const Vector2& p2)
	: x(p2.x - p1.x), y(p2.y - p1.y)
{
}
#pragma endregion

#pragma region functions
float Vector2::GetNorm() const
{
	return sqrt(x * x + y * y);
}

float Vector2::GetSquaredNorm() const
{
	return x * x + y * y;
}

Vector2 Vector2::Normalize() const
{
	float norm = GetNorm();
	return Vector2(x / norm, y / norm);
}

Vector2 Vector2::GetNormal() const
{
	return Vector2(y, -x).Normalize();
}

float Vector2::Angle() const
{
	return atan2f(y, x);
}

Vector2 Vector2::Rotate(float angle) const
{
	float c = cos(angle);
	float s = sin(angle);

	return Vector2(x * c - y * s, y * c + x * s);
}

float Vector2::Angle(const Vector2 a, const Vector2 b)
{
	float dotProduct = DotProduct(a, b);
	float angle = acosf(
		dotProduct / (a.GetNorm() * b.GetNorm())
	);

	if (Determinant(a, b) < 0)
		angle = -angle;

	return angle;
}

float Vector2::DotProduct(const Vector2 a, const Vector2 b)
{
	return a.x * b.x + a.y * b.y;
}

float Vector2::Determinant(const Vector2 a, const Vector2 b)
{
	return (a.x * b.y) - (b.x * a.y);
}
#pragma endregion

#pragma region operators
Vector2 operator+(const Vector2 a, const Vector2 b)
{
	return Vector2(a.x + b.x, a.y + b.y);
}

Vector2 operator-(const Vector2 a, const Vector2 b)
{
	return Vector2(a.x - b.x, a.y - b.y);
}

Vector2 operator-(const Vector2 a)
{
	return Vector2(-a.x, -a.y);
}

Vector2 operator*(const Vector2 a, const Vector2 b)
{
	return Vector2(a.x * b.x, a.y * b.y);
}

Vector2 operator*(const Vector2 a, const float s)
{
	return Vector2(a.x * s, a.y * s);
}

Vector2 operator/(const Vector2 a, const Vector2 b)
{
	return Vector2(a.x / b.x, a.y / b.y);
}

Vector2 operator/(const Vector2 a, const float s)
{
	return Vector2(a.x / s, a.y / s);
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

std::ostream& operator<<(std::ostream& out, const Vector2& v)
{
	return out << "{ " << v.x << " ; " << v.y << " }";
}
#pragma endregion
