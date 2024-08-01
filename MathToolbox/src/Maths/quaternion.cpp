#include "Maths/quaternion.hpp"

#include <format>

#include "Maths/calc.hpp"
#include "Maths/matrix.hpp"

Quaternion Quaternion::FromAxisAngle(const Vector3& axis, const float_t angle) noexcept
{
	Quaternion result;
	FromAxisAngle(axis, angle, &result);
	return result;
}

void Quaternion::FromAxisAngle(const Vector3& axis, const float_t angle, Quaternion* result) noexcept
{
	const Vector3 normalizedAxis = axis.Normalized();
	const float_t halfAngle = angle * 0.5f;
	const float_t s = std::sin(halfAngle);
	const float_t c = std::cos(halfAngle);

	result->X() = normalizedAxis.x * s;
	result->Y() = normalizedAxis.y * s;
	result->Z() = normalizedAxis.z * s;
	result->W() = c;
}

Quaternion Quaternion::FromEuler(const Vector3& rotation) noexcept
{
	Quaternion result;
	FromEuler(rotation, &result);
	return result;
}

void Quaternion::FromEuler(const Vector3& rotation, Quaternion* result) noexcept
{
	const float_t cr = std::cos(rotation.x * 0.5f);
	const float_t sr = std::sin(rotation.x * 0.5f);
	const float_t cp = std::cos(rotation.y * 0.5f);
	const float_t sp = std::sin(rotation.y * 0.5f);
	const float_t cy = std::cos(rotation.z * 0.5f);
	const float_t sy = std::sin(rotation.z * 0.5f);

	result->X() = sr * cp * cy - cr * sp * sy;
	result->Y() = cr * sp * cy + sr * cp * sy;
	result->Z() = cr * cp * sy - sr * sp * cy;
	result->W() = cr * cp * cy + sr * sp * sy;
}

Quaternion Quaternion::FromRotationMatrix(const Matrix& rotation) noexcept
{
	Quaternion result;
	FromRotationMatrix(rotation, &result);
	return result;
}

void Quaternion::FromRotationMatrix(const Matrix& rotation, Quaternion* result) noexcept
{
	const float_t trace = rotation.Trace() - rotation.m33;

	if (trace > 0.f)
	{
		float_t s = std::sqrt(trace + 1.f);
		result->W() = s * 0.5f;
		s = 0.5f / s;
		result->imaginary = Vector3(
			(rotation.m21 - rotation.m12) * s,
			(rotation.m02 - rotation.m20) * s,
			(rotation.m10 - rotation.m01) * s
		);
	}
	else
	{
		if (rotation.m00 >= rotation.m11 && rotation.m00 >= rotation.m22)
		{
			const float_t s = std::sqrt(1.f + rotation.m00 - rotation.m11 - rotation.m22);
			const float_t invS = 0.5f / s;
			*result = Quaternion(
				0.5f * s,
				(rotation.m10 + rotation.m01) * invS,
				(rotation.m20 + rotation.m02) * invS,
				(rotation.m21 - rotation.m12) * invS
			);
		}
		else if (rotation.m11 > rotation.m22)
		{
			const float_t s = std::sqrt(1.f + rotation.m11 - rotation.m00 - rotation.m22);
			const float_t invS = 0.5f / s;
			*result = Quaternion(
				(rotation.m01 + rotation.m10) * invS,
				0.5f * s,
				(rotation.m12 + rotation.m21) * invS,
				(rotation.m02 - rotation.m20) * invS
			);
		}
		else
		{
			const float_t s = std::sqrt(1.f + rotation.m22 - rotation.m00 - rotation.m11);
			const float_t invS = 0.5f / s;
			*result = Quaternion(
				(rotation.m02 + rotation.m20) * invS,
				(rotation.m12 + rotation.m21) * invS,
				0.5f * s,
				(rotation.m10 - rotation.m01) * invS
			);
		}
	}
}

Vector3 Quaternion::ToEuler(const Quaternion& rotation) noexcept
{
	Vector3 result;
	ToEuler(rotation, &result);
	return result;
}

void Quaternion::ToEuler(const Quaternion& rotation, Vector3* result) noexcept
{
	// Code from https://en.wikipedia.org/wiki/Conversion_between_quaternions_and_Euler_angles#Source_code_2
	
	// roll (x-axis rotation)
	const float_t sinrCosp = 2.f * (rotation.W() * rotation.X() + rotation.Y() * rotation.Z());
	const float_t cosrCosp = 1.f - 2.f * (rotation.X() * rotation.X() + rotation.Y() * rotation.Y());
	result->x = std::atan2(sinrCosp, cosrCosp);

	// pitch (y-axis rotation)
	const float_t sinp = std::sqrt(1.f + 2.f * (rotation.W() * rotation.Y() - rotation.X() * rotation.Z()));
	const float_t cosp = std::sqrt(1.f - 2.f * (rotation.W() * rotation.Y() - rotation.X() * rotation.Z()));
	result->y = 2.f * std::atan2(sinp, cosp) - Calc::PiOver2;

	// yaw (z-axis rotation)
	const float_t sinyCosp = 2.f * (rotation.W() * rotation.Z() + rotation.X() * rotation.Y());
	const float_t cosyCosp = 1.f - 2.f * (rotation.Y() * rotation.Y() + rotation.Z() * rotation.Z());
	result->z = std::atan2(sinyCosp, cosyCosp);
}

Quaternion Quaternion::Lerp(const Quaternion& value, const Quaternion& target, const float_t t) noexcept
{
	Quaternion result;
	Lerp(value, target, t, &result);
	return result;
}

void Quaternion::Lerp(const Quaternion& value, const Quaternion& target, const float_t t, Quaternion* result) noexcept
{
	const float_t t1 = 1.f - t;

	const float_t dot = Dot(value, target);

	if (dot >= 0.f)
	{
		result->X() = t1 * value.X() + t * target.X();
		result->Y() = t1 * value.Y() + t * target.Y();
		result->Z() = t1 * value.Z() + t * target.Z();
		result->W() = t1 * value.W() + t * target.W();
	}
	else
	{
		result->X() = t1 * value.X() - t * target.X();
		result->Y() = t1 * value.Y() - t * target.Y();
		result->Z() = t1 * value.Z() - t * target.Z();
		result->W() = t1 * value.W() - t * target.W();
	}

	// Normalize it.
	const float_t ls = result->X() * result->X() + result->Y() * result->Y() + result->Z() * result->Z() + result->W() * result->W();
	const float_t invNorm = 1.f / std::sqrt(ls);

	result->X() *= invNorm;
	result->Y() *= invNorm;
	result->Z() *= invNorm;
	result->W() *= invNorm;
}

Quaternion Quaternion::Slerp(const Quaternion& value, const Quaternion& target, const float_t t) noexcept
{
	Quaternion result;
	Slerp(value, target, t, &result);
	return result;
}

void Quaternion::Slerp(const Quaternion& value, const Quaternion& target, const float_t t, Quaternion* result) noexcept
{
	float_t cosOmega = value.X() * target.X() + value.Y() * target.Y() +
					 value.Z() * target.Z() + value.W() * target.W();

	bool_t flip = false;

	if (cosOmega < 0.f)
	{
		flip = true;
		cosOmega = -cosOmega;
	}

	float_t s1, s2;

	if (cosOmega > 1.f - Calc::Zero)
	{
		// Too close, do straight linear interpolation.
		s1 = 1.f - t;
		s2 = flip ? -t : t;
	}
	else
	{
		const float_t omega = std::acos(cosOmega);
		const float_t invSinOmega = 1.f / std::sin(omega);

		s1 = std::sin((1.f - t) * omega) * invSinOmega;
		s2 = flip
			? -std::sin(t * omega) * invSinOmega
			: std::sin(t * omega) * invSinOmega;
	}

	result->X() = s1 * value.X() + s2 * target.X();
	result->Y() = s1 * value.Y() + s2 * target.Y();
	result->Z() = s1 * value.Z() + s2 * target.Z();
	result->W() = s1 * value.W() + s2 * target.W();
}

Quaternion Quaternion::Normalized() const noexcept
{
	const float_t length = Length();
	return Quaternion(imaginary / length, real / length);
}

void Quaternion::Normalized(Quaternion* result) const noexcept
{
	const float_t length = Length();
	*result = Quaternion(imaginary / length, real / length);
}

float_t Quaternion::Length() const noexcept
{
	return std::sqrt(SquaredLength());
}

bool_t Quaternion::IsInfinity() const noexcept
{
	return imaginary.IsInfinity()
		&& std::isinf(real);
}

bool_t Quaternion::IsNaN() const noexcept
{
	return imaginary.IsNaN()
		&& std::isnan(real);
}

std::ostream& operator<<(std::ostream& out, const Quaternion& q)
{
	return out << std::format("{{{:.3f} {:.3f} {:.3f} {:.3f}}}", q.imaginary.x, q.imaginary.y, q.imaginary.z, q.real);
}
