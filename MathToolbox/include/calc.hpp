#pragma once

#include <algorithm>
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
    /// The value under which a number is considered to be zero.
	/// </summary>
	constexpr float Zero = ZERO;
	
	/// <summary>
	///	Shorthand for writing <code>std::numbers::pi_v<float></code>.
	/// </summary>
	constexpr float Pi = std::numbers::pi_v<float>;
	
	/// <summary>
	///	Shorthand for writing <code>calc::Pi / 2.f</code>.
	/// </summary>
	constexpr float PiOver2 = Pi / 2.f;
	
	/// <summary>
	///	Shorthand for writing <code>calc::Pi / 2.f</code>.
	/// </summary>
	constexpr float PiOver4 = Pi / 4.f;
	
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
	extern constexpr float Sign(float number) noexcept;

	/// <summary>
	///	A constexpr version of the <code>std::abs</code> function.
	/// </summary>
	[[nodiscard]]
	extern constexpr float Abs(float number) noexcept;

	/// <summary>
	/// Approaches the target value by the given step size without ever
	/// exceeding it.
	/// </summary>
	/// <param name="value">The value to change.</param>
	/// <param name="target">The target value.</param>
	/// <param name="step">The step size.</param>
	extern constexpr void Approach(float& value, float target, float step) noexcept;

	/// <summary>
	/// Given a value between 0 and 1, returns a value going from 0 to 1
	/// and to 0 again.
	/// </summary>
	/// <param name="value"></param>
	/// <returns>A value between 0 and 1, closer to 1 if the input value is close to 0.5.</returns>
	[[nodiscard]]
	extern constexpr float YoYo(float value) noexcept;

	/// <summary>
	/// Checks if a value is less than what is considered to be zero, e.g. if its absolute
	/// value is smaller than <code>calc::Zero</code>.
	/// </summary>
	/// <param name="value">The value to check.</param>
	/// <returns>Whether the value is considered to be zero.</returns>
	[[nodiscard]]
	extern constexpr bool IsZero(float value) noexcept;

	/// <summary>
	/// Checks if a value is less than what is considered to be zero, e.g. if its absolute
	/// value is smaller than <code>calc::Zero</code>.
	/// </summary>
	/// <param name="value">The value to check.</param>
	/// <param name="zero">The value under which a number is considered to be zero.</param>
	/// <returns>Whether the value is considered to be zero.</returns>
	[[nodiscard]]
	extern constexpr bool IsZero(float value, float zero) noexcept;

	/// <summary>
	/// Checks if two values are considered equal.
	/// </summary>
	/// <param name="a">The first value.</param>
	/// <param name="b">The second value.</param>
	/// <returns>Whether the values are considered equal.</returns>
	[[nodiscard]]
	extern constexpr bool Equals(float a, float b) noexcept;

    /// <summary>
    /// Checks if a value is less than what is considered zero and sets it if true.
    /// </summary>
    /// <param name="value">The value to check and set.</param>
    /// <returns>Whether the value is considered zero and the operation was made.</returns>
    extern constexpr bool Nullify(float& value) noexcept;

    /// <summary>
	/// Updates a cooldown timer.
    /// </summary>
    /// <param name="cooldown">The variable to update.</param>
    /// <param name="deltaTime">The delta time to subtract to 'cooldown'.</param>
    extern constexpr void UpdateCooldown(float& cooldown, float deltaTime) noexcept;
}

constexpr float calc::Sign(const float number) noexcept
{
	return number < 0.f ? -1.f : 1.f;
}

constexpr float calc::Abs(const float number) noexcept
{
	return number < 0.f ? -number : number;
}

constexpr void calc::Approach(float &value, const float target, const float step) noexcept
{
	// If the target value hasn't been reached yet
	if (!Equals(value, target))
	{
		const float difference = target - value;
		value += std::min(step, Abs(difference)) * Sign(difference);
	}
}

constexpr float calc::YoYo(const float value) noexcept
{
	return value <= 0.5f ? value * 2.f : 1.f - (value - 0.5f) * 2.f;
}

constexpr bool calc::IsZero(const float value) noexcept
{
	return IsZero(value, Zero);
}

constexpr bool calc::IsZero(const float value, const float zero) noexcept
{
	return Abs(value) <= zero;
}

constexpr bool calc::Equals(const float a, const float b) noexcept
{
	return IsZero(a - b);
}

constexpr bool calc::Nullify(float &value) noexcept
{
	const bool zero = IsZero(value);

	if (zero)
		value = 0.f;

	return zero;
}

constexpr void calc::UpdateCooldown(float& cooldown, const float deltaTime) noexcept
{
	if (cooldown > 0.f)
		cooldown -= deltaTime;
}

#undef ZERO
