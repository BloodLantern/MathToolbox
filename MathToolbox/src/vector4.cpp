#include "vector4.hpp"

#include <cassert>
#include <format>

#include "calc.hpp"
#include "matrix.hpp"
#include "vector2.hpp"
#include "vector3.hpp"

float Vector4::Length() const noexcept
{
	return std::sqrt(SquaredLength());
}

Vector4 Vector4::Normalized() const noexcept
{
	const float length = Length();
	if (Calc::IsZero(length))
		return Zero();

	__assume(length != 0.f);
	const float invLength = 1.f / length;
	return Vector4(x * invLength, y * invLength, z * invLength, w * invLength);
}

void Vector4::Normalized(Vector4& result) const noexcept
{
	const float length = Length();
	if (Calc::IsZero(length))
	{
		result = Zero();
		return;
	}

	__assume(length != 0.f);
	const float invLength = 1.f / length;
	result = Vector4(x * invLength, y * invLength, z * invLength, w * invLength);
}

Vector4::operator Vector2() const noexcept
{
	return Vector2(x, y);
}

Vector4::operator Vector3() const noexcept
{
	return Vector3(x, y, z);
}

Vector4::operator Matrix() const noexcept
{
	return Matrix(
		x, 0, 0, 0,
		y, 1, 0, 0,
		z, 0, 1, 0,
        w, 0, 0, 1
	);
}

std::ostream& operator<<(std::ostream& out, const Vector4& v) noexcept
{
	return out << std::format("{{{:.3f} {:.3f} {:.3f} {:.3f}}}", v.x, v.y, v.z, v.w);
}
