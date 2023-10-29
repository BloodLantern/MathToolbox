#include "calc.hpp"

#include "vector2.hpp"
#include "vector3.hpp"

constexpr char calc::Sign(const float value)
{
    // std::signbit returns whether the value is negative
    return std::signbit(value) ? -1 : 1;
}

void calc::Approach(float &value, const float target, const float step)
{
    const float difference = target - value;

    // If the target value hasn't been reached yet
    if (std::abs(difference) > 0)
    {
        value += std::min(step, std::abs(difference)) * Sign(difference);
    }
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
    return value <= Zero;
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
