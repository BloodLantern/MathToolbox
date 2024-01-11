#include "calc.hpp"

#include <algorithm>

constexpr float calc::Sign(const float value) noexcept
{
    return value < 0.f ? -1.f : 1.f;
}

void calc::Approach(float &value, const float target, const float step) noexcept
{
    // If the target value hasn't been reached yet
    if (!Equals(value, target))
    {
        const float difference = target - value;
        value += std::min(step, std::abs(difference)) * Sign(difference);
    }
}

float calc::YoYo(const float value) noexcept
{
    return value <= 0.5f ? value * 2.f : 1.f - (value - 0.5f) * 2.f;
}

bool calc::IsZero(const float value) noexcept
{
    return std::abs(value) <= Zero;
}

bool calc::Equals(const float a, const float b) noexcept
{
    return IsZero(a - b);
}

bool calc::Nullify(float &value) noexcept
{
    const bool zero = IsZero(value);

    if (zero)
        value = 0.f;

    return zero;
}

void calc::UpdateCooldown(float& cooldown, const float deltaTime) noexcept
{
    if (cooldown > 0.f)
        cooldown -= deltaTime;
}

float calc::FastInverseSqrt(const float number, const bool precise) noexcept
{
    constexpr float threehalfs = 1.5f;

    const float x2 = number * 0.5f;
    float y = number;
    	
    long i = *(long*) &y;
    i = 0x5F3759DF - (i >> 1);
    y = *(float*) &i;
    	
    y = y * (threehalfs - (x2 * y * y)); // 1st iteration
    	
    if (precise)
        y = y * (threehalfs - (x2 * y * y)); // 2nd iteration, optional

    return y;
}
