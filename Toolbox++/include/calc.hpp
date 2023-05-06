#pragma once

#include <cmath>
#include <algorithm>

namespace calc
{
    /// @brief The Earth gravitational constant
    constexpr float Gravity = 9.80665f;

    /// @brief Returns -1 if x is less than 0, 1 if x is greater than 0
    ///        and 0 if x is equal to 0.
    [[nodiscard]] extern constexpr char Sign(const float value);

    /// @brief Approaches the target value by the given step size without ever
    ///        exceeding it.
    /// @param value The value to change.
    /// @param target The target value.
    /// @param step The step size.
    extern void Approach(float& value, const float target, const float step);
}
