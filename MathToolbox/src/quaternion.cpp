#include "quaternion.hpp"

#include "calc.hpp"
#include "matrix.hpp"

float Quaternion::Length() const noexcept
{
	return std::sqrt(SquaredLength());
}

Quaternion Quaternion::FromAxisAngle(const Vector3& axis, const float angle) noexcept
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

Quaternion Quaternion::FromEuler(const Vector3& rotation) noexcept
{
	const float cr = std::cos(rotation.x * 0.5f);
	const float sr = std::sin(rotation.x * 0.5f);
	const float cp = std::cos(rotation.y * 0.5f);
	const float sp = std::sin(rotation.y * 0.5f);
	const float cy = std::cos(rotation.z * 0.5f);
	const float sy = std::sin(rotation.z * 0.5f);

	Quaternion quat;
	
	quat.X() = sr * cp * cy - cr * sp * sy;
	quat.Y() = cr * sp * cy + sr * cp * sy;
	quat.Z() = cr * cp * sy - sr * sp * cy;
	quat.W() = cr * cp * cy + sr * sp * sy;
	
	return quat;
}

Quaternion Quaternion::FromRotationMatrix(const Matrix& rotation) noexcept
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

Quaternion Quaternion::Lerp(const Quaternion& a, const Quaternion& b, const float t) noexcept
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

Quaternion Quaternion::Slerp(const Quaternion& a, const Quaternion& b, const float t) noexcept
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
