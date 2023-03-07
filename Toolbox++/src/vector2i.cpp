#include "vector2i.hpp"

#include "matrix.hpp"

#define SQ(var) ((var) * (var))

Vector2i::Vector2i(const Vector2i p1, const Vector2i p2)
	: x(p2.x - p1.x), y(p2.y - p1.y)
{
}

#pragma region functions
float Vector2i::Norm() const
{
	return sqrt(SquaredNorm());
}

float Vector2i::SquaredNorm() const
{
	return (float) (x * x + y * y);
}

Vector2 Vector2i::Normalize() const
{
	float norm = Norm();
	assert(norm != 0.f && "Cannot normalize a zero vector");
    __assume(norm != 0.f);

	return Vector2(x / norm, y / norm);
}

Vector2 Vector2i::Normal() const
{
	return Vector2i(y, -x).Normalize();
}

float Vector2i::Angle() const
{
	return atan2f((float) y, (float) x);
}

Vector2 Vector2i::Rotate(const float angle) const
{
	float c = cos(angle);
	float s = sin(angle);
	return Rotate(c, s);
}

Vector2 Vector2i::Rotate(const float angle, const Vector2i center) const
{
	float c = cos(angle);
	float s = sin(angle);
	return Rotate(center, c, s);
}

Vector2 Vector2i::Rotate(const float cos, const float sin) const
{
	return Vector2(x * cos - y * sin, y * cos + x * sin);
}

Vector2 Vector2i::Rotate(const Vector2i center, const float cos, const float sin) const
{
	Vector2i temp = *this - center;
	return Vector2(temp.x * cos - temp.y * sin, temp.y * cos + temp.x * sin) + center;
}

float Vector2i::Angle(const Vector2i a, const Vector2i b)
{
	float dotProduct = DotProduct(a, b);
	float angle = std::acos(dotProduct / (a.Norm() * b.Norm()));

	if (Determinant(a, b) < 0)
		angle = -angle;

	return angle;
}

float Vector2i::DotProduct(const Vector2i a, const Vector2i b)
{
	return (float) (a.x * b.x + a.y * b.y);
}

float Vector2i::CrossProduct(const Vector2i a, const Vector2i b)
{
	// For a Vector2i this is only the determinant
	return Determinant(a, b);
}

float Vector2i::Determinant(const Vector2i a, const Vector2i b)
{
	return (float) ((a.x * b.y) - (b.x * a.y));
}
#pragma endregion

#pragma region operators
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
	return Vector2((float) x, (float) y);
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

Vector2i operator/(const Vector2i a, const Vector2i b)
{
	return Vector2i(a.x / b.x, a.y / b.y);
}

Vector2i operator/(const Vector2i a, const int s)
{
	return Vector2i(a.x / s, a.y / s);
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

Vector2i &operator/=(Vector2i &a, const Vector2i b)
{
	a.x /= b.x;
	a.y /= b.y;
	return a;
}

Vector2i& operator/=(Vector2i& v, const int factor)
{
	v.x /= factor;
	v.y /= factor;
	return v;
}

std::ostream& operator<<(std::ostream& out, const Vector2i v)
{
	char buffer[10];
	out << "[ ";
	sprintf_s(buffer, sizeof(buffer), "%6d", v.x);
	out << buffer << ", ";
	sprintf_s(buffer, sizeof(buffer), "%6d", v.y);
	return out << buffer << " ]";
}
#pragma endregion
