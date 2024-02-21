#pragma once

#ifdef MATH_DEFINE_FORMATTER
#include <format>
#include <sstream>
#endif

#include <stdexcept>

#include "calc.hpp"

class Vector2i;
class Vector3;
class Vector4;

/// <summary>
/// The Vector2 class represents either a two-dimensional vector or a point.
/// </summary>
class MATH_TOOLBOX Vector2
{
public:
	float x = 0.f, y = 0.f;

	/// <summary>
	///	Equivalent to calling the default constructor.
	/// </summary>
	[[nodiscard]]
	static constexpr Vector2 Zero() noexcept;

	[[nodiscard]]
	static constexpr Vector2 UnitX() noexcept;

	[[nodiscard]]
	static constexpr Vector2 UnitY() noexcept;

	/// <summary>
	/// Returns a · b.
	/// </summary>
	[[nodiscard]]
	static constexpr float Dot(Vector2 a, Vector2 b) noexcept;

	/// <summary>
	/// Returns a x b.
	/// For a Vector2, this is simply the determinant.
	/// </summary>
	[[nodiscard]]
	static constexpr float Cross(Vector2 a, Vector2 b) noexcept;

	/// <summary>
	/// Returns the determinant of 'a' and 'b'.
	/// </summary>
	[[nodiscard]]
	static constexpr float Determinant(Vector2 a, Vector2 b) noexcept;

	/// <summary>
	/// Lerp between two positions in a 2-dimensional space.
	/// </summary>
	/// <param name="value">The current position.</param>
	/// <param name="target">The target position.</param>
	/// <param name="t">The time to lerp.</param>
	/// <returns>The lerp position.</returns>
	[[nodiscard]]
	static constexpr Vector2 Lerp(Vector2 value, Vector2 target, float t) noexcept;

	/// <summary>
	/// Constructs a Vector2 with both its components set to 0.
	/// </summary>
	constexpr Vector2() = default;
	
	/// <summary>
	/// Constructs a Vector2 with both its components set to 'xy'.
	/// </summary>
	/// <param name="xy">The value to set this vector's x and y components to.</param>
	constexpr explicit Vector2(float xy) noexcept;
	
	/// <summary>
	/// Constructs a Vector2 with its components set to the data pointed by <code>data</code>.
	/// This constructor assumes that <code>data</code> is a valid pointer pointing to at least 2 float values.
	/// </summary>
	/// <param name="data">The data where the values for this vector's components are located.</param>
	constexpr explicit Vector2(const float* data) noexcept;

	/// <summary>
	/// Constructs a Vector2 with set component values.
	/// </summary>
	/// <param name="x">The value to set this vector's x components to.</param>
	/// <param name="y">The value to set this vector's y components to.</param>
	constexpr Vector2(float x, float y) noexcept;

	/// <summary>
	///	Gets a pointer to the first component of this vector.
	/// </summary>
	/// <returns>A pointer to the first component of this vector.</returns>
	[[nodiscard]]
	constexpr const float* Raw() const noexcept;

	/// <summary>
	///	Gets a pointer to the first component of this vector.
	/// </summary>
	/// <returns>A pointer to the first component of this vector.</returns>
	[[nodiscard]]
	constexpr float* Raw() noexcept;

	/// <summary>
	/// Returns the length of the vector.
	/// </summary>
	[[nodiscard]]
	float Length() const noexcept;
	
	/// <summary>
	/// Returns the squared length of the vector.
	/// </summary>
	[[nodiscard]]
	constexpr float SquaredLength() const noexcept;

	/// <summary>
	/// Returns a normalized vector.
	/// </summary>
	/// <returns>A vector with the same direction but a length of one.</returns>
	[[nodiscard]]
	Vector2 Normalized() const noexcept;
	
	/// <summary>
	/// Returns the normal vector to this one.
	/// </summary>
	/// <returns>A vector with the same length but a normal direction.</returns>
	[[nodiscard]]
	Vector2 Normal() const noexcept;

	/// <summary>
	///	Check whether all of this vector's components are infinite.
	/// </summary>
	[[nodiscard]]
	bool IsInfinity() const noexcept;

	/// <summary>
	///	Check whether all of this vector's components are NaN.
	/// </summary>
	[[nodiscard]]
	bool IsNaN() const noexcept;

	/// <summary>
	///	Retrieves this vector's component at index i.
	/// </summary>
	/// <param name="i">
	/// The index of the component to get. It would be 0
	/// for x, 1 for y, etc...
	/// </param>
	/// <returns>The value of the component at index i.</returns>
	[[nodiscard]]
	constexpr float operator[](size_t i) const;

	/// <summary>
	///	Retrieves this vector's component at index i.
	/// </summary>
	/// <param name="i">
	/// The index of the component to get. It would be 0
	/// for x, 1 for y, etc...
	/// </param>
	/// <returns>The value of the component at index i.</returns>
	[[nodiscard]]
	constexpr float& operator[](size_t i);

	explicit operator Vector2i() const noexcept;
	
	explicit operator Vector3() const noexcept;
	
	explicit operator Vector4() const noexcept;
};

static_assert(std::is_default_constructible_v<Vector2>, "Class Vector2 must be default constructible.");
static_assert(std::is_copy_constructible_v<Vector2>, "Class Vector2 must be copy constructible.");
static_assert(std::is_move_constructible_v<Vector2>, "Class Vector2 must be move constructible.");
static_assert(std::is_copy_assignable_v<Vector2>, "Class Vector2 must be copy assignable.");
static_assert(std::is_move_assignable_v<Vector2>, "Class Vector2 must be move assignable.");

constexpr Vector2::Vector2(const float xy) noexcept : x(xy), y(xy) {}

constexpr Vector2::Vector2(const float* const data) noexcept : x(data[0]), y(data[1]) {}

constexpr Vector2::Vector2(const float x, const float y) noexcept : x(x), y(y) {}

constexpr Vector2 Vector2::Zero() noexcept { return Vector2(); }

constexpr Vector2 Vector2::UnitX() noexcept { return Vector2(1.f, 0.f); }

constexpr Vector2 Vector2::UnitY() noexcept { return Vector2(0.f, 1.f); }

constexpr float Vector2::Dot(const Vector2 a, const Vector2 b) noexcept { return a.x * b.x + a.y * b.y; }

constexpr float Vector2::Cross(const Vector2 a, const Vector2 b) noexcept { return Determinant(a, b); }

constexpr float Vector2::Determinant(const Vector2 a, const Vector2 b) noexcept { return a.x * b.y - b.x * a.y; }

constexpr const float* Vector2::Raw() const noexcept { return& x; }

constexpr float* Vector2::Raw() noexcept { return& x; }

constexpr float Vector2::SquaredLength() const noexcept { return SQ(x) + SQ(y); }

constexpr float Vector2::operator[](const size_t i) const
{
	if (i < 2) [[likely]]
		return *(Raw() + i);
	[[unlikely]]
		throw std::out_of_range("Vector2 subscript out of range");
}

constexpr float& Vector2::operator[](const size_t i)
{
	if (i < 2) [[likely]]
		return *(Raw() + i);
	[[unlikely]]
		throw std::out_of_range("Vector2 subscript out of range");
}

[[nodiscard]]
constexpr Vector2 operator+(const Vector2 a, const Vector2 b) noexcept { return Vector2(a.x + b.x, a.y + b.y); }

[[nodiscard]]
constexpr Vector2 operator-(const Vector2 a) noexcept { return Vector2(-a.x, -a.y); }

[[nodiscard]]
constexpr Vector2 operator-(const Vector2 a, const Vector2 b) noexcept { return a + -b; }

[[nodiscard]]
constexpr Vector2 operator*(const Vector2 a, const Vector2 b) noexcept { return Vector2(a.x * b.x, a.y * b.y); }

[[nodiscard]]
constexpr Vector2 operator*(const Vector2 v, const float factor) noexcept { return Vector2(v.x * factor, v.y * factor); }

[[nodiscard]]
constexpr Vector2 operator*(const float factor, const Vector2 v) noexcept { return v * factor; }

[[nodiscard]]
constexpr Vector2 operator/(const Vector2 a, const Vector2 b) noexcept { return Vector2(a.x / b.x, a.y / b.y); }

[[nodiscard]]
constexpr Vector2 operator/(const Vector2 v, const float factor) noexcept { const float invFactor = 1.f / factor; return Vector2(v.x * invFactor, v.y * invFactor); }

constexpr Vector2& operator+=(Vector2& a, const Vector2 b) noexcept { return a = a + b; }

constexpr Vector2& operator-=(Vector2& a, const Vector2 b) noexcept { return a = a - b; }

constexpr Vector2& operator*=(Vector2& a, const Vector2 b) noexcept { return a = a * b; }

constexpr Vector2& operator*=(Vector2& v, const float factor) noexcept { return v = v * factor; }

constexpr Vector2& operator*=(const float factor, Vector2& v) noexcept { return v = v * factor; }

constexpr Vector2& operator/=(Vector2& a, const Vector2 b) noexcept { return a = a / b; }

constexpr Vector2& operator/=(Vector2& v, const float factor) noexcept { return v = v / factor; }

/// <summary>
///	Checks if two Vector2 are considered equal using <see cref="Calc::Equals"/>.
/// </summary>
[[nodiscard]]
constexpr bool operator==(const Vector2 a, const Vector2 b) noexcept
{
	return Calc::Equals(a.x, b.x)
		&& Calc::Equals(a.y, b.y);
}

/// <summary>
///	Checks if two Vector2 are considered different using <see cref="Calc::Equals"/>.
/// </summary>
[[nodiscard]]
constexpr bool operator!=(const Vector2 a, const Vector2 b) noexcept { return !(a == b); }

std::ostream& operator<<(std::ostream& out, Vector2 v) noexcept;

constexpr Vector2 Vector2::Lerp(const Vector2 value, const Vector2 target, const float t) noexcept { return value + (target - value) * t; }

#ifdef MATH_DEFINE_FORMATTER
template<>
struct std::formatter<Vector2>
{
	template<class ParseContext>
	constexpr typename ParseContext::iterator parse(ParseContext& ctx);

	template<class FmtContext>
	typename FmtContext::iterator format(Vector2 v, FmtContext& ctx) const;
    
private:
    std::string m_Format;
};

template<class ParseContext>
constexpr typename ParseContext::iterator std::formatter<Vector2, char>::parse(ParseContext& ctx)
{
	auto it = ctx.begin();
	if (it == ctx.end())
		return it;

    while (*it != '}' && it != ctx.end())
        m_Format += *it++;
    
	return it;
}

template<class FmtContext>
typename FmtContext::iterator std::formatter<Vector2>::format(Vector2 v, FmtContext& ctx) const
{
    std::ostringstream out;

    out << std::vformat("{:" + m_Format + "} ; {:" + m_Format + '}', std::make_format_args(v.x, v.y));

    return std::ranges::copy(std::move(out).str(), ctx.out()).out;
}
#endif

using vec2 = Vector2;
