#include "quaternion.hpp"

#include <cassert>

#define SQ(x) ((x) * (x))

constexpr void FromRotation(Quaternion& quat, const float xRotation, const float yRotation, const float zRotation)
{
	float cr = std::cos(xRotation * 0.5f);
	float sr = std::sin(xRotation * 0.5f);
	float cp = std::cos(yRotation * 0.5f);
	float sp = std::sin(yRotation * 0.5f);
	float cy = std::cos(zRotation * 0.5f);
	float sy = std::sin(zRotation * 0.5f);
	
	quat.X() = sr * cp * cy - cr * sp * sy;
	quat.Y() = cr * sp * cy + sr * cp * sy;
	quat.Z() = cr * cp * sy - sr * sp * cy;
	quat.W() = cr * cp * cy + sr * sp * sy;
}

constexpr void FromRotation(Quaternion& quat, const Vector3& rotation)
{
	FromRotation(quat, rotation.x, rotation.y, rotation.z);
}

constexpr Quaternion Quaternion::Zero()
{
	return Quaternion();
}

constexpr Quaternion Quaternion::UnitX()
{
	return Quaternion(1.0f, 0.0f, 0.0f, 0.0f);
}

constexpr Quaternion Quaternion::UnitY()
{
	return Quaternion(0.0f, 1.0f, 0.0f, 0.0f);
}

constexpr Quaternion Quaternion::UnitZ()
{
	return Quaternion(0.0f, 0.0f, 1.0f, 0.0f);
}

constexpr Quaternion Quaternion::UnitW()
{
	return Quaternion(0.0f, 0.0f, 0.0f, 1.0f);
}

constexpr Quaternion Quaternion::Identity()
{
	return UnitW();
}

constexpr Quaternion::Quaternion()
	: real()
{
}

constexpr Quaternion::Quaternion(const Vector4& values)
	: imaginary((Vector3) values)
	, real(values.w)
{
}

constexpr Quaternion::Quaternion(const Vector3& imaginary, const float real)
	: imaginary(imaginary)
	, real(real)
{
}

constexpr Quaternion::Quaternion(const float xyzw)
	: imaginary(xyzw)
	, real(xyzw)
{
}

constexpr Quaternion::Quaternion(const float x, const float y, const float z, const float w)
	: imaginary(x, y, z)
	, real(w)
{
}

constexpr Quaternion::Quaternion(const std::initializer_list<float>& values)
{
	assert(values.size() == 3 || values.size() == 4 && "Cannot initialize Quaternion from initializer list with size != 3 && size != 4");

	const float* it = values.begin();
	if (values.size() == 3)
	{
		FromRotation(*this, it[0], it[1], it[2]);
	}
	else
	{
		imaginary = Vector3(it[0], it[1], it[2]);
		real = it[3];
	}
}

constexpr Quaternion::Quaternion(const Vector3& rotation)
{
	FromRotation(*this, rotation);
}

constexpr Quaternion::Quaternion(const float xRotation, const float yRotation, const float zRotation)
{
	FromRotation(*this, xRotation, yRotation, zRotation);
}

constexpr float& Quaternion::X()
{
	return imaginary.x;
}

constexpr float& Quaternion::Y()
{
	return imaginary.y;
}

constexpr float& Quaternion::Z()
{
	return imaginary.z;
}

constexpr float& Quaternion::W()
{
	return real;
}

constexpr Quaternion Quaternion::Conjugate() const
{
	return Quaternion(-imaginary, real);
}

float Quaternion::Length() const
{
	return std::sqrt(SquaredLength());
}

constexpr float Quaternion::SquaredLength() const
{
	return SQ(imaginary.x) + SQ(imaginary.y) + SQ(imaginary.z) + SQ(real);
}

constexpr Quaternion Quaternion::Inverse() const
{
	float norm = SquaredLength();
	if (norm > 0.f) 
	{
		float invNorm = 1.f / norm;
		return Quaternion(-X() * invNorm, -Y() * invNorm, -Z() * invNorm, W() * invNorm);
	}
	return Quaternion::Zero();
}

constexpr float Quaternion::X() const
{
	return imaginary.x;
}

constexpr float Quaternion::Y() const
{
	return imaginary.y;
}

constexpr float Quaternion::Z() const
{
	return imaginary.z;
}

constexpr float Quaternion::W() const
{
	return real;
}

constexpr float Quaternion::operator[](const size_t i) const
{
	return (&imaginary.x)[i];
}

constexpr float& Quaternion::operator[](const size_t i)
{
	return (&imaginary.x)[i];
}

constexpr Quaternion::operator Vector4() const
{
	return Vector4(imaginary, real);
}

constexpr Quaternion::operator Vector<4>() const
{
	return
	{
		imaginary.x,
		imaginary.y,
		imaginary.z,
		real
	};
}

Quaternion operator+(const Quaternion& a, const Quaternion& b)
{
	return Quaternion(a.imaginary + b.imaginary, a.real + b.real);
}

Quaternion operator-(const Quaternion& a, const Quaternion& b)
{
	return Quaternion(a + -b);
}

Quaternion operator-(const Quaternion& a)
{
	return Quaternion(-a.imaginary, -a.real);
}

Quaternion operator*(const Quaternion& a, const Quaternion& b)
{
	return Quaternion(
		a.X() * b.W() + a.W() * b.X() - a.Z() * b.Y() + a.Y() * b.Z(),
		a.Y() * b.W() + a.Z() * b.X() + a.W() * b.Y() - a.X() * b.Z(),
		a.Z() * b.W() - a.Y() * b.X() + a.X() * b.Y() + a.W() + b.Z(),
		a.W() * b.W() - a.X() * b.X() - a.Y() * b.Y() - a.Z() * b.Z()
	);
}

Quaternion operator*(const Quaternion& v, const float factor)
{
	return Quaternion(v.imaginary * factor, v.real * factor);
}

Quaternion operator/(const Quaternion& a, const Quaternion& b)
{
	return Quaternion(a.imaginary / b.imaginary, a.real / b.real);
}

Quaternion operator/(const Quaternion& v, const float factor)
{
	return Quaternion(v.imaginary / factor, v.real / factor);
}

Quaternion& operator+=(Quaternion& a, const Quaternion& b)
{
	return a = a + b;
}

Quaternion& operator-=(Quaternion& a, const Quaternion& b)
{
	return a = a - b;
}

Quaternion& operator*=(Quaternion& a, const Quaternion& b)
{
	return a = a * b;
}

Quaternion& operator*=(Quaternion& v, const float factor)
{
	return v = v * factor;
}

Quaternion& operator/=(Quaternion& a, const Quaternion& b)
{
	return a = a / b;
}

Quaternion& operator/=(Quaternion& v, const float factor)
{
	return v = v * factor;
}

std::ostream& operator<<(std::ostream& out, const Quaternion& v)
{
	char buffer[10];
	out << "[ ";
	(void) sprintf_s(buffer, sizeof(buffer), "%6.3f", v.imaginary.x);
	out << buffer << ", ";
	(void) sprintf_s(buffer, sizeof(buffer), "%6.3f", v.imaginary.y);
	out << buffer << ", ";
	(void) sprintf_s(buffer, sizeof(buffer), "%6.3f", v.imaginary.z);
	out << buffer << ", ";
	(void) sprintf_s(buffer, sizeof(buffer), "%6.3f", v.real);
	return out << buffer << " ]";
}
