#include "vector.hpp"

#pragma region defines
#define SQ(var) ((var) * (var))
#pragma endregion

#pragma region constructors
Vector::Vector()
{
    mData.resize(1);
    mData[0] = 0;
}

Vector::Vector(const size_t size, const float defaultValue)
{
    mData.resize(size);
    for (size_t i = 0; i < size; i++)
        mData[i] = defaultValue;
}

Vector::Vector(const Vector& p)
{
    mData.resize(p.GetSize());
    for (size_t i = 0; i < size; i++)
        mData[i] = defaultValue;
}

Vector::Vector(...)
{
    va_list args;

}

Vector::Vector(const std::initializer_list<float> &values)
{
    mData.resize(values.size());

    const float* it = values.begin();
    for (size_t i = 0; i < values.size(); i++)
        mData[i] = it[i];
}

Vector::Vector(const Vector& p1, const Vector& p2)
{
}
#pragma endregion

#pragma region functions
float Vector::Norm() const
{
    return sqrt(x * x + y * y);
}

float Vector::SquaredNorm() const
{
    return x * x + y * y;
}

Vector Vector::Normalize() const
{
    float norm = Norm();
    return Vector(x / norm, y / norm);
}

Vector Vector::Normal() const
{
    return Vector(y, -x).Normalize();
}

float Vector::Angle() const
{
    return atan2f(y, x);
}

Vector Vector::Rotate(float angle) const
{
    float c = cos(angle);
    float s = sin(angle);

    return Vector(x * c - y * s, y * c + x * s);
}

float Angle(const Vector a, const Vector b)
{
    float dotProduct = DotProduct(a, b);
    float angle = acosf(
        dotProduct / (a.Norm() * b.Norm())
    );

    if (Determinant(a, b) < 0)
        angle = -angle;

    return angle;
}

float DotProduct(const Vector a, const Vector b)
{
    return a.x * b.x + a.y * b.y;
}

float Determinant(const Vector a, const Vector b)
{
    return (a.x * b.y) - (b.x * a.y);
}
#pragma endregion

#pragma region operators
Vector operator+(const Vector a, const Vector b)
{
    return Vector(a.x + b.x, a.y + b.y);
}

Vector operator-(const Vector a, const Vector b)
{
    return Vector(a.x - b.x, a.y - b.y);
}

Vector operator-(const Vector a)
{
    return Vector(-a.x, -a.y);
}

Vector operator*(const Vector a, const Vector b)
{
    return Vector(a.x * b.x, a.y * b.y);
}

Vector operator*(const Vector a, const float s)
{
    return Vector(a.x * s, a.y * s);
}

Vector operator/(const Vector a, const Vector b)
{
    return Vector(a.x / b.x, a.y / b.y);
}

Vector operator/(const Vector a, const float s)
{
    return Vector(a.x / s, a.y / s);
}

Vector& operator+=(Vector& a, const Vector b)
{
    a.x += b.x;
    a.y += b.y;
    return a;
}

Vector& operator+=(Vector& v, const float factor)
{
    v.x += factor;
    v.y += factor;
    return v;
}

Vector &operator-=(Vector &a, const Vector b)
{
    a.x -= b.x;
    a.y -= b.y;
    return a;
}

Vector& operator-=(Vector& v, const float factor)
{
    v.x -= factor;
    v.y -= factor;
    return v;
}

Vector& operator*=(Vector& a, const Vector b)
{
    a.x *= b.x;
    a.y *= b.y;
    return a;
}

Vector& operator*=(Vector& v, const float factor)
{
    v.x *= factor;
    v.y *= factor;
    return v;
}

Vector &operator/=(Vector &a, const Vector b)
{
    a.x /= b.x;
    a.y /= b.y;
    return a;
}

Vector& operator/=(Vector& v, const float factor)
{
    v.x /= factor;
    v.y /= factor;
    return v;
}

std::ostream& operator<<(std::ostream& out, const Vector& v)
{
    return out << "{ " << v.x << " ; " << v.y << " }";
}
#pragma endregion

#pragma region Point
float Dist(const Vector p1, const Vector p2)
{
    return std::sqrt(DistSquared(p1, p2));
}

float DistSquared(const Vector p1, const Vector p2)
{
    return SQ(p1.x - p2.x) + SQ(p1.y - p2.y);
}

Vector Mid(const Vector p1, const Vector p2)
{
    return Vector((p1.x + p2.x) / 2, (p1.y + p2.y) / 2);
}

Vector Rotate(const Vector p, const float angle)
{
    float c = cos(angle);
    float s = sin(angle);

    return Vector(p.x * c - p.y * s, p.y * c + p.x * s);
}

Vector Rotate(const Vector p, const Vector center, float angle)
{
    float _x = p.x - center.x;
    float _y = p.y - center.y;

    float c = cos(angle);
    float s = sin(angle);

    return Vector(center.x + _x * c - _y * s, center.y + _y * c + _x * s);
}

Vector Rotate(const Vector p, float cos, float sin)
{
    return Vector(p.x * cos - p.y * sin, p.y * cos + p.x * sin);
}

Vector Rotate(const Vector p, const Vector center, float cos, float sin)
{
    float _x = p.x - center.x;
    float _y = p.y - center.y;

    return Vector(center.x + _x * cos - _y * sin, center.y + _y * cos + _x * sin);
}

Vector Scale(const Vector p, float scale)
{
    return Vector(p.x * scale, p.y * scale);
}

Vector Scale(const Vector p, const Vector center, float scale)
{

    return Vector(scale * (p.x - center.x), scale * (p.y - center.y)) + center;
}

Vector Circumcenter(const Vector p1, const Vector p2, const Vector p3)
{
    float d = 2 * (
        p1.x * (p2.y - p3.y) +
        p2.x * (p3.y - p1.y) +
        p3.x * (p1.y - p2.y)
        );

    return Vector((
        (SQ(p1.x) + SQ(p1.y)) * (p2.y - p3.y) +
        (SQ(p2.x) + SQ(p2.y)) * (p3.y - p1.y) +
        (SQ(p3.x) + SQ(p3.y)) * (p1.y - p2.y)
        ) / d,
        ((SQ(p1.x) + SQ(p1.y)) * (p3.x - p2.x) +
        (SQ(p2.x) + SQ(p2.y)) * (p1.x - p3.x) +
        (SQ(p3.x) + SQ(p3.y)) * (p2.x - p1.x)
        ) / d);
}

Vector IsobarycenterTriangle(const Vector p1, const Vector p2, const Vector p3)
{
    return Vector((p1.x + p2.x + p3.x) / 3, (p1.y + p2.y + p3.y) / 3);
}
#pragma endregion
