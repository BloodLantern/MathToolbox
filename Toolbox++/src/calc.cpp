#include "calc.hpp"

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
