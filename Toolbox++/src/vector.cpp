#include "vector.hpp"

#include "matrix.hpp"
#include "vector3.hpp"

#define SQ(var) ((var) * (var))

#pragma region constructors
Vector::Vector(const size_t size, const float defaultValue)
    : mData(size), mSize(size)
{
    for (size_t i = 0; i < size; i++)
        mData[i] = defaultValue;
}

Vector::Vector(const Vector& p)
    : mData(p.mSize), mSize(p.mSize)
{
    for (size_t i = 0; i < mSize; i++)
        mData[i] = p[i];
}

Vector::Vector(const Vector& p1, const Vector& p2)
    : mData(p1.mSize), mSize(p1.mSize)
{
    assert(p1.GetSize() == p2.GetSize() && "Vectors must have the same size");
    __assume(p1.GetSize() == p2.GetSize());

    for (size_t i = 0; i < mSize; i++)
        mData[i] = p2[i] - p1[i];
}
#pragma endregion

#pragma region functions
float Vector::Norm() const
{
    return sqrt(SquaredNorm());
}

float Vector::SquaredNorm() const
{
    float result = 0;
    for (size_t i = 0; i < mSize; i++)
        result += SQ(mData[i]);
    return result;
}

Vector Vector::Normalized() const
{
    float norm = Norm();
	if (norm == 0)
		return 0;

    __assume(norm != 0.f);
    Vector result(mSize);
    for (size_t i = 0; i < mSize; i++)
        result[i] = mData[i] / norm;
    return result;
}

float Vector::Dot(const Vector& other) const
{
    assert(mSize == other.GetSize() && "Vectors must have the same size");
    __assume(mSize == other.GetSize());

    float result = 0;
    for (size_t i = 0; i < mSize; i++)
        result += mData[i] * other[i];
    return result;
}

Vector Vector::Cross(const Vector& other) const
{
    const size_t size = mSize;
    assert(size == other.GetSize() && "Vectors must have the same size");
    __assume(size == other.GetSize());

    Vector result(size);
    for (size_t i = 0; i < size; i++)
        result[i] = mData[(i + 1) % size] * other[(i + 2) % size] - mData[(i + 2) % size] * other[(i + 1) % size];
    return result;
}

float Vector::Dot(const Vector& a, const Vector& b)
{
    return a.Dot(b);
}

Vector Vector::Cross(const Vector& a, const Vector& b)
{
    return a.Cross(b);
}
#pragma endregion

#pragma region operators
float Vector::operator[](const size_t i) const
{
    return mData[i];
}

float &Vector::operator[](const size_t i)
{
    return mData[i];
}

Vector &Vector::operator=(const float value)
{
    mData[0] = value;
    return *this;
}

Vector::operator Vector2() const
{
    assert(mSize == 2 && "Vector must be of size 2 for a cast to Vector2");
    __assume(mSize == 2);

    return { mData[0], mData[1] };
}

Vector::operator Vector3() const
{
    assert(mSize == 3 && "Vector must be of size 3 for a cast to Vector3");
    __assume(mSize == 3);

    return { mData[0], mData[1], mData[2] };
}

Vector::operator Matrix() const
{
	Matrix result(mSize);
	for (size_t i = 0; i < mSize; i++)
		result[i] = mData[0];
	return result;
}

Vector operator+(const Vector& a, const Vector& b)
{
    assert(a.GetSize() == b.GetSize() && "Vectors must have the same size");
    __assume(a.GetSize() == b.GetSize());

    Vector result(a.GetSize());
    for (size_t i = 0; i < a.GetSize(); i++)
        result[i] = a[i] + b[i];
    return result;
}

Vector operator-(const Vector& a, const Vector& b)
{
    assert(a.GetSize() == b.GetSize() && "Vectors must have the same size");
    __assume(a.GetSize() == b.GetSize());

    Vector result(a.GetSize());
    for (size_t i = 0; i < a.GetSize(); i++)
        result[i] = a[i] - b[i];
    return result;
}

Vector operator-(const Vector& a)
{
    Vector result(a.GetSize());
    for (size_t i = 0; i < a.GetSize(); i++)
        result[i] = -a[i];
    return result;
}

Vector operator*(const Vector& a, const Vector& b)
{
    assert(a.GetSize() == b.GetSize() && "Vectors must have the same size");
    __assume(a.GetSize() == b.GetSize());
    
    Vector result(a.GetSize());
    for (size_t i = 0; i < a.GetSize(); i++)
        result[i] = a[i] * b[i];
    return result;
}

Vector operator*(const Vector& a, const float s)
{
    Vector result(a.GetSize());
    for (size_t i = 0; i < a.GetSize(); i++)
        result[i] = a[i] * s;
    return result;
}

Vector operator/(const Vector& a, const Vector& b)
{
    assert(a.GetSize() == b.GetSize() && "Vectors must have the same size");
    __assume(a.GetSize() == b.GetSize());

    Vector result(a.GetSize());
    for (size_t i = 0; i < a.GetSize(); i++)
        result[i] = a[i] / b[i];
    return result;
}

Vector operator/(const Vector& a, const float s)
{
    Vector result(a.GetSize());
    for (size_t i = 0; i < a.GetSize(); i++)
        result[i] = a[i] / s;
    return result;
}

Vector& operator+=(Vector& a, const Vector& b)
{
    assert(a.GetSize() == b.GetSize() && "Vectors must have the same size");
    __assume(a.GetSize() == b.GetSize());

    for (size_t i = 0; i < a.GetSize(); i++)
        a[i] += b[i];
    return a;
}

Vector& operator+=(Vector& v, const float factor)
{
    for (size_t i = 0; i < v.GetSize(); i++)
        v[i] += factor;
    return v;
}

Vector &operator-=(Vector &a, const Vector& b)
{
    assert(a.GetSize() == b.GetSize() && "Vectors must have the same size");
    __assume(a.GetSize() == b.GetSize());

    for (size_t i = 0; i < a.GetSize(); i++)
        a[i] -= b[i];
    return a;
}

Vector& operator-=(Vector& v, const float factor)
{
    for (size_t i = 0; i < v.GetSize(); i++)
        v[i] -= factor;
    return v;
}

Vector& operator*=(Vector& a, const Vector& b)
{
    assert(a.GetSize() == b.GetSize() && "Vectors must have the same size");
    __assume(a.GetSize() == b.GetSize());

    for (size_t i = 0; i < a.GetSize(); i++)
        a[i] *= b[i];
    return a;
}

Vector& operator*=(Vector& v, const float factor)
{
    for (size_t i = 0; i < v.GetSize(); i++)
        v[i] *= factor;
    return v;
}

Vector &operator/=(Vector &a, const Vector& b)
{
    assert(a.GetSize() == b.GetSize() && "Vectors must have the same size");
    __assume(a.GetSize() == b.GetSize());

    for (size_t i = 0; i < a.GetSize(); i++)
        a[i] /= b[i];
    return a;
}

Vector& operator/=(Vector& v, const float factor)
{
    for (size_t i = 0; i < v.GetSize(); i++)
        v[i] /= factor;
    return v;
}

std::ostream& operator<<(std::ostream& out, const Vector& v)
{
    out << "[ ";
    for (size_t i = 0; i < v.GetSize(); i++)
    {
        char buffer[10];
        sprintf_s(buffer, sizeof(buffer), "%6.3f", v[i]);
        out << buffer;
        if (i != v.GetSize() - 1)
            out << ", ";
        else
            out << " ";
    }
    return out << "]";
}
#pragma endregion
