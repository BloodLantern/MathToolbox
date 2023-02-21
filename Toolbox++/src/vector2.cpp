#include "vector2.hpp"

#define SQ(var) ((var) * (var))

Vector2::Vector2(const Vector2 p1, const Vector2 p2)
	: x(p2.x - p1.x), y(p2.y - p1.y)
{
}

#pragma region functions
float Vector2::Norm() const
{
	return sqrt(x * x + y * y);
}

float Vector2::SquaredNorm() const
{
	return x * x + y * y;
}

Vector2 Vector2::Normalize() const
{
	float norm = Norm();
	assert(norm != 0.f && "[Vector2::Normalize]: Length of vector is zero!");
	return Vector2(x / norm, y / norm);
}

Vector2 Vector2::Normal() const
{
	return Vector2(y, -x).Normalize();
}

float Vector2::Angle() const
{
	return atan2f(y, x);
}

Vector2 Vector2::Rotate(const float angle) const
{
	float c = cos(angle);
	float s = sin(angle);
	return Rotate(c, s);
}

Vector2 Vector2::Rotate(const float angle, const Vector2 center) const
{
	float c = cos(angle);
	float s = sin(angle);
	return Rotate(center, c, s);
}

Vector2 Vector2::Rotate(const float cos, const float sin) const
{
	return Vector2(x * cos - y * sin, y * cos + x * sin);
}

Vector2 Vector2::Rotate(const Vector2 center, const float cos, const float sin) const
{
	Vector2 temp = *this - center;
	return Vector2(temp.x * cos - temp.y * sin, temp.y * cos + temp.x * sin) + center;
}

float Vector2::Angle(const Vector2 a, const Vector2 b)
{
	float dotProduct = DotProduct(a, b);
	float angle = std::acos(dotProduct / (a.Norm() * b.Norm()));

	if (Determinant(a, b) < 0)
		angle = -angle;

	return angle;
}

float Vector2::DotProduct(const Vector2 a, const Vector2 b)
{
	return a.x * b.x + a.y * b.y;
}

float Vector2::CrossProduct(const Vector2 a, const Vector2 b)
{
	// For a Vector2 this is only the determinant
	return Determinant(a, b);
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

std::ostream& operator<<(std::ostream& out, const Vector2 v)
{
	return out << "{ " << v.x << " ; " << v.y << " }";
}
#pragma endregion
