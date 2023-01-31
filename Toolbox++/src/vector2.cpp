#include "vector2.hpp"

namespace calc
{
#pragma region defines
	#define SQ(var) ((var) * (var))
#pragma endregion

#pragma region constants
	const Vector2 Vector2::Zero(0.f, 0.f);
	const Vector2 Vector2::UnitY(0.f, 1.f);
	const Vector2 Vector2::UnitX(1.f, 0.f);
#pragma endregion

#pragma region constructors
	Vector2::Vector2()
		: x(0), y(0)
	{
	}

	Vector2::Vector2(const float xy)
		: x(xy), y(xy)
	{
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

    float Angle(const Vector2 a, const Vector2 b)
    {
		float dotProduct = DotProduct(a, b);
		float angle = acosf(
			dotProduct / (a.GetNorm() * b.GetNorm())
		);

		if (Determinant(a, b) < 0)
			angle = -angle;

		return angle;
    }

    float DotProduct(const Vector2 a, const Vector2 b)
    {
		return a.x * b.x + a.y * b.y;
    }

    float Determinant(const Vector2 a, const Vector2 b)
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

#pragma region Point2
	float Dist(const Vector2 p1, const Vector2 p2)
	{
		return std::sqrt(DistSquared(p1, p2));
	}

	float DistSquared(const Vector2 p1, const Vector2 p2)
	{
		return SQ(p1.x - p2.x) + SQ(p1.y - p2.y);
	}

	Vector2 Mid(const Vector2 p1, const Vector2 p2)
	{
		return Vector2((p1.x + p2.x) / 2, (p1.y + p2.y) / 2);
	}

	Vector2 Rotate(const Vector2 p, const float angle)
	{
		float c = cos(angle);
		float s = sin(angle);

		return Vector2(p.x * c - p.y * s, p.y * c + p.x * s);
	}

	Vector2 Rotate(const Vector2 p, const Vector2 center, float angle)
	{
		float _x = p.x - center.x;
		float _y = p.y - center.y;

		float c = cos(angle);
		float s = sin(angle);

		return Vector2(center.x + _x * c - _y * s, center.y + _y * c + _x * s);
	}

	Vector2 Rotate(const Vector2 p, float cos, float sin)
	{
		return Vector2(p.x * cos - p.y * sin, p.y * cos + p.x * sin);
	}

	Vector2 Rotate(const Vector2 p, const Vector2 center, float cos, float sin)
	{
		float _x = p.x - center.x;
		float _y = p.y - center.y;

		return Vector2(center.x + _x * cos - _y * sin, center.y + _y * cos + _x * sin);
	}

	Vector2 Scale(const Vector2 p, float scale)
	{
		return Vector2(p.x * scale, p.y * scale);
	}

	Vector2 Scale(const Vector2 p, const Vector2 center, float scale)
	{

		return Vector2(scale * (p.x - center.x), scale * (p.y - center.y)) + center;
	}

	Vector2 Circumcenter(const Vector2 p1, const Vector2 p2, const Vector2 p3)
	{
		float d = 2 * (
			p1.x * (p2.y - p3.y) +
			p2.x * (p3.y - p1.y) +
			p3.x * (p1.y - p2.y)
			);

		return Vector2((
			(SQ(p1.x) + SQ(p1.y)) * (p2.y - p3.y) +
			(SQ(p2.x) + SQ(p2.y)) * (p3.y - p1.y) +
			(SQ(p3.x) + SQ(p3.y)) * (p1.y - p2.y)
			) / d,
			((SQ(p1.x) + SQ(p1.y)) * (p3.x - p2.x) +
			(SQ(p2.x) + SQ(p2.y)) * (p1.x - p3.x) +
			(SQ(p3.x) + SQ(p3.y)) * (p2.x - p1.x)
			) / d);
	}

	Vector2 IsobarycenterTriangle(const Vector2 p1, const Vector2 p2, const Vector2 p3)
	{
		return Vector2((p1.x + p2.x + p3.x) / 3, (p1.y + p2.y + p3.y) / 3);
	}
#pragma endregion
}
