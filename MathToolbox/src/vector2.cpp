#include "vector2.hpp"

#include <format>

#include "vector2i.hpp"
#include "vector3.hpp"
#include "vector4.hpp"

float_t Vector2::Length() const noexcept
{
	return std::sqrt(SquaredLength());
}

Vector2 Vector2::Normalized() const noexcept
{
	const float_t length = Length();
	if (Calc::IsZero(length))
		return Zero();

    __assume(length != 0.f);
	const float_t invLength = 1.f / length;
	return Vector2(x * invLength, y * invLength);
}

Vector2 Vector2::Normal() const noexcept
{
	return Vector2(y, -x).Normalized();
}

bool Vector2::IsInfinity() const noexcept
{
	return std::isinf(x)
		&& std::isinf(y);
}

bool Vector2::IsNaN() const noexcept
{
	return std::isnan(x)
		&& std::isnan(y);
}

Vector2::operator Vector2i() const noexcept
{
	return Vector2i(static_cast<int32_t>(std::round(x)), static_cast<int32_t>(std::round(y)));
}

Vector2::operator Vector3() const noexcept
{
	return Vector3(x, y, 0.f);
}

Vector2::operator Vector4() const noexcept
{
	return Vector4(x, y, 0.f, 1.f);
}

std::ostream& operator<<(std::ostream& out, const Vector2 v) noexcept
{
	return out << std::format("{{{:.3f} {:.3f}}}", v.x, v.y);
}
