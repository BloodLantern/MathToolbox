#include "vector3.hpp"

#include "matrix.hpp"

#define SQ(var) ((var) * (var))

Vector3::Vector3(const Vector3& p1, const Vector3& p2)
	: x(p2.x - p1.x), y(p2.y - p1.y), z(p2.z - p1.z)
{
}

#pragma region functions
float Vector3::Length() const
{
	return sqrt(SquaredLength());
}

float Vector3::SquaredLength() const
{
	return x * x + y * y + z * z;
}

Vector3 Vector3::Normalized() const
{
	float length = Length();
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

Vector3 Vector3::Rotate(const float angle, const Vector3 &axis) const
{
    return Matrix3x3::Rotation3D(angle, axis) * *this;
}

Vector3 Vector3::Rotate(const float angle, const Vector3& axis, const Vector3& center) const
{
    return (*this - center).Rotate(angle, axis);
}

Vector3 Vector3::Rotate(const float cos, const float sin, const Vector3& axis) const
{
    return Matrix3x3::Rotation3D(cos, sin, axis) * *this;
}

Vector3 Vector3::Rotate(const float cos, const float sin, const Vector3& axis, const Vector3& center) const
{
    return (*this - center).Rotate(cos, sin, axis);
}

float Vector3::Angle(const Vector3& a, const Vector3& b)
{
	return std::acos(Dot(a, b) / (a.Length() * b.Length()));
}

float Vector3::Dot(const Vector3& a, const Vector3& b)
{
	return a.Dot(b);
}

Vector3 Vector3::Cross(const Vector3& a, const Vector3& b)
{
	return a.Cross(b);
}
#pragma endregion

#pragma region operators

float Vector3::operator[](const size_t i) const
{
	assert(i >= 0 && i < 3 && "Vector3 subscript out of range");
    __assume(i >= 0 && i < 3);

	return *(&x + i);
}

float& Vector3::operator[](const size_t i)
{
	assert(i >= 0 && i < 3 && "Vector3 subscript out of range");
    __assume(i >= 0 && i < 3);

	return *(&x + i);
}

Vector3::operator Vector2() const
{
	return Vector2(x, y);
}

Vector3::operator Vector2i() const
{
	return Vector2i((int) x, (int) y);
}

Vector3::operator Vector4() const
{
	return Vector4(x, y, z, 1);
}

Vector3::operator Vector<3>() const
{
    return Vector<3>{ x, y, z };
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

Vector3 operator*(const Vector3& a, const float s)
{
	return Vector3(a.x * s, a.y * s, a.z * s);
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

Vector3 operator/(const Vector3& a, const float s)
{
	return Vector3(a.x / s, a.y / s, a.z / s);
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

bool operator==(const Vector3 &v, const float f)
{
    return v.x == f && v.y == f && v.z == f;
}

bool operator!=(const Vector3 &v, const float f)
{
    return !(v == f);
}

bool operator<(const Vector3 &v, const float f)
{
    return v.x < f && v.y < f && v.z < f;
}

bool operator>(const Vector3 &v, const float f)
{
    return v.x > f && v.y > f && v.z > f;
}

bool operator<=(const Vector3 &v, const float f)
{
    return v < f || v == f;
}

bool operator>=(const Vector3 &v, const float f)
{
    return v > f || v == f;
}

std::ostream& operator<<(std::ostream& out, const Vector3& v)
{
	char buffer[10];
	out << "[ ";
	sprintf_s(buffer, sizeof(buffer), "%6.3f", v.x);
	out << buffer << ", ";
	sprintf_s(buffer, sizeof(buffer), "%6.3f", v.y);
	out << buffer << ", ";
	sprintf_s(buffer, sizeof(buffer), "%6.3f", v.z);
	return out << buffer << " ]";
}
#pragma endregion
