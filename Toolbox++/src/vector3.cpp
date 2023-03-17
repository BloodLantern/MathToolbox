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
	return sqrt(SquaredNorm());
}

float Vector3::SquaredNorm() const
{
	return x * x + y * y + z * z;
}

Vector3 Vector3::Normalized() const
{
	float norm = Norm();
	if (norm == 0)
		return 0;

    __assume(norm != 0.f);
	return Vector3(x / norm, y / norm, z / norm);
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
    return (Vector3) (Matrix::RotationMatrix3D(angle, axis) * (*this));
}

Vector3 Vector3::Rotate(const float angle, const Vector3& axis, const Vector3& center) const
{
    return (*this - center).Rotate(angle, axis);
}

Vector3 Vector3::Rotate(const float cos, const float sin, const Vector3& axis) const
{
    return (Vector3) (Matrix::RotationMatrix3D(cos, sin, axis) * (*this));
}

Vector3 Vector3::Rotate(const float cos, const float sin, const Vector3& axis, const Vector3& center) const
{
    return (*this - center).Rotate(cos, sin, axis);
}

float Vector3::Angle(const Vector3& a, const Vector3& b)
{
	return std::acos(Dot(a, b) / (a.Norm() * b.Norm()));
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

Vector3::operator Matrix() const
{
	Matrix result(3);
	for (size_t i = 0; i < 3; i++)
		result[i] = operator[](i);
	return result;
}

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
