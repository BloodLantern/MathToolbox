#include "vector3.hpp"

#pragma region defines
#define SQ(var) ((var) * (var))
#pragma endregion

#pragma region constants
const Vector3 Vector3::Zero(0.f, 0.f);
const Vector3 Vector3::UnitY(0.f, 1.f);
const Vector3 Vector3::UnitX(1.f, 0.f);
#pragma endregion

#pragma region constructors
Vector3::Vector3(const float xyz)
	: x(xyz), y(xyz), z(xyz)
{
}

Vector3::Vector3(const float x, const float y, const float z)
	: x(x), y(y), z(z)
{
}

Vector3::Vector3(const Vector3& p)
	: x(p.x), y(p.y), z(p.z)
{
}

Vector3::Vector3(const Vector3& p1, const Vector3& p2)
	: x(p2.x - p1.x), y(p2.y - p1.y), z(p2.z - p1.z)
{
}
#pragma endregion

#pragma region functions
float Vector3::GetNorm() const
{
	return sqrt(x * x + y * y + z * z);
}

float Vector3::GetSquaredNorm() const
{
	return x * x + y * y + z * z;
}

Vector3 Vector3::Normalize() const
{
	float norm = GetNorm();
	return Vector3(x / norm, y / norm, z / norm);
}

Vector3 Vector3::GetNormal() const
{
	return Vector3(y, -x).Normalize();
}

float Vector3::Angle() const
{
	return atan2f(y, x);
}

Vector3 Vector3::Rotate(float angle) const
{
	float c = cos(angle);
	float s = sin(angle);

	return Vector3(x * c - y * s, y * c + x * s);
}

float Angle(const Vector3 a, const Vector3 b)
{
	float dotProduct = DotProduct(a, b);
	float angle = acosf(
		dotProduct / (a.GetNorm() * b.GetNorm())
	);

	if (Determinant(a, b) < 0)
		angle = -angle;

	return angle;
}

float DotProduct(const Vector3 a, const Vector3 b)
{
	return a.x * b.x + a.y * b.y;
}

float Determinant(const Vector3 a, const Vector3 b)
{
	return (a.x * b.y) - (b.x * a.y);
}
#pragma endregion

#pragma region operators
Vector3 operator+(const Vector3 a, const Vector3 b)
{
	return Vector3(a.x + b.x, a.y + b.y, a.z + b.z);
}

Vector3 operator-(const Vector3 a)
{
	return Vector3(-a.x, -a.y, -a.z);
}

Vector3 operator-(const Vector3 a, const Vector3 b)
{
	return a + -b;
}

Vector3 operator*(const Vector3 a, const Vector3 b)
{
	return Vector3(a.x * b.x, a.y * b.y, a.z * b.z);
}

Vector3 operator*(const Vector3 a, const float s)
{
	return Vector3(a.x * s, a.y * s, a.z * s);
}

Vector3 operator/(const Vector3 a, const Vector3 b)
{
	return Vector3(a.x / b.x, a.y / b.y, a.z / b.z);
}

Vector3 operator/(const Vector3 a, const float s)
{
	return Vector3(a.x / s, a.y / s, a.z / s);
}

Vector3& operator+=(Vector3& a, const Vector3 b)
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

Vector3 &operator-=(Vector3 &a, const Vector3 b)
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

Vector3& operator*=(Vector3& a, const Vector3 b)
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

Vector3 &operator/=(Vector3 &a, const Vector3 b)
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
	return out << "{ " << v.x << ", " << v.y << ", " << v.z << " }";
}
#pragma endregion

#pragma region Point3
float Dist(const Vector3 p1, const Vector3 p2)
{
	return std::sqrt(DistSquared(p1, p2));
}

float DistSquared(const Vector3 p1, const Vector3 p2)
{
	return SQ(p1.x - p2.x) + SQ(p1.y - p2.y) + SQ(p1.z - p2.z);
}

Vector3 Mid(const Vector3 p1, const Vector3 p2)
{
	return Vector3((p1.x + p2.x) / 2, (p1.y + p2.y) / 2, (p1.z + p2.z) / 2);
}

Vector3 Rotate(const Vector3 p, const float angle)
{
	float c = cos(angle);
	float s = sin(angle);

	return Vector3(p.x * c - p.y * s, p.y * c + p.x * s);
}

Vector3 Rotate(const Vector3 p, const Vector3 center, float angle)
{
	float _x = p.x - center.x;
	float _y = p.y - center.y;

	float c = cos(angle);
	float s = sin(angle);

	return Vector3(center.x + _x * c - _y * s, center.y + _y * c + _x * s);
}

Vector3 Rotate(const Vector3 p, float cos, float sin)
{
	return Vector3(p.x * cos - p.y * sin, p.y * cos + p.x * sin);
}

Vector3 Rotate(const Vector3 p, const Vector3 center, float cos, float sin)
{
	float _x = p.x - center.x;
	float _y = p.y - center.y;

	return Vector3(center.x + _x * cos - _y * sin, center.y + _y * cos + _x * sin);
}

Vector3 Scale(const Vector3 p, float scale)
{
	return Vector3(p.x * scale, p.y * scale, p.z * scale);
}

Vector3 Scale(const Vector3 p, const Vector3 center, float scale)
{

	return Vector3(scale * (p.x - center.x), scale * (p.y - center.y), scale * (p.z - center.z)) + center;
}
#pragma endregion
