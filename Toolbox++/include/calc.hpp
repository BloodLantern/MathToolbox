#pragma once

#include <cmath>
#include <algorithm>

class Vector2;
class Vector3;

namespace calc
{
    /// @brief The Earth gravitational constant
    constexpr float Gravity = 9.80665f;
    /// @brief The value under which a number is considered zero
    constexpr float Zero = 1e-6f;

    /// <summary>
    /// Returns -1 if x is less than 0, 1 if x is greater than 0
    /// and 0 if x is equal to 0.
    /// </summary>
    [[nodiscard]]
    __forceinline
    extern constexpr char Sign(const float value);

    /// <summary>
    /// Approaches the target value by the given step size without ever
    /// exceeding it.
    /// </summary>
    /// <param name="value">The value to change.</param>
    /// <param name="target">The target value.</param>
    /// <param name="step">The step size.</param>
    [[nodiscard]]
    extern void Approach(float& value, const float target, const float step);

    /// <summary>
    /// Lerp between two positions in a 2-dimensional space.
    /// </summary>
    /// <param name="value">The current position.</param>
    /// <param name="target">The target position.</param>
    /// <param name="t">The time to lerp.</param>
    /// <returns>The lerped position.</returns>
    [[nodiscard]]
    __forceinline
    extern Vector2 Lerp(const Vector2& value, const Vector2& target, const float t);

    /// <summary>
    /// Lerp between two positions in a 3-dimensional space.
    /// </summary>
    /// <param name="value">The current position.</param>
    /// <param name="target">The target position.</param>
    /// <param name="t">The time to lerp.</param>
    /// <returns>The lerped position.</returns>
    [[nodiscard]]
    __forceinline
    extern Vector3 Lerp(const Vector3& value, const Vector3& target, const float t);

    /// <summary>
    /// Checks if a value is less than what is considered zero.
    /// </summary>
    /// <param name="value">The value to check.</param>
    /// <returns>Whether the value is considered zero.</returns>
    [[nodiscard]]
    __forceinline
    extern bool IsZero(const float value);

    /// <summary>
    /// Checks if a value is less than what is considered zero and sets it if true.
    /// </summary>
    /// <param name="value">The value to check and set.</param>
    /// <returns>Whether the value is considered zero and the operation was made.</returns>
    __forceinline
    extern bool Nullify(float& value);

    /// <summary>
	/// Updates a cooldown timer.
    /// </summary>
    /// <param name="cooldown">The variable to update.</param>
    /// <param name="deltaTime">The delta time to substract to 'cooldown'.</param>
    __forceinline
    extern void UpdateCooldown(float& cooldown, const float deltaTime);
}
