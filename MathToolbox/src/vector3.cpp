#include "vector3.hpp"

#include <cassert>

#include "calc.hpp"
#include "matrix.hpp"
#include "vector2.hpp"
#include "vector4.hpp"

float Vector3::Length() const noexcept
{
	return std::sqrt(SquaredLength());
}

Vector3 Vector3::Normalized() const noexcept
{
	const float length = Length();
	if (calc::IsZero(length))
		return Zero();

	__assume(length != 0.f);
	const float invLength = 1.f / length;
	return Vector3(x * invLength, y * invLength, z * invLength);
}

void Vector3::Normalized(Vector3& result) const noexcept
{
	const float length = Length();
	if (calc::IsZero(length))
	{
		result = Zero();
		return;
	}

	__assume(length != 0.f);
	const float invLength = 1.f / length;
	result = Vector3(x * invLength, y * invLength, z * invLength);
}

Vector3::operator Vector2() const noexcept
{
	return Vector2(x, y);
}

Vector3::operator Vector4() const noexcept
{
	return Vector4(x, y, z, 1.f);
}

std::ostream& operator<<(std::ostream& out, const Vector3& v) noexcept
{
	return out << std::format("{{{:.3f} {:.3f} {:.3f}}}", v.x, v.y, v.z);
}
