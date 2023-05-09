#include "vector4.hpp"

#include "matrix.hpp"
#include "matrix4x4.hpp"
#include "vector3.hpp"

#define SQ(var) ((var) * (var))

Vector4::Vector4(const Vector4& p1, const Vector4& p2)
	: x(p2.x - p1.x), y(p2.y - p1.y), z(p2.z - p1.z), w(p2.w - p1.w)
{
}

#pragma region functions
float Vector4::Norm() const
{
	return sqrt(SquaredNorm());
}

float Vector4::SquaredNorm() const
{
	return x * x + y * y + z * z + w * w;
}

Vector4 Vector4::Normalized() const
{
	float norm = Norm();
	if (norm == 0)
		return 0;

    __assume(norm != 0.f);
	return Vector4(x / norm, y / norm, z / norm, w / norm);
}

float Vector4::Dot(const Vector4& other) const
{
	return x * other.x + y * other.y + z * other.z + w * other.w;
}

float Vector4::Dot(const Vector4& a, const Vector4& b)
{
	return a.Dot(b);
}
#pragma endregion

#pragma region operators

float Vector4::operator[](const size_t i) const
{
	assert(i >= 0 && i < 4 && "Vector4 subscript out of range");
    __assume(i >= 0 && i < 4);

	return *(&x + i);
}

float& Vector4::operator[](const size_t i)
{
	assert(i >= 0 && i < 4 && "Vector4 subscript out of range");
    __assume(i >= 0 && i < 4);

	return *(&x + i);
}

Vector4::operator Vector2() const
{
	return Vector2(x, y);
}

Vector4::operator Vector3() const
{
	return Vector3(x, y, z);
}

Vector4::operator Matrix() const
{
	Matrix result(4);
	for (size_t i = 0; i < 4; i++)
		result[i] = operator[](i);
	return result;
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

Vector4 operator*(const Vector4& a, const float s)
{
	return Vector4(a.x * s, a.y * s, a.z * s, a.w * s);
}

Vector4 operator*(const Vector4 &v, const Matrix4x4 &m)
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

Vector4 operator/(const Vector4& a, const float s)
{
	return Vector4(a.x / s, a.y / s, a.z / s, a.w / s);
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

Vector4 &operator*=(Vector4 &v, const Matrix4x4 &m)
{
    return v = v * m;
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

bool operator==(const Vector4 &v, const float f)
{
    return v.x == f && v.y == f && v.z == f && v.w == f;
}

bool operator!=(const Vector4 &v, const float f)
{
    return !(v == f);
}

bool operator<(const Vector4 &v, const float f)
{
    return v.x < f && v.y < f && v.z < f && v.w < f;
}

bool operator>(const Vector4 &v, const float f)
{
    return v.x > f && v.y > f && v.z > f && v.w > f;
}

bool operator<=(const Vector4 &v, const float f)
{
    return v < f || v == f;
}

bool operator>=(const Vector4 &v, const float f)
{
    return v > f || v == f;
}

std::ostream& operator<<(std::ostream& out, const Vector4& v)
{
	char buffer[10];
	out << "[ ";
	sprintf_s(buffer, sizeof(buffer), "%6.3f", v.x);
	out << buffer << ", ";
	sprintf_s(buffer, sizeof(buffer), "%6.3f", v.y);
	out << buffer << ", ";
	sprintf_s(buffer, sizeof(buffer), "%6.3f", v.z);
	out << buffer << ", ";
	sprintf_s(buffer, sizeof(buffer), "%6.3f", v.w);
	return out << buffer << " ]";
}
#pragma endregion
