#pragma once

#include <numbers>

#ifndef ZERO
#define ZERO 1e-6f
#endif

#define SQ(x) ((x) * (x))

class Vector2;
class Vector3;

namespace calc
{
	/// <summary>
    /// The value under which a number is considered zero
	/// </summary>
	constexpr float Zero = ZERO;
	
	/// <summary>
	///	Shorthand for writing <code>std::numbers::pi_v<float></code>.
	/// </summary>
	constexpr float Pi = std::numbers::pi_v<float>;
	
	/// <summary>
	///	Value used to convert from degrees to radians.
	/// </summary>
	constexpr float Deg2Rad = Pi / 180.f;
	
	/// <summary>
	///	Value used to convert from radians to degrees.
	/// </summary>
	constexpr float Rad2Deg = 1.f / Deg2Rad;

    /// <summary>
    /// Returns -1 if x is less than 0, 1 if x is greater than 0
    /// and 0 if x is equal to 0.
    /// </summary>
    /// <returns>-1 if the value is negative, 1 if it is positive. 0 Otherwise.</returns>
    [[nodiscard]]
	extern constexpr float Sign(float value) noexcept;

	/// <summary>
	/// Approaches the target value by the given step size without ever
	/// exceeding it.
	/// </summary>
	/// <param name="value">The value to change.</param>
	/// <param name="target">The target value.</param>
	/// <param name="step">The step size.</param>
	extern void Approach(float& value, float target, float step) noexcept;

	/// <summary>
	/// Given a value between 0 and 1, returns a value going from 0 to 1
	/// and to 0 again.
	/// </summary>
	/// <param name="value"></param>
	/// <returns>A value between 0 and 1, closer to 1 if the input value is close to 0.5.</returns>
	[[nodiscard]]
	extern float YoYo(float value) noexcept;

	/// <summary>
	/// Checks if a value is less than what is considered zero, e.g. if it is smaller
	/// than <code>calc::Zero</code>.
	/// </summary>
	/// <param name="value">The value to check.</param>
	/// <returns>Whether the value is considered zero.</returns>
	[[nodiscard]]
	extern bool IsZero(float value) noexcept;

	/// <summary>
	/// Checks if two values are considered equal.
	/// </summary>
	/// <param name="a">The first value.</param>
	/// <param name="b">The second value.</param>
	/// <returns>Whether the values are considered equal.</returns>
	[[nodiscard]]
	extern bool Equals(float a, float b) noexcept;

    /// <summary>
    /// Checks if a value is less than what is considered zero and sets it if true.
    /// </summary>
    /// <param name="value">The value to check and set.</param>
    /// <returns>Whether the value is considered zero and the operation was made.</returns>
    extern bool Nullify(float& value) noexcept;

    /// <summary>
	/// Updates a cooldown timer.
    /// </summary>
    /// <param name="cooldown">The variable to update.</param>
    /// <param name="deltaTime">The delta time to subtract to 'cooldown'.</param>
    extern void UpdateCooldown(float& cooldown, float deltaTime) noexcept;
}
