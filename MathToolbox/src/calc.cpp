#include "calc.hpp"

#include "vector2.hpp"
#include "vector3.hpp"

constexpr float calc::Sign(const float value)
{
    return value < 0.f ? -1.f : 1.f;
}

void calc::Approach(float &value, const float target, const float step)
{
    const float difference = target - value;

    // If the target value hasn't been reached yet
    if (std::abs(difference) > 0)
        value += std::min(step, std::abs(difference)) * Sign(difference);
}

float calc::YoYo(const float value)
{
    return value <= 0.5f ? value * 2.f : 1.f - (value - 0.5f) * 2.f;
}

Vector2 calc::Lerp(const Vector2 &value, const Vector2 &target, const float t)
{
    return value + (target - value) * t;
}

Vector3 calc::Lerp(const Vector3 &value, const Vector3 &target, const float t)
{
    return value + (target - value) * t;
}

bool calc::IsZero(const float value)
{
    return std::abs(value) <= Zero;
}

bool calc::Equals(const float a, const float b)
{
    return IsZero(a - b);
}

bool calc::Nullify(float &value)
{
    const bool zero = IsZero(value);

    if (zero)
        value = 0;

    return zero;
}

void calc::UpdateCooldown(float& cooldown, const float deltaTime)
{
    if (cooldown > 0.f)
        cooldown -= deltaTime;
}

Vector2 calc::Round(const Vector2& value)
{
    return Vector2(std::roundf(value.x), std::roundf(value.y));
}

Vector3 calc::Round(const Vector3& value)
{
	return Vector3(std::roundf(value.x), std::roundf(value.y), std::roundf(value.z));
}
