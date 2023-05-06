#include "vector2.hpp"

#include "matrix.hpp"
#include "vector2i.hpp"
#include "vector3.hpp"

#define SQ(var) ((var) * (var))

Vector2::Vector2(const Vector2 p1, const Vector2 p2)
	: x(p2.x - p1.x), y(p2.y - p1.y)
{
}

#pragma region functions
float Vector2::Norm() const
{
	return std::sqrt(SquaredNorm());
}

float Vector2::SquaredNorm() const
{
	return x * x + y * y;
}

Vector2 Vector2::Normalized() const
{
	float norm = Norm();
	if (norm == 0)
		return 0;

    __assume(norm != 0.f);
	return Vector2(x / norm, y / norm);
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
	float dotProduct = Dot(a, b);
	float angle = std::acos(dotProduct / (a.Norm() * b.Norm()));

	if (Determinant(a, b) < 0)
		angle = -angle;

	return angle;
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
#pragma endregion

#pragma region operators
float Vector2::operator[](const size_t i) const
{
	assert(i >= 0 && i < 2 && "Vector2 subscript out of range");
    __assume(i >= 0 && i < 2);

    return *(&x + i);
}

float &Vector2::operator[](const size_t i)
{
    
	assert(i >= 0 && i < 2 && "Vector2 subscript out of range");
    __assume(i >= 0 && i < 2);

    return *(&x + i);
}

Vector2::operator Vector2i() const
{
	return Vector2i((int)std::round(x), (int)std::round(y));
}

Vector2::operator Vector3() const
{
	return Vector3(x, y, 0);
}

Vector2::operator Matrix() const
{
	Matrix result(2);
	for (size_t i = 0; i < 2; i++)
		result[i] = operator[](i);
	return result;
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

bool operator==(const Vector2 &v, const float f)
{
    return v.x == f && v.y == f;
}

bool operator!=(const Vector2 &v, const float f)
{
    return !(v == f);
}

bool operator<(const Vector2 &v, const float f)
{
    return v.x < f && v.y < f;
}

bool operator>(const Vector2 &v, const float f)
{
    return v.x > f && v.y > f;
}

bool operator<=(const Vector2 &v, const float f)
{
    return v < f || v == f;
}

bool operator>=(const Vector2 &v, const float f)
{
    return v > f || v == f;
}

std::ostream& operator<<(std::ostream& out, const Vector2 v)
{
	char buffer[10];
	out << "[ ";
	sprintf_s(buffer, sizeof(buffer), "%6.3f", v.x);
	out << buffer << ", ";
	sprintf_s(buffer, sizeof(buffer), "%6.3f", v.y);
	return out << buffer << " ]";
}
#pragma endregion
