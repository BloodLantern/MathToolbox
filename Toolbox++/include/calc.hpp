#pragma once

#include <cmath>
#include <algorithm>

namespace calc
{
    /// @brief The Earth gravitational constant
    constexpr float Gravity = 9.80665f;

    [[nodiscard]] constexpr char Sign(const float value);

    static void Approach(float& value, const float target, const float step);
}
