#pragma once

#include <algorithm>
#include <numbers>

#include "definitions.hpp"

/// \file calc.hpp
/// <summary>
/// A collection of general-use constants and useful functions.
/// </summary>

#ifndef ZERO
/// <summary>
/// The value to set <see cref="Calc::Zero"/> to. Can be overridden by
/// defining it with a different value before including this file.
/// </summary>
/// <remarks>
///	This macro is undefined at the end of this file. To access this value,
///	the <see cref="Calc::Zero"/> constant should be used instead.
/// </remarks>
#define ZERO 1e-6f
#endif

/// \namespace Calc
/// <summary>
///	This namespace contains mathematical constants and
///	useful functions/macros.
/// </summary>
namespace Calc
{
	/// <summary>
    /// The value under which a number is considered to be zero.
	/// </summary>
	constexpr float Zero = ZERO;
	
	/// <summary>
	///	Shorthand for writing <c>std::numbers::pi_v<float></c>.
	/// </summary>
	constexpr float Pi = std::numbers::pi_v<float>;
	
	/// <summary>
	///	Shorthand for writing <c>Calc::Pi / 2.f</c>.
	/// </summary>
	constexpr float PiOver2 = Pi / 2.f;
	
	/// <summary>
	///	Shorthand for writing <c>Calc::Pi / 2.f</c>.
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
    /// <param name="number">The number to get the sign of.</param>
    /// <returns>-1 if the value is negative, 1 if it is positive. 0 Otherwise.</returns>
    [[nodiscard]]
	MATH_TOOLBOX constexpr float Sign(float number) noexcept;

	/// <summary>
	///	A constexpr version of the <c>std::abs</c> function.
	/// </summary>
	/// <param name="number">The number to get the absolute value of.</param>
	/// <returns>The absolute value of <paramref name="number"/>.</returns>
	[[nodiscard]]
	MATH_TOOLBOX constexpr float Abs(float number) noexcept;

	/// <summary>
	/// Approaches the target value by the given step size without ever
	/// exceeding it.
	/// </summary>
	/// <param name="value">The value to change.</param>
	/// <param name="target">The target value.</param>
	/// <param name="step">The step size.</param>
	MATH_TOOLBOX constexpr void Approach(float& value, float target, float step) noexcept;

	/// <summary>
	/// Given a value between 0 and 1, returns a value going from 0 to 1
	/// and to 0 again.
	/// </summary>
	/// <param name="value"></param>
	/// <returns>A value between 0 and 1, closer to 1 if the input value is close to 0.5.</returns>
	[[nodiscard]]
	MATH_TOOLBOX constexpr float YoYo(float value) noexcept;

	/// <summary>
	///	Returns true on an interval.
	/// </summary>
	/// <param name="value">The current time value.</param>
	/// <param name="lastValue">The last time value. (last call)</param>
	/// <param name="interval">The interval.</param>
	[[nodiscard]]
	MATH_TOOLBOX constexpr bool OnInterval(float value, float lastValue, float interval);

	/// <summary>
	/// Checks if a value is less than what is considered to be zero, e.g. if its absolute
	/// value is smaller than <see cref="Calc::Zero"/>.
	/// </summary>
	/// <param name="value">The value to check.</param>
	/// <returns>Whether the value is considered to be zero.</returns>
	[[nodiscard]]
	MATH_TOOLBOX constexpr bool IsZero(float value) noexcept;

	/// <summary>
	/// Checks if a value is less than what is considered to be zero, e.g. if its absolute
	/// value is smaller than <paramref name="zero"/>.
	/// </summary>
	/// <param name="value">The value to check.</param>
	/// <param name="zero">The value under which a number is considered to be zero.</param>
	/// <returns>Whether the value is considered to be zero.</returns>
	[[nodiscard]]
	MATH_TOOLBOX constexpr bool IsZero(float value, float zero) noexcept;

	/// <summary>
	/// Checks if two values are considered equal using <see cref="IsZero(float)"/>.
	/// </summary>
	/// <param name="a">The first value.</param>
	/// <param name="b">The second value.</param>
	/// <returns>Whether the values are considered equal.</returns>
	[[nodiscard]]
	MATH_TOOLBOX constexpr bool Equals(float a, float b) noexcept;
}

constexpr float Calc::Sign(const float number) noexcept { return number < 0.f ? -1.f : 1.f; }

constexpr float Calc::Abs(const float number) noexcept { return number < 0.f ? -number : number; }

constexpr void Calc::Approach(float &value, const float target, const float step) noexcept
{
	// If the target value hasn't been reached yet
	if (!Equals(value, target))
	{
		const float difference = target - value;
		value += std::min(step, Abs(difference)) * Sign(difference);
	}
}

constexpr float Calc::YoYo(const float value) noexcept { return value <= 0.5f ? value * 2.f : 1.f - (value - 0.5f) * 2.f; }

constexpr bool Calc::OnInterval(float value, float lastValue, float interval) { return (int) (lastValue / interval) != (int) (value / interval); }

constexpr bool Calc::IsZero(const float value) noexcept { return IsZero(value, Zero); }

constexpr bool Calc::IsZero(const float value, const float zero) noexcept { return Abs(value) <= zero; }

constexpr bool Calc::Equals(const float a, const float b) noexcept { return IsZero(a - b); }

#undef ZERO
