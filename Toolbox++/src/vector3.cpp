#include "vector3.hpp"

#include "matrix.hpp"

#define SQ(var) ((var) * (var))

Vector3::Vector3(const Vector3& p1, const Vector3& p2)
	: x(p2.x - p1.x), y(p2.y - p1.y), z(p2.z - p1.z)
{
}

#pragma region functions
float Vector3::Norm() const
{
	return sqrt(x * x + y * y + z * z);
}

float Vector3::SquaredNorm() const
{
	return x * x + y * y + z * z;
}

Vector3 Vector3::Normalize() const
{
	float norm = Norm();
	assert(norm != 0.f && "[Vector3::Normalize]: Length of vector is zero!");
	return Vector3(x / norm, y / norm, z / norm);
}

float Vector3::Angle(const Vector3& a, const Vector3& b)
{
	float dotProduct = DotProduct(a, b);
	float angle = std::acos(dotProduct / (a.Norm() * b.Norm()));

	if (Determinant(a, b) < 0)
		angle = -angle;

	return angle;
}

float Vector3::DotProduct(const Vector3& a, const Vector3& b)
{
	return a.x * b.x + a.y * b.y + a.z * b.z;
}

Vector3 Vector3::CrossProduct(const Vector3& a, const Vector3& b)
{
	return Vector3(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x);
}

float Vector3::Determinant(const Vector3& a, const Vector3& b)
{
	return Vector3(
		a.y * b.z - a.z * b.y,
		a.z * b.x - a.x * b.z,
		a.x * b.y - a.y * b.x
	);
}
#pragma endregion

#pragma region operators
Vector3 operator+(const Vector3& a, const Vector3& b)
{
	return Vector3(a.x + b.x, a.y + b.y);
}

Vector3 operator-(const Vector3& a, const Vector3& b)
{
	return a + -b;
}

Vector3 operator-(const Vector3& a)
{
	return Vector3(-a.x, -a.y);
}

Vector3 operator*(const Vector3& a, const Vector3& b)
{
	return Vector3(a.x * b.x, a.y * b.y);
}

Vector3 operator*(const Vector3& a, const float s)
{
	return Vector3(a.x * s, a.y * s);
}

Vector3 operator/(const Vector3& a, const Vector3& b)
{
	return Vector3(a.x / b.x, a.y / b.y);
}

Vector3 operator/(const Vector3& a, const float s)
{
	return Vector3(a.x / s, a.y / s);
}

Vector3& operator+=(Vector3& a, const Vector3& b)
{
	a.x += b.x;
	a.y += b.y;
	return a;
}

Vector3& operator+=(Vector3& v, const float factor)
{
	v.x += factor;
	v.y += factor;
	return v;
}

Vector3 &operator-=(Vector3 &a, const Vector3& b)
{
	a.x -= b.x;
	a.y -= b.y;
	return a;
}

Vector3& operator-=(Vector3& v, const float factor)
{
	v.x -= factor;
	v.y -= factor;
	return v;
}

Vector3& operator*=(Vector3& a, const Vector3& b)
{
	a.x *= b.x;
	a.y *= b.y;
	return a;
}

Vector3& operator*=(Vector3& v, const float factor)
{
	v.x *= factor;
	v.y *= factor;
	return v;
}

Vector3 &operator/=(Vector3 &a, const Vector3& b)
{
	a.x /= b.x;
	a.y /= b.y;
	return a;
}

Vector3& operator/=(Vector3& v, const float factor)
{
	v.x /= factor;
	v.y /= factor;
	return v;
}

std::ostream& operator<<(std::ostream& out, const Vector3& v)
{
	return out << "{ " << v.x << " ; " << v.y << " }";
}
#pragma endregion
