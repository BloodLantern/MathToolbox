#include "quaternion.hpp"

#include "calc.hpp"
#include "matrix.hpp"

float Quaternion::Length() const noexcept
{
	return std::sqrt(SquaredLength());
}

Quaternion Quaternion::FromAxisAngle(const Vector3& axis, const float angle) noexcept
{
	Quaternion result;
	FromAxisAngle(axis, angle, result);
	return result;
}

void Quaternion::FromAxisAngle(const Vector3& axis, float angle, Quaternion& result) noexcept
{
	const float halfAngle = angle * 0.5f;
	const float s = std::sin(halfAngle);
	const float c = std::cos(halfAngle);

	result.X() = axis.x * s;
	result.Y() = axis.y * s;
	result.Z() = axis.z * s;
	result.W() = c;
}

Quaternion Quaternion::FromEuler(const Vector3& rotation) noexcept
{
	Quaternion result;
	FromEuler(rotation, result);
	return result;
}

void Quaternion::FromEuler(const Vector3& rotation, Quaternion& result) noexcept
{
	const float cr = std::cos(rotation.x * 0.5f);
	const float sr = std::sin(rotation.x * 0.5f);
	const float cp = std::cos(rotation.y * 0.5f);
	const float sp = std::sin(rotation.y * 0.5f);
	const float cy = std::cos(rotation.z * 0.5f);
	const float sy = std::sin(rotation.z * 0.5f);

	result.X() = sr * cp * cy - cr * sp * sy;
	result.Y() = cr * sp * cy + sr * cp * sy;
	result.Z() = cr * cp * sy - sr * sp * cy;
	result.W() = cr * cp * cy + sr * sp * sy;
}

Quaternion Quaternion::FromRotationMatrix(const Matrix& rotation) noexcept
{
	Quaternion result;
	FromRotationMatrix(rotation, result);
	return result;
}

void Quaternion::FromRotationMatrix(const Matrix& rotation, Quaternion& result) noexcept
{
	const float trace = rotation.Trace() - rotation[3][3];

	if (trace > 0.f)
	{
		float s = std::sqrt(trace + 1.f);
		result.W() = s * 0.5f;
		s = 0.5f / s;
		result.X() = (rotation[2][1] - rotation[1][2]) * s;
		result.Y() = (rotation[0][2] - rotation[2][0]) * s;
		result.Z() = (rotation[1][0] - rotation[0][1]) * s;
	}
	else
	{
		if (rotation[0][0] >= rotation[1][1] && rotation[0][0] >= rotation[2][2])
		{
			const float s = std::sqrt(1.f + rotation[0][0] - rotation[1][1] - rotation[2][2]);
			const float invS = 0.5f / s;
			result.X() = 0.5f * s;
			result.Y() = (rotation[1][0] + rotation[0][1]) * invS;
			result.Z() = (rotation[2][0] + rotation[0][2]) * invS;
			result.W() = (rotation[2][1] - rotation[1][2]) * invS;
		}
		else if (rotation[1][1] > rotation[2][2])
		{
			const float s = std::sqrt(1.f + rotation[1][1] - rotation[0][0] - rotation[2][2]);
			const float invS = 0.5f / s;
			result.X() = (rotation[0][1] + rotation[1][0]) * invS;
			result.Y() = 0.5f * s;
			result.Z() = (rotation[1][2] + rotation[2][1]) * invS;
			result.W() = (rotation[0][2] - rotation[2][0]) * invS;
		}
		else
		{
			const float s = std::sqrt(1.f + rotation[2][2] - rotation[0][0] - rotation[1][1]);
			const float invS = 0.5f / s;
			result.X() = (rotation[0][2] + rotation[2][0]) * invS;
			result.Y() = (rotation[1][2] + rotation[2][1]) * invS;
			result.Z() = 0.5f * s;
			result.W() = (rotation[1][0] - rotation[0][1]) * invS;
		}
	}
}

Quaternion Quaternion::Lerp(const Quaternion& a, const Quaternion& b, const float t) noexcept
{
	Quaternion result;
	Lerp(a, b, t, result);
	return result;
}

void Quaternion::Lerp(const Quaternion& a, const Quaternion& b, float t, Quaternion& result) noexcept
{
	const float t1 = 1.f - t;

	const float dot = Dot(a, b);

	if (dot >= 0.f)
	{
		result.X() = t1 * a.X() + t * b.X();
		result.Y() = t1 * a.Y() + t * b.Y();
		result.Z() = t1 * a.Z() + t * b.Z();
		result.W() = t1 * a.W() + t * b.W();
	}
	else
	{
		result.X() = t1 * a.X() - t * b.X();
		result.Y() = t1 * a.Y() - t * b.Y();
		result.Z() = t1 * a.Z() - t * b.Z();
		result.W() = t1 * a.W() - t * b.W();
	}

	// Normalize it.
	const float ls = result.X() * result.X() + result.Y() * result.Y() + result.Z() * result.Z() + result.W() * result.W();
	const float invNorm = 1.f / std::sqrt(ls);

	result.X() *= invNorm;
	result.Y() *= invNorm;
	result.Z() *= invNorm;
	result.W() *= invNorm;
}

Quaternion Quaternion::Slerp(const Quaternion& a, const Quaternion& b, const float t) noexcept
{
	Quaternion result;
	Slerp(a, b, t, result);
	return result;
}

void Quaternion::Slerp(const Quaternion& a, const Quaternion& b, float t, Quaternion& result) noexcept
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

	result.X() = s1 * a.X() + s2 * b.X();
	result.Y() = s1 * a.Y() + s2 * b.Y();
	result.Z() = s1 * a.Z() + s2 * b.Z();
	result.W() = s1 * a.W() + s2 * b.W();
}

bool operator==(const Quaternion a, const Quaternion b)
{
	return calc::Equals(a.imaginary.x, b.imaginary.x)
		&& calc::Equals(a.imaginary.y, b.imaginary.y)
		&& calc::Equals(a.imaginary.z, b.imaginary.z)
		&& calc::Equals(a.real, b.real);
}

bool operator!=(const Quaternion a, const Quaternion b)
{
	return !(a == b);
}

std::ostream& operator<<(std::ostream& out, const Quaternion& q)
{
	return out << std::format("{{{:.3f} {:.3f} {:.3f} {:.3f}}}", q.imaginary.x, q.imaginary.y, q.imaginary.z, q.real);
}
