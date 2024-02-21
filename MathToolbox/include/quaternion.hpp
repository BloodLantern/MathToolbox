#pragma once

#ifdef MATH_DEFINE_FORMATTER
#include <format>
#include <sstream>
#endif

#include "calc.hpp"
#include "vector3.hpp"
#include "vector4.hpp"

/// <summary>
/// The Quaternion class represents a 4-dimensional vector mainly used for mathematical
/// calculations revolving around rotations.
/// </summary>
class MATH_TOOLBOX Quaternion
{
public:
	/// <summary>
	///	The imaginary part of this Quaternion. Represents the <c>x</c>, <c>y</c>, and <c>z</c> components.
	/// </summary>
	Vector3 imaginary;
	
	/// <summary>
	///	The real part of this Quaternion. Represents the <c>w</c> component.
	/// </summary>
	float real = 0.f;

	/// <summary>
	///	Equivalent to calling the default constructor.
	/// </summary>
	/// <returns>A Quaternion with everything set to 0.</returns>
	/// <seealso cref="Quaternion()"/>
	[[nodiscard]]
	static constexpr Quaternion Zero() noexcept;

	/// <summary>
	///	Equivalent to calling the default constructor.
	/// </summary>
	/// <param name="result">The output value.</param>
	/// <seealso cref="Zero()"/>
	static constexpr void Zero(Quaternion* result) noexcept;

	/// <summary>
	///	Create a constant Quaternion of value <c>{ x = 1, y = 0, z = 0, w = 0 }</c>.
	/// </summary>
	/// <returns>A Quaternion with and <c>x</c> value of <c>1</c>, and everything else set to 0.</returns>
	[[nodiscard]]
	static constexpr Quaternion UnitX() noexcept;
	
	/// <summary>
	///	Create a constant Quaternion of value <c>{ x = 1, y = 0, z = 0, w = 0 }</c>.
	/// </summary>
	/// <param name="result">The output value.</param>
	/// <seealso cref="UnitX()"/>
	static constexpr void UnitX(Quaternion* result) noexcept;
	
	/// <summary>
	///	Create a constant Quaternion of value <c>{ x = 0, y = 1, z = 0, w = 0 }</c>.
	/// </summary>
	/// <returns>A Quaternion with and <c>y</c> value of <c>1</c>, and everything else set to 0.</returns>
	[[nodiscard]]
	static constexpr Quaternion UnitY() noexcept;
	
	/// <summary>
	///	Create a constant Quaternion of value <c>{ x = 0, y = 1, z = 0, w = 0 }</c>.
	/// </summary>
	/// <param name="result">The output value.</param>
	/// <seealso cref="UnitY()"/>
	static constexpr void UnitY(Quaternion* result) noexcept;
	
	/// <summary>
	///	Create a constant Quaternion of value <c>{ x = 0, y = 0, z = 1, w = 0 }</c>.
	/// </summary>
	/// <returns>A Quaternion with and <c>z</c> value of <c>1</c>, and everything else set to 0.</returns>
	[[nodiscard]]
	static constexpr Quaternion UnitZ() noexcept;
	
	/// <summary>
	///	Create a constant Quaternion of value <c>{ x = 0, y = 0, z = 1, w = 0 }</c>.
	/// </summary>
	/// <param name="result">The output value.</param>
	/// <seealso cref="UnitZ()"/>
	static constexpr void UnitZ(Quaternion* result) noexcept;
	
	/// <summary>
	///	Create a constant Quaternion of value <c>{ x = 0, y = 0, z = 0, w = 1 }</c>.
	/// </summary>
	/// <returns>A Quaternion with and <c>w</c> value of <c>1</c>, and everything else set to 0.</returns>
	[[nodiscard]]
	static constexpr Quaternion UnitW() noexcept;
	
	/// <summary>
	///	Create a constant Quaternion of value <c>{ x = 0, y = 0, z = 0, w = 1 }</c>.
	/// </summary>
	/// <param name="result">The output value.</param>
	/// <seealso cref="UnitW()"/>
	static constexpr void UnitW(Quaternion* result) noexcept;

	/// <summary>
	///	Equivalent to calling <see cref="UnitW()"/>.
	/// </summary>
	/// <returns>A Quaternion with and <c>w</c> value of <c>1</c>, and everything else set to 0.</returns>
	[[nodiscard]]
	static constexpr Quaternion Identity() noexcept;

	/// <summary>
	///	Equivalent to calling <code>Quaternion::UnitW()</code>.
	/// </summary>
	/// <param name="result">The output value.</param>
	/// <seealso cref="UnitW(Quaternion&)"/>
	static constexpr void Identity(Quaternion* result) noexcept;

	/// <summary>
	///	Create a rotation Quaternion from an axis-angle rotation.
	/// </summary>
	/// <param name="axis">The axis around which the rotation occurs.</param>
	/// <param name="angle">The rotation angle.</param>
	/// <returns>A rotation Quaternion equivalent to the given axis-angle rotation.</returns>
	[[nodiscard]]
	static Quaternion FromAxisAngle(const Vector3& axis, float angle) noexcept;

	/// <summary>
	///	Create a rotation Quaternion from an axis-angle rotation.
	/// </summary>
	/// <param name="axis">The axis around which the rotation occurs.</param>
	/// <param name="angle">The rotation angle.</param>
	/// <param name="result">The output value.</param>
	/// <seealso cref="FromAxisAngle(const Vector3&, float)"/>
	static void FromAxisAngle(const Vector3& axis, float angle, Quaternion* result) noexcept;
	
	/// <summary>
	///	Create a rotation Quaternion from an axis-angle rotation.
	/// </summary>
	/// <param name="rotation">The euler rotation vector.</param>
	/// <returns>A rotation Quaternion equivalent to the given axis-angle rotation.</returns>
	[[nodiscard]]
	static Quaternion FromEuler(const Vector3& rotation) noexcept;
	
	/// <summary>
	///	Create a rotation Quaternion from an axis-angle rotation.
	/// </summary>
	/// <param name="rotation">The euler rotation vector.</param>
	/// <param name="result">The output value.</param>
	/// <seealso cref="FromEuler(const Vector3&)"/>
	static void FromEuler(const Vector3& rotation, Quaternion* result) noexcept;
	
	/// <summary>
	///	Create a rotation Quaternion from an axis-angle rotation.
	/// </summary>
	/// <param name="rotation">The rotation Matrix.</param>
	/// <returns>A rotation Quaternion equivalent to the given axis-angle rotation.</returns>
	[[nodiscard]]
	static Quaternion FromRotationMatrix(const Matrix& rotation) noexcept;
	
	/// <summary>
	///	Create a rotation Quaternion from an axis-angle rotation.
	/// </summary>
	/// <param name="rotation">The rotation Matrix.</param>
	/// <param name="result">The output value.</param>
	/// <seealso cref="FromRotationMatrix(const Matrix&)"/>
	static void FromRotationMatrix(const Matrix& rotation, Quaternion* result) noexcept;
	
	/// <summary>
	///	Converts a Quaternion to an euler-angle Vector3.
	/// </summary>
	/// <param name="rotation">The euler rotation vector.</param>
	/// <returns>A rotation Quaternion equivalent to the given axis-angle rotation.</returns>
	[[nodiscard]]
	static Vector3 ToEuler(const Quaternion& rotation) noexcept;
	
	/// <summary>
	///	Converts a Quaternion to an euler-angle Vector3.
	/// </summary>
	/// <param name="rotation">The rotation quaternion.</param>
	/// <param name="result">The output value.</param>
	/// <seealso cref="ToEuler(const Vector3&)"/>
	static void ToEuler(const Quaternion& rotation, Vector3* result) noexcept;

	/// <summary>
	///	Compute the dot product of two Quaternions.
	/// </summary>
	/// <param name="a">The left-hand side argument.</param>
	/// <param name="b">The right-hand side argument.</param>
	/// <returns>The result of <paramref name="a"/> · <paramref name="b"/>.</returns>
	[[nodiscard]]
	static constexpr float Dot(const Quaternion& a, const Quaternion& b) noexcept;
	
	/// <summary>
	///	Compute the linear interpolation between two Quaternions.
	/// </summary>
	/// <param name="value">The current position.</param>
	/// <param name="target">The target position.</param>
	/// <param name="t">The time to lerp.</param>
	/// <returns>The lerp position.</returns>
	[[nodiscard]]
	static Quaternion Lerp(const Quaternion& value, const Quaternion& target, float t) noexcept;
	
	/// <summary>
	///	Compute the linear interpolation between two Quaternions.
	/// </summary>
	/// <param name="value">The current position.</param>
	/// <param name="target">The target position.</param>
	/// <param name="t">The time to lerp.</param>
	/// <param name="result">The output value.</param>
	/// <seealso cref="Lerp(const Quaternion&, const Quaternion&, float)"/>
	static void Lerp(const Quaternion& value, const Quaternion& target, float t, Quaternion* result) noexcept;
	
	/// <summary>
	///	Compute the spherical linear interpolation between two Quaternions.
	/// </summary>
	/// <param name="value">The current position.</param>
	/// <param name="target">The target position.</param>
	/// <param name="t">The time to slerp.</param>
	/// <returns>The slerp position.</returns>
	[[nodiscard]]
	static Quaternion Slerp(const Quaternion& value, const Quaternion& target, float t) noexcept;
	
	/// <summary>
	///	Compute the spherical linear interpolation between two Quaternions.
	/// </summary>
	/// <param name="value">The current position.</param>
	/// <param name="target">The target position.</param>
	/// <param name="t">The time to slerp.</param>
	/// <param name="result">The output value.</param>
	/// <seealso cref="Slerp(const Quaternion&, const Quaternion&, float)"/>
	static void Slerp(const Quaternion& value, const Quaternion& target, float t, Quaternion* result) noexcept;
	
	/// <summary>
	///	Rotate a point using a rotation quaternion.
	///	Calling this function is equivalent to doing:
	///	<code>rotation * point * rotation.Conjugate()</code>.
	/// </summary>
	/// <param name="point">The current position.</param>
	/// <param name="rotation">The target position.</param>
	/// <returns>The rotated point.</returns>
	[[nodiscard]]
	static constexpr Vector3 Rotate(const Vector3& point, const Quaternion& rotation) noexcept;
	
	/// <summary>
	///	Rotate a point using a rotation quaternion.
	///	Calling this function is equivalent to doing:
	///	<code>rotation * point * rotation.Conjugate()</code>.
	/// </summary>
	/// <param name="point">The current position.</param>
	/// <param name="rotation">The target position.</param>
	/// <param name="result">The output value.</param>
	/// <seealso cref="Rotate(const Vector3&, const Quaternion&)"/>
	static constexpr void Rotate(const Vector3& point, const Quaternion& rotation, Vector3* result) noexcept;

	/// <summary>
	///	Construct a Quaternion with everything set to <c>0</c>.
	/// </summary>
	constexpr Quaternion() = default;
	
	/// <summary>
	///	Construct a Quaternion from a Vector4.
	/// </summary>
	constexpr explicit Quaternion(const Vector4& values) noexcept;
	
	constexpr explicit Quaternion(const Vector3& imaginary, float real = 1.f) noexcept;
	
	constexpr explicit Quaternion(float xyzw) noexcept;
	
	/// <summary>
	/// Constructs a Vector2 with its components set to the data pointed by <code>data</code>.
	/// This constructor assumes that <code>data</code> is a valid pointer pointing to at least 2 float values.
	/// </summary>
	/// <param name="data">The data where the values for this vector's components are located.</param>
	constexpr explicit Quaternion(const float* data) noexcept;
	
	constexpr Quaternion(float x, float y, float z, float w) noexcept;

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

	[[nodiscard]]
	constexpr float X() const noexcept;
	
	[[nodiscard]]
	constexpr float Y() const noexcept;
	
	[[nodiscard]]
	constexpr float Z() const noexcept;
	
	[[nodiscard]]
	constexpr float W() const noexcept;

	[[nodiscard]]
	constexpr float& X() noexcept;
	
	[[nodiscard]]
	constexpr float& Y() noexcept;
	
	[[nodiscard]]
	constexpr float& Z() noexcept;
	
	[[nodiscard]]
	constexpr float& W() noexcept;

	[[nodiscard]]
	constexpr Quaternion Conjugate() const noexcept;

	constexpr void Conjugate(Quaternion* result) const noexcept;

	[[nodiscard]]
	Quaternion Normalized() const noexcept;

	void Normalized(Quaternion* result) const noexcept;
	
	[[nodiscard]]
	float Length() const noexcept;
	
	[[nodiscard]]
	constexpr float SquaredLength() const noexcept;

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
	
	[[nodiscard]]
	constexpr Quaternion Invert() const noexcept;
	
	constexpr void Invert(Quaternion* result) const noexcept;

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
	
	constexpr explicit operator Vector3() const noexcept;
	
	constexpr explicit operator Vector4() const noexcept;
};

static_assert(std::is_default_constructible_v<Quaternion>, "Class Quaternion must be default constructible.");
static_assert(std::is_copy_constructible_v<Quaternion>, "Class Quaternion must be copy constructible.");
static_assert(std::is_move_constructible_v<Quaternion>, "Class Quaternion must be move constructible.");
static_assert(std::is_copy_assignable_v<Quaternion>, "Class Quaternion must be copy assignable.");
static_assert(std::is_move_assignable_v<Quaternion>, "Class Quaternion must be move assignable.");

constexpr Quaternion::Quaternion(const Vector4& values) noexcept : imaginary(values.x, values.y, values.z), real(values.w) {}

constexpr Quaternion::Quaternion(const Vector3& imaginary, const float real) noexcept : imaginary(imaginary), real(real) {}

constexpr Quaternion::Quaternion(const float xyzw) noexcept : imaginary(xyzw), real(xyzw) {}

constexpr Quaternion::Quaternion(const float* const data) noexcept : imaginary(data), real(data[3]) {}

constexpr Quaternion::Quaternion(const float x, const float y, const float z, const float w) noexcept : imaginary(x, y, z), real(w) {}

constexpr Quaternion Quaternion::Zero() noexcept { return Quaternion(); }

constexpr void Quaternion::Zero(Quaternion* result) noexcept { *result = Quaternion(); }

constexpr Quaternion Quaternion::UnitX() noexcept { return Quaternion(1.f, 0.f, 0.f, 0.f); }

constexpr void Quaternion::UnitX(Quaternion* result) noexcept { *result = Quaternion(1.f, 0.f, 0.f, 0.f); }

constexpr Quaternion Quaternion::UnitY() noexcept { return Quaternion(0.f, 1.f, 0.f, 0.f); }

constexpr void Quaternion::UnitY(Quaternion* result) noexcept { *result = Quaternion(0.f, 1.f, 0.f, 0.f); }

constexpr Quaternion Quaternion::UnitZ() noexcept { return Quaternion(0.f, 0.f, 1.f, 0.f); }

constexpr void Quaternion::UnitZ(Quaternion* result) noexcept { *result = Quaternion(0.f, 0.f, 1.f, 0.f); }

constexpr Quaternion Quaternion::UnitW() noexcept { return Quaternion(0.f, 0.f, 0.f, 1.f); }

constexpr void Quaternion::UnitW(Quaternion* result) noexcept { *result = Quaternion(0.f, 0.f, 0.f, 1.f); }

constexpr Quaternion Quaternion::Identity() noexcept { return UnitW(); }

constexpr void Quaternion::Identity(Quaternion* result) noexcept { *result = UnitW(); }

constexpr float Quaternion::Dot(const Quaternion& a, const Quaternion& b) noexcept { return a.X() * b.X() + a.Y() * b.Y() + a.Z() * b.Z() + a.W() * b.W(); }

constexpr const float* Quaternion::Raw() const noexcept { return &imaginary.x; }

constexpr float* Quaternion::Raw() noexcept { return &imaginary.x; }

constexpr float& Quaternion::X() noexcept { return imaginary.x; }

constexpr float& Quaternion::Y() noexcept { return imaginary.y; }

constexpr float& Quaternion::Z() noexcept { return imaginary.z; }

constexpr float& Quaternion::W() noexcept { return real; }

constexpr float Quaternion::X() const noexcept { return imaginary.x; }

constexpr float Quaternion::Y() const noexcept { return imaginary.y; }

constexpr float Quaternion::Z() const noexcept { return imaginary.z; }

constexpr float Quaternion::W() const noexcept { return real; }

constexpr Quaternion Quaternion::Conjugate() const noexcept { return Quaternion(-imaginary, real); }

constexpr void Quaternion::Conjugate(Quaternion* result) const noexcept { *result = Quaternion(-imaginary, real); }

constexpr float Quaternion::SquaredLength() const noexcept { return SQ(imaginary.x) + SQ(imaginary.y) + SQ(imaginary.z) + SQ(real); }

constexpr float Quaternion::operator[](const size_t i) const
{
	if (i < 4) [[likely]]
		return *(Raw() + i);
	[[unlikely]]
		throw std::out_of_range("Quaternion subscript out of range");
}

constexpr float& Quaternion::operator[](const size_t i)
{
	if (i < 4) [[likely]]
		return *(Raw() + i);
	[[unlikely]]
		throw std::out_of_range("Quaternion subscript out of range");
}

constexpr Quaternion::operator Vector3() const noexcept { return imaginary; }

constexpr Quaternion::operator Vector4() const noexcept { return Vector4(imaginary.x, imaginary.y, imaginary.z, real); }

constexpr Quaternion operator+(const Quaternion& a, const Quaternion& b) noexcept { return Quaternion(a.imaginary + b.imaginary, a.real + b.real); }

constexpr Quaternion operator-(const Quaternion& a) noexcept { return Quaternion(-a.imaginary, -a.real); }

constexpr Quaternion operator-(const Quaternion& a, const Quaternion& b) noexcept { return Quaternion(a + -b); }

constexpr Quaternion operator*(const Quaternion& a, const Quaternion& b) noexcept
{
	Quaternion result;

	// cross(av, bv)
	const float cx = a.Y() * b.Z() - a.Z() * b.Y();
	const float cy = a.Z() * b.X() - a.X() * b.Z();
	const float cz = a.X() * b.Y() - a.Y() * b.X();

	const float dot = a.X() * b.X() + a.Y() * b.Y() + a.Z() * b.Z();

	result.X() = a.X() * b.W() + b.X() * a.W() + cx;
	result.Y() = a.Y() * b.W() + b.Y() * a.W() + cy;
	result.Z() = a.Z() * b.W() + b.Z() * a.W() + cz;
	result.W() = a.W() * b.W() - dot;

	return result;
}

constexpr Quaternion operator*(const Quaternion& q, const Vector3& v) noexcept { return q * Quaternion(v, 1.f); }

constexpr Quaternion operator*(const Quaternion& v, const float factor) noexcept { return Quaternion(v.imaginary * factor, v.real * factor); }

constexpr Quaternion operator/(const Quaternion& v, const float factor) noexcept { return Quaternion(v.imaginary / factor, v.real / factor); }

constexpr Quaternion& operator+=(Quaternion& a, const Quaternion& b) noexcept { return a = a + b; }

constexpr Quaternion& operator-=(Quaternion& a, const Quaternion& b) noexcept { return a = a - b; }

constexpr Quaternion& operator*=(Quaternion& a, const Quaternion& b) noexcept { return a = a * b; }

constexpr Quaternion& operator*=(Quaternion& v, const float factor) noexcept { return v = v * factor; }

constexpr Quaternion& operator/=(Quaternion& v, const float factor) noexcept { return v = v / factor; }

/// <summary>
///	Checks if two Quaternions are considered equal using <code>Calc::Equals</code>.
/// </summary>
[[nodiscard]]
bool operator==(Quaternion a, Quaternion b);

/// <summary>
///	Checks if two Quaternions are considered different using <code>Calc::Equals</code>.
/// </summary>
[[nodiscard]]
bool operator!=(Quaternion a, Quaternion b);

std::ostream& operator<<(std::ostream& out, const Quaternion& q);

constexpr Quaternion Quaternion::Invert() const noexcept
{
	Quaternion result;
	Invert(&result);
	return result;
}

constexpr void Quaternion::Invert(Quaternion* result) const noexcept
{
	const float sqLength = SquaredLength();
	
	if (Calc::IsZero(sqLength))
	{
		*result = Zero();
		return;
	}
	
	*result = Conjugate() / sqLength;
}

constexpr Vector3 Quaternion::Rotate(const Vector3& point, const Quaternion& rotation) noexcept { return (rotation * point * rotation.Conjugate()).imaginary; }

constexpr void Quaternion::Rotate(const Vector3& point, const Quaternion& rotation, Vector3* result) noexcept { *result = (rotation * point * rotation.Conjugate()).imaginary; }

#ifdef MATH_DEFINE_FORMATTER
template<>
struct std::formatter<Quaternion>
{
    template<class ParseContext>
    constexpr typename ParseContext::iterator parse(ParseContext& ctx);

    template<class FmtContext>
    typename FmtContext::iterator format(Quaternion q, FmtContext& ctx) const;

private:
    std::string m_Format;
};

template<class ParseContext>
constexpr typename ParseContext::iterator std::formatter<Quaternion, char>::parse(ParseContext& ctx)
{
    auto it = ctx.begin();
    if (it == ctx.end())
        return it;

    while (*it != '}' && it != ctx.end())
        m_Format += *it++;

    return it;
}

template<class FmtContext>
typename FmtContext::iterator std::formatter<Quaternion>::format(Quaternion q, FmtContext &ctx) const
{
    std::ostringstream out;

    out << std::vformat("{:" + m_Format + "} ; {:" + m_Format + "} ; {:" + m_Format + "} ; {:" + m_Format + '}', std::make_format_args(q.X(), q.Y(), q.Z(), q.W()));

    return std::ranges::copy(std::move(out).str(), ctx.out()).out;
}
#endif

using quat = Quaternion;
