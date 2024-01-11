#pragma once

#include "vector3.hpp"
#include "vector4.hpp"

#include <ostream>

class Quaternion
{
public:
	Vector3 imaginary;
	float real;

	/// <summary>
	///	Equivalent to calling the default constructor.
	/// </summary>
	[[nodiscard]]
	static constexpr Quaternion Zero() noexcept;
	
	[[nodiscard]]
	static constexpr Quaternion UnitX() noexcept;
	
	[[nodiscard]]
	static constexpr Quaternion UnitY() noexcept;
	
	[[nodiscard]]
	static constexpr Quaternion UnitZ() noexcept;
	
	[[nodiscard]]
	static constexpr Quaternion UnitW() noexcept;

	/// <summary>
	///	Equivalent to calling <code>Quaternion::UnitW()</code>.
	/// </summary>
	[[nodiscard]]
	static constexpr Quaternion Identity() noexcept;

	constexpr Quaternion() = default;
	
	constexpr explicit Quaternion(const Vector4& values) noexcept;
	
	constexpr Quaternion(const Vector3& imaginary, float real) noexcept;
	
	constexpr explicit Quaternion(float xyzw) noexcept;
	
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
	
	[[nodiscard]]
	float Length() const noexcept;
	
	[[nodiscard]]
	constexpr float SquaredLength() const noexcept;
	
	[[nodiscard]]
	constexpr Quaternion Invert() const noexcept;

	[[nodiscard]]
	static Quaternion FromAxisAngle(const Vector3& axis, float angle) noexcept;
	
	[[nodiscard]]
	static Quaternion FromEuler(const Vector3& rotation) noexcept;
	
	[[nodiscard]]
	static Quaternion FromRotationMatrix(const Matrix& rotation) noexcept;
	
	[[nodiscard]]
	static constexpr float Dot(const Quaternion& a, const Quaternion& b) noexcept;
	
	[[nodiscard]]
	static Quaternion Lerp(const Quaternion& a, const Quaternion& b, float t) noexcept;
	
	[[nodiscard]]
	static Quaternion Slerp(const Quaternion& a, const Quaternion& b, float t) noexcept;
	
	[[nodiscard]]
	static constexpr Vector3 Rotate(const Vector3& point, const Quaternion& rotation) noexcept;

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

constexpr Quaternion::Quaternion(const float x, const float y, const float z, const float w) noexcept : imaginary(x, y, z), real(w) {}

constexpr Quaternion Quaternion::Zero() noexcept { return Quaternion(); }

constexpr Quaternion Quaternion::UnitX() noexcept { return Quaternion(1.f, 0.f, 0.f, 0.f); }

constexpr Quaternion Quaternion::UnitY() noexcept { return Quaternion(0.f, 1.f, 0.f, 0.f); }

constexpr Quaternion Quaternion::UnitZ() noexcept { return Quaternion(0.f, 0.f, 1.f, 0.f); }

constexpr Quaternion Quaternion::UnitW() noexcept { return Quaternion(0.f, 0.f, 0.f, 1.f); }

constexpr Quaternion Quaternion::Identity() noexcept { return UnitW(); }

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

constexpr float Quaternion::SquaredLength() const noexcept { return SQ(imaginary.x) + SQ(imaginary.y) + SQ(imaginary.z) + SQ(real); }

constexpr float Quaternion::Dot(const Quaternion& a, const Quaternion& b) noexcept { return a.X() * b.X() + a.Y() * b.Y() + a.Z() * b.Z() + a.W() * b.W(); }

constexpr float Quaternion::operator[](const size_t i) const
{
	if (i < 4) [[likely]]
		return *(Raw() + i);
	else [[unlikely]]
		throw std::out_of_range("Quaternion subscript out of range");
}

constexpr float& Quaternion::operator[](const size_t i)
{
	if (i < 4) [[likely]]
		return *(Raw() + i);
	else [[unlikely]]
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

	const float q1x = a.X();
	const float q1y = a.Y();
	const float q1z = a.Z();
	const float q1w = a.W();

	const float q2x = b.X();
	const float q2y = b.Y();
	const float q2z = b.Z();
	const float q2w = b.W();

	// cross(av, bv)
	const float cx = q1y * q2z - q1z * q2y;
	const float cy = q1z * q2x - q1x * q2z;
	const float cz = q1x * q2y - q1y * q2x;

	const float dot = q1x * q2x + q1y * q2y + q1z * q2z;

	result.X() = q1x * q2w + q2x * q1w + cx;
	result.Y() = q1y * q2w + q2y * q1w + cy;
	result.Z() = q1z * q2w + q2z * q1w + cz;
	result.W() = q1w * q2w - dot;

	return result;
}

constexpr Quaternion operator*(const Quaternion& q, const Vector3& v) noexcept { return q * Quaternion(v, 1.f); }

constexpr Quaternion operator*(const Quaternion& v, const float factor) noexcept { return Quaternion(v.imaginary * factor, v.real * factor); }

constexpr Quaternion operator/(const Quaternion& v, const float factor) noexcept { return Quaternion(v.imaginary / factor, v.real / factor); }

constexpr Quaternion& operator+=(Quaternion& a, const Quaternion& b) noexcept { return a = a + b; }

constexpr Quaternion& operator-=(Quaternion& a, const Quaternion& b) noexcept { return a = a - b; }

constexpr Quaternion& operator*=(Quaternion& a, const Quaternion& b) noexcept { return a = a * b; }

constexpr Quaternion& operator*=(Quaternion& v, const float factor) noexcept { return v = v * factor; }

constexpr Quaternion& operator/=(Quaternion& v, const float factor) noexcept { return v = v * factor; }

/// <summary>
///	Checks if two Quaternions are considered equal using <code>calc::Equals</code>.
/// </summary>
[[nodiscard]]
bool operator==(Quaternion a, Quaternion b);

/// <summary>
///	Checks if two Quaternions are considered different using <code>calc::Equals</code>.
/// </summary>
[[nodiscard]]
bool operator!=(Quaternion a, Quaternion b);

std::ostream& operator<<(std::ostream& out, const Quaternion& q);

constexpr Quaternion Quaternion::Invert() const noexcept
{
	const float sqLength = SquaredLength();
	
	if (sqLength > 0.f) 
		return Conjugate() / sqLength;
	
	return Zero();
}

constexpr Vector3 Quaternion::Rotate(const Vector3& point, const Quaternion& rotation) noexcept { return (rotation * point * rotation.Conjugate()).imaginary; }

using quat = Quaternion;
