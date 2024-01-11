#include "quaternion.hpp"

#include "calc.hpp"
#include "matrix.hpp"

constexpr Quaternion Quaternion::Zero() noexcept
{
	return Quaternion();
}

constexpr Quaternion Quaternion::UnitX() noexcept
{
	return Quaternion(1.f, 0.f, 0.f, 0.f);
}

constexpr Quaternion Quaternion::UnitY() noexcept
{
	return Quaternion(0.f, 1.f, 0.f, 0.f);
}

constexpr Quaternion Quaternion::UnitZ() noexcept
{
	return Quaternion(0.f, 0.f, 1.f, 0.f);
}

constexpr Quaternion Quaternion::UnitW() noexcept
{
	return Quaternion(0.f, 0.f, 0.f, 1.f);
}

constexpr Quaternion Quaternion::Identity() noexcept
{
	return UnitW();
}

constexpr Quaternion::Quaternion(const Vector4& values)
	: imaginary(static_cast<Vector3>(values))
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

constexpr const float* Quaternion::Raw() const
{
	return &imaginary.x;
}

constexpr float* Quaternion::Raw()
{
	return &imaginary.x;
}

float& Quaternion::X()
{
	return imaginary.x;
}

float& Quaternion::Y()
{
	return imaginary.y;
}

float& Quaternion::Z()
{
	return imaginary.z;
}

float& Quaternion::W()
{
	return real;
}

float Quaternion::X() const
{
	return imaginary.x;
}

float Quaternion::Y() const
{
	return imaginary.y;
}

float Quaternion::Z() const
{
	return imaginary.z;
}

float Quaternion::W() const
{
	return real;
}

Quaternion Quaternion::Conjugate() const
{
	return Quaternion(-imaginary, real);
}

float Quaternion::Length() const
{
	return std::sqrt(SquaredLength());
}

float Quaternion::SquaredLength() const
{
	return SQ(imaginary.x) + SQ(imaginary.y) + SQ(imaginary.z) + SQ(real);
}

Quaternion Quaternion::Inverse() const
{
	const float sqLength = SquaredLength();
	
	if (sqLength > 0.f) 
	{
		return Conjugate() / sqLength;
	}
	
	return Zero();
}

float Quaternion::Dot(const Quaternion& other) const
{
	return Dot(*this, other);
}

Vector3 Quaternion::Rotate(const Vector3& point) const
{
	return Rotate(point, *this);
}

Quaternion Quaternion::FromAxisAngle(const Vector3& axis, const float angle)
{
	const float halfAngle = angle * 0.5f;
	const float s = std::sin(halfAngle);
	const float c = std::cos(halfAngle);

	Quaternion quat;

	quat.X() = axis.x * s;
	quat.Y() = axis.y * s;
	quat.Z() = axis.z * s;
	quat.W() = c;

	return quat;
}

Quaternion Quaternion::FromEuler(const Vector3& rotation)
{
	const float cr = cos(rotation.x * 0.5f);
	const float sr = sin(rotation.x * 0.5f);
	const float cp = cos(rotation.y * 0.5f);
	const float sp = sin(rotation.y * 0.5f);
	const float cy = cos(rotation.z * 0.5f);
	const float sy = sin(rotation.z * 0.5f);

	Quaternion quat;
	
	quat.X() = sr * cp * cy - cr * sp * sy;
	quat.Y() = cr * sp * cy + sr * cp * sy;
	quat.Z() = cr * cp * sy - sr * sp * cy;
	quat.W() = cr * cp * cy + sr * sp * sy;
	
	return quat;
}

Quaternion Quaternion::FromRotationMatrix(const Matrix& rotation)
{
	const float trace = rotation.Trace() - rotation[3][3];

	Quaternion q;

	if (trace > 0.f)
	{
		float s = std::sqrt(trace + 1.f);
		q.W() = s * 0.5f;
		s = 0.5f / s;
		q.X() = (rotation[2][1] - rotation[1][2]) * s;
		q.Y() = (rotation[0][2] - rotation[2][0]) * s;
		q.Z() = (rotation[1][0] - rotation[0][1]) * s;
	}
	else
	{
		if (rotation[0][0] >= rotation[1][1] && rotation[0][0] >= rotation[2][2])
		{
			const float s = std::sqrt(1.f + rotation[0][0] - rotation[1][1] - rotation[2][2]);
			const float invS = 0.5f / s;
			q.X() = 0.5f * s;
			q.Y() = (rotation[1][0] + rotation[0][1]) * invS;
			q.Z() = (rotation[2][0] + rotation[0][2]) * invS;
			q.W() = (rotation[2][1] - rotation[1][2]) * invS;
		}
		else if (rotation[1][1] > rotation[2][2])
		{
			const float s = std::sqrt(1.f + rotation[1][1] - rotation[0][0] - rotation[2][2]);
			const float invS = 0.5f / s;
			q.X() = (rotation[0][1] + rotation[1][0]) * invS;
			q.Y() = 0.5f * s;
			q.Z() = (rotation[1][2] + rotation[2][1]) * invS;
			q.W() = (rotation[0][2] - rotation[2][0]) * invS;
		}
		else
		{
			const float s = std::sqrt(1.f + rotation[2][2] - rotation[0][0] - rotation[1][1]);
			const float invS = 0.5f / s;
			q.X() = (rotation[0][2] + rotation[2][0]) * invS;
			q.Y() = (rotation[1][2] + rotation[2][1]) * invS;
			q.Z() = 0.5f * s;
			q.W() = (rotation[1][0] - rotation[0][1]) * invS;
		}
	}

	return q;
}

float Quaternion::Dot(const Quaternion& a, const Quaternion& b)
{
	return a.X() * b.X()
		 + a.Y() * b.Y()
		 + a.Z() * b.Z()
		 + a.W() * b.W();
}

Quaternion Quaternion::Lerp(const Quaternion& a, const Quaternion& b, const float t)
{
	const float t1 = 1.f - t;

	Quaternion r;

	const float dot = Dot(a, b);

	if (dot >= 0.f)
	{
		r.X() = t1 * a.X() + t * b.X();
		r.Y() = t1 * a.Y() + t * b.Y();
		r.Z() = t1 * a.Z() + t * b.Z();
		r.W() = t1 * a.W() + t * b.W();
	}
	else
	{
		r.X() = t1 * a.X() - t * b.X();
		r.Y() = t1 * a.Y() - t * b.Y();
		r.Z() = t1 * a.Z() - t * b.Z();
		r.W() = t1 * a.W() - t * b.W();
	}

	// Normalize it.
	const float ls = r.X() * r.X() + r.Y() * r.Y() + r.Z() * r.Z() + r.W() * r.W();
	const float invNorm = 1.f / std::sqrt(ls);

	r.X() *= invNorm;
	r.Y() *= invNorm;
	r.Z() *= invNorm;
	r.W() *= invNorm;

	return r;
}

Quaternion Quaternion::Slerp(const Quaternion& a, const Quaternion& b, const float t)
{
	float cosOmega = a.X() * b.X() + a.Y() * b.Y() +
					 a.Z() * b.Z() + a.W() * b.W();

	bool flip = false;

	if (cosOmega < 0.f)
	{
		flip = true;
		cosOmega = -cosOmega;
	}

	float s1, s2;

	if (cosOmega > 1.f - calc::Zero)
	{
		// Too close, do straight linear interpolation.
		s1 = 1.f - t;
		s2 = flip ? -t : t;
	}
	else
	{
		const float omega = std::acos(cosOmega);
		const float invSinOmega = 1.f / std::sin(omega);

		s1 = std::sin((1.f - t) * omega) * invSinOmega;
		s2 = flip
			? -std::sin(t * omega) * invSinOmega
			: std::sin(t * omega) * invSinOmega;
	}

	Quaternion ans;

	ans.X() = s1 * a.X() + s2 * b.X();
	ans.Y() = s1 * a.Y() + s2 * b.Y();
	ans.Z() = s1 * a.Z() + s2 * b.Z();
	ans.W() = s1 * a.W() + s2 * b.W();

	return ans;
}

Vector3 Quaternion::Rotate(const Vector3& point, const Quaternion& rotation)
{
	return static_cast<Vector3>(rotation * point * rotation.Conjugate());
}

float Quaternion::operator[](const size_t i) const
{
	return (&imaginary.x)[i];
}

float& Quaternion::operator[](const size_t i)
{
	return (&imaginary.x)[i];
}

Quaternion::operator Vector3() const
{
	return imaginary;
}

Quaternion::operator Vector4() const
{
	return Vector4(imaginary.x, imaginary.y, imaginary.z, real);
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
	Quaternion result;

	const float q1x = a.X();
	const float q1y = a.Y();
	const float q1z = a.Z();
	const float q1w = a.W();

	const float q2x = b.X();
	const float q2y = b.Y();
	const float q2z = b.Z();
	const float q2w = b.W();

	// cross(av, bv)
	const float cx = q1y * q2z - q1z * q2y;
	const float cy = q1z * q2x - q1x * q2z;
	const float cz = q1x * q2y - q1y * q2x;

	const float dot = q1x * q2x + q1y * q2y + q1z * q2z;

	result.X() = q1x * q2w + q2x * q1w + cx;
	result.Y() = q1y * q2w + q2y * q1w + cy;
	result.Z() = q1z * q2w + q2z * q1w + cz;
	result.W() = q1w * q2w - dot;

	return result;
}

Quaternion operator*(const Quaternion& q, const Vector3& v)
{
	return q * Quaternion(v, 1.f);
}

Quaternion operator*(const Quaternion& v, const float factor)
{
	return Quaternion(v.imaginary * factor, v.real * factor);
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

Quaternion& operator/=(Quaternion& v, const float factor)
{
	return v = v * factor;
}

bool operator==(Quaternion a, Quaternion b)
{
	return calc::Equals(a.imaginary.x, b.imaginary.x)
		&& calc::Equals(a.imaginary.y, b.imaginary.y)
		&& calc::Equals(a.imaginary.z, b.imaginary.z)
		&& calc::Equals(a.real, b.real);
}

bool operator!=(Quaternion a, Quaternion b)
{
	return !(a == b);
}

std::ostream& operator<<(std::ostream& out, const Quaternion& q)
{
	return out << std::format("{{{:6.3f} {:6.3f} {:6.3f} {:6.3f}}}", q.imaginary.x, q.imaginary.y, q.imaginary.z, q.real);
}
