#pragma once

#ifdef MATH_DEFINE_FORMATTER
#include <format>
#include <sstream>
#endif

#include "calc.hpp"
#include "vector2.hpp"

class Vector3;
class Vector4;

/// <summary>
/// The Vector2i class represents either a two-dimensional vector or a point.
/// </summary>
class MATH_TOOLBOX Vector2i
{
public:
	int x = 0, y = 0;

	/// <summary>
	///	Equivalent to calling the default constructor.
	/// </summary>
	[[nodiscard]]
	static constexpr Vector2i Zero() noexcept;

	[[nodiscard]]
	static constexpr Vector2i UnitX() noexcept;

	[[nodiscard]]
	static constexpr Vector2i UnitY() noexcept;
	
	/// <summary>
	/// Returns a · b.
	/// </summary>
	[[nodiscard]]
	static constexpr float Dot(Vector2i a, Vector2i b) noexcept;
	
	/// <summary>
	/// Returns a x b.
	/// For a Vector2i this is only the determinant.
	/// </summary>
	[[nodiscard]]
	static constexpr float Cross(Vector2i a, Vector2i b) noexcept;
	
	/// <summary>
	/// Returns the determinant of 'a' and 'b'.
	/// </summary>
	[[nodiscard]]
	static constexpr float Determinant(Vector2i a, Vector2i b) noexcept;

	constexpr Vector2i() = default;

	/// <summary>
	/// Constructs a Vector2i with both its components set to 'xy'.
	/// </summary>
	constexpr explicit Vector2i(int xy);
	
	/// <summary>
	/// Constructs a Vector2i with its components set to the data pointed by <code>data</code>.
	/// This constructor assumes that <code>data</code> is a valid pointer pointing to at least 2 int values.
	/// </summary>
	/// <param name="data">The data where the values for this vector's components are located.</param>
	constexpr explicit Vector2i(const int* data) noexcept;

	constexpr Vector2i(int x, int y);

	/// <summary>
	///	Gets a pointer to the first component of this vector.
	/// </summary>
	/// <returns>A pointer to the first component of this vector.</returns>
	[[nodiscard]]
	constexpr const int* Raw() const noexcept;

	/// <summary>
	///	Gets a pointer to the first component of this vector.
	/// </summary>
	/// <returns>A pointer to the first component of this vector.</returns>
	[[nodiscard]]
	constexpr int* Raw() noexcept;

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
	Vector2 Normalized() const;
	
	/// <summary>
	/// Returns the normal vector to this one.
	/// </summary>
	/// <returns>A vector with the same length but a normal direction.</returns>
	[[nodiscard]]
	Vector2 Normal() const;

	/// <summary>
	///	Retrieves this vector's component at index i.
	/// </summary>
	/// <param name="i">
	/// The index of the component to get. It would be 0
	/// for x, 1 for y, etc...
	/// </param>
	/// <returns>The value of the component at index i.</returns>
	[[nodiscard]]
	constexpr int operator[](size_t i) const;
	
	/// <summary>
	///	Retrieves this vector's component at index i.
	/// </summary>
	/// <param name="i">
	/// The index of the component to get. It would be 0
	/// for x, 1 for y, etc...
	/// </param>
	/// <returns>The value of the component at index i.</returns>
	[[nodiscard]]
	constexpr int& operator[](size_t i);
	
    explicit operator Vector2() const;
	
    explicit operator Vector3() const;
	
    explicit operator Vector4() const;
};

static_assert(std::is_default_constructible_v<Vector2i>, "Class Vector2i must be default constructible.");
static_assert(std::is_copy_constructible_v<Vector2i>, "Class Vector2i must be copy constructible.");
static_assert(std::is_move_constructible_v<Vector2i>, "Class Vector2i must be move constructible.");
static_assert(std::is_copy_assignable_v<Vector2i>, "Class Vector2i must be copy assignable.");
static_assert(std::is_move_assignable_v<Vector2i>, "Class Vector2i must be move assignable.");

constexpr Vector2i::Vector2i(const int xy): x(xy), y(xy) {}

constexpr Vector2i::Vector2i(const int* const data) noexcept : x(data[0]), y(data[1]) {}

constexpr Vector2i::Vector2i(const int x, const int y): x(x), y(y) {}

constexpr Vector2i Vector2i::Zero() noexcept { return Vector2i(); }

constexpr Vector2i Vector2i::UnitX() noexcept { return Vector2i(1, 0); }

constexpr Vector2i Vector2i::UnitY() noexcept { return Vector2i(0, 1); }

constexpr float Vector2i::Dot(const Vector2i a, const Vector2i b) noexcept { return static_cast<float>(a.x * b.x + a.y * b.y); }

constexpr float Vector2i::Cross(const Vector2i a, const Vector2i b) noexcept { return Determinant(a, b); }

constexpr float Vector2i::Determinant(const Vector2i a, const Vector2i b) noexcept { return static_cast<float>(a.x * b.y - b.x * a.y); }

constexpr const int* Vector2i::Raw() const noexcept { return &x; }

constexpr int* Vector2i::Raw() noexcept { return &x; }

constexpr float Vector2i::SquaredLength() const noexcept { return static_cast<float>(x * x + y * y); }

constexpr int Vector2i::operator[](const size_t i) const
{
	if (i < 2) [[likely]]
		return *(Raw() + i);
	[[unlikely]]
		throw std::out_of_range("Vector2i subscript out of range");
}

constexpr int& Vector2i::operator[](const size_t i)
{
	if (i < 2) [[likely]]
		return *(Raw() + i);
	[[unlikely]]
		throw std::out_of_range("Vector2i subscript out of range");
}

[[nodiscard]]
constexpr Vector2i operator+(const Vector2i a, const Vector2i b) noexcept { return Vector2i(a.x + b.x, a.y + b.y); }

[[nodiscard]]
constexpr Vector2i operator-(const Vector2i a) noexcept { return Vector2i(-a.x, -a.y); }

[[nodiscard]]
constexpr Vector2i operator-(const Vector2i a, const Vector2i b) noexcept { return a + -b; }

[[nodiscard]]
constexpr Vector2i operator*(const Vector2i a, const Vector2i b) noexcept { return Vector2i(a.x * b.x, a.y * b.y); }

[[nodiscard]]
constexpr Vector2i operator*(const Vector2i v, const int factor) noexcept { return Vector2i(v.x * factor, v.y * factor); }

[[nodiscard]]
constexpr Vector2i operator*(const int factor, const Vector2i v) noexcept { return v * factor; }

[[nodiscard]]
constexpr Vector2 operator/(const Vector2i a, const Vector2i b) noexcept { return Vector2(static_cast<float>(a.x) / static_cast<float>(b.x), static_cast<float>(a.y) / static_cast<float>(b.y)); }

[[nodiscard]]
constexpr Vector2 operator/(const Vector2i v, const float factor) noexcept { return Vector2(static_cast<float>(v.x) / factor, static_cast<float>(v.y) / factor); }

constexpr Vector2i& operator+=(Vector2i& a, const Vector2i b) noexcept { return a = a + b; }

constexpr Vector2i &operator-=(Vector2i &a, const Vector2i b) noexcept { return a = a - b; }

constexpr Vector2i& operator*=(Vector2i& a, const Vector2i b) noexcept { return a = a * b; }

constexpr Vector2i& operator*=(Vector2i& v, const int factor) noexcept { return v = v * factor; }

/// <summary>
///	Checks if two Vector2i are considered equal using <code>Calc::Equals</code>.
/// </summary>
[[nodiscard]]
constexpr bool operator==(const Vector2i a, const Vector2i b) noexcept { return a.x == b.x && a.y == b.y; }

/// <summary>
///	Checks if two Vector2i are considered different using <code>Calc::Equals</code>.
/// </summary>
[[nodiscard]]
constexpr bool operator!=(const Vector2i a, const Vector2i b) noexcept { return !(a == b); }

std::ostream& operator<<(std::ostream& out, Vector2i v) noexcept;

#ifdef MATH_DEFINE_FORMATTER
template<>
struct std::formatter<Vector2i>
{
    template<class ParseContext>
    constexpr typename ParseContext::iterator parse(ParseContext& ctx);

    template<class FmtContext>
    typename FmtContext::iterator format(Vector2i v, FmtContext& ctx) const;

private:
    std::string m_Format;
};

template<class ParseContext>
constexpr typename ParseContext::iterator std::formatter<Vector2i, char>::parse(ParseContext& ctx)
{
    auto it = ctx.begin();
    if (it == ctx.end())
        return it;

    while (*it != '}' && it != ctx.end())
        m_Format += *it++;

    return it;
}

template<class FmtContext>
typename FmtContext::iterator std::formatter<Vector2i>::format(Vector2i v, FmtContext &ctx) const
{
    std::ostringstream out;

    out << std::vformat("{:" + m_Format + "} ; {:" + m_Format + '}', std::make_format_args(v.x, v.y));

    return std::ranges::copy(std::move(out).str(), ctx.out()).out;
}
#endif

using vec2i = Vector2i;
