module Math:Vector4;

import std;
import :Types;
import :Vector2;
import :Vector3;
import :Matrix;
import :Calc;

float_t Vector4::Length() const noexcept
{
	return std::sqrt(SquaredLength());
}

Vector4 Vector4::Normalized() const noexcept
{
	const float_t length = Length();
	if (Calc::IsZero(length))
		return Zero();

	const float_t invLength = 1.f / length;
	return Vector4(x * invLength, y * invLength, z * invLength, w * invLength);
}

void Vector4::Normalized(Vector4* result) const noexcept
{
	const float_t length = Length();
	if (Calc::IsZero(length))
	{
		*result = Zero();
		return;
	}

	const float_t invLength = 1.f / length;
	*result = Vector4(x * invLength, y * invLength, z * invLength, w * invLength);
}

bool Vector4::IsInfinity() const noexcept
{
	return std::isinf(x)
		&& std::isinf(y)
		&& std::isinf(z)
		&& std::isinf(w);
}

bool Vector4::IsNaN() const noexcept
{
	return std::isnan(x)
		&& std::isnan(y)
		&& std::isnan(z)
		&& std::isnan(w);
}

Vector4::operator Vector2() const noexcept
{
	return Vector2(x, y);
}

Vector4::operator Vector3() const noexcept
{
	return Vector3(x, y, z);
}

std::ostream& operator<<(std::ostream& out, const Vector4& v) noexcept
{
	return out << std::format("{{{:.3f} {:.3f} {:.3f} {:.3f}}}", v.x, v.y, v.z, v.w);
}
