#include "vector2.hpp"

#include <format>

#include "vector2i.hpp"
#include "vector3.hpp"
#include "vector4.hpp"

float Vector2::Length() const noexcept
{
	return std::sqrt(SquaredLength());
}

Vector2 Vector2::Normalized() const noexcept
{
	const float length = Length();
	if (Calc::IsZero(length))
		return Zero();

    __assume(length != 0.f);
	const float invLength = 1.f / length;
	return Vector2(x * invLength, y * invLength);
}

Vector2 Vector2::Normal() const noexcept
{
	return Vector2(y, -x).Normalized();
}

Vector2::operator Vector2i() const noexcept
{
	return Vector2i(static_cast<int>(std::round(x)), static_cast<int>(std::round(y)));
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
