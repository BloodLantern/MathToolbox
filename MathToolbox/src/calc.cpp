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
