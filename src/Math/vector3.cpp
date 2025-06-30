#include "Math/vector3.hpp"

#include <cassert>
#include <format>

#include "Math/calc.hpp"
#include "Math/matrix.hpp"
#include "Math/vector2.hpp"
#include "Math/vector4.hpp"

float_t Vector3::Length() const noexcept
{
	return std::sqrt(SquaredLength());
}

Vector3::operator Vector4() const noexcept
{
    return {x, y, z, 1.f};
}

Vector3 Vector3::Normalized() const noexcept
{
	const float_t length = Length();
	if (Calc::IsZero(length))
		return Zero();

	ASSUME(length != 0.f);
	const float_t invLength = 1.f / length;
	return {x * invLength, y * invLength, z * invLength};
}

void Vector3::Normalized(Vector3* result) const noexcept
{
	const float_t length = Length();
	if (Calc::IsZero(length))
	{
		*result = Zero();
		return;
	}

	ASSUME(length != 0.f);
	const float_t invLength = 1.f / length;
	*result = Vector3(x * invLength, y * invLength, z * invLength);
}

bool Vector3::IsInfinity() const noexcept
{
	return std::isinf(x)
		&& std::isinf(y)
		&& std::isinf(z);
}

bool Vector3::IsNaN() const noexcept
{
	return std::isnan(x)
		&& std::isnan(y)
		&& std::isnan(z);
}

Vector3::operator Vector2() const noexcept
{
	return {x, y};
}

Vector3 Vector3::Rescaled(float_t newLength) const noexcept
{
    return *this * newLength / Length();
}

std::ostream& operator<<(std::ostream& out, const Vector3& v) noexcept
{
	return out << std::format("{{{:.3f} {:.3f} {:.3f}}}", v.x, v.y, v.z);
}
