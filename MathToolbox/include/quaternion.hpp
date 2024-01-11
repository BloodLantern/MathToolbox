#pragma once

#include "vector3.hpp"

#include <ostream>

class Vector4;

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
	
	constexpr explicit Quaternion(const Vector4& values);
	
	constexpr Quaternion(const Vector3& imaginary, float real);
	
	constexpr explicit Quaternion(float xyzw);
	
	constexpr Quaternion(float x, float y, float z, float w);

	/// <summary>
	///	Gets a pointer to the first component of this vector.
	/// </summary>
	/// <returns>A pointer to the first component of this vector.</returns>
	[[nodiscard]]
	
	constexpr const float* Raw() const;

	/// <summary>
	///	Gets a pointer to the first component of this vector.
	/// </summary>
	/// <returns>A pointer to the first component of this vector.</returns>
	[[nodiscard]]
	
	constexpr float* Raw();

	[[nodiscard]]
	 float X() const;
	
	[[nodiscard]]
	 float Y() const;
	
	[[nodiscard]]
	 float Z() const;
	
	[[nodiscard]]
	 float W() const;

	[[nodiscard]]
	 float& X();
	
	[[nodiscard]]
	 float& Y();
	
	[[nodiscard]]
	 float& Z();
	
	[[nodiscard]]
	 float& W();

	[[nodiscard]]
	Quaternion Conjugate() const;
	
	[[nodiscard]]
	float Length() const;
	
	[[nodiscard]]
	float SquaredLength() const;
	
	[[nodiscard]]
	Quaternion Inverse() const;
	
	[[nodiscard]]
	float Dot(const Quaternion& other) const;
	
	[[nodiscard]]
	Vector3 Rotate(const Vector3& point) const;

	[[nodiscard]]
	static Quaternion FromAxisAngle(const Vector3& axis, float angle);
	
	[[nodiscard]]
	static Quaternion FromEuler(const Vector3& rotation);
	
	[[nodiscard]]
	static Quaternion FromRotationMatrix(const Matrix& rotation);
	
	[[nodiscard]]
	static float Dot(const Quaternion& a, const Quaternion& b);
	
	[[nodiscard]]
	static Quaternion Lerp(const Quaternion& a, const Quaternion& b, float t);
	
	[[nodiscard]]
	static Quaternion Slerp(const Quaternion& a, const Quaternion& b, float t);
	
	[[nodiscard]]
	static Vector3 Rotate(const Vector3& point, const Quaternion& rotation);

	/// <summary>
	///	Retrieves this vector's component at index i.
	/// </summary>
	/// <param name="i">
	/// The index of the component to get. It would be 0
	/// for x, 1 for y, etc...
	/// </param>
	/// <returns>The value of the component at index i.</returns>
	[[nodiscard]]
	float operator[](size_t i) const;
	
	/// <summary>
	///	Retrieves this vector's component at index i.
	/// </summary>
	/// <param name="i">
	/// The index of the component to get. It would be 0
	/// for x, 1 for y, etc...
	/// </param>
	/// <returns>The value of the component at index i.</returns>
	[[nodiscard]]
	float& operator[](size_t i);
	
	explicit operator Vector3() const;
	
	explicit operator Vector4() const;
};

static_assert(std::is_default_constructible_v<Quaternion>, "Class Quaternion must be default constructible.");
static_assert(std::is_copy_constructible_v<Quaternion>, "Class Quaternion must be copy constructible.");
static_assert(std::is_move_constructible_v<Quaternion>, "Class Quaternion must be move constructible.");
static_assert(std::is_copy_assignable_v<Quaternion>, "Class Quaternion must be copy assignable.");
static_assert(std::is_move_assignable_v<Quaternion>, "Class Quaternion must be move assignable.");

[[nodiscard]]
Quaternion operator+(const Quaternion& a, const Quaternion& b);
[[nodiscard]]
Quaternion operator-(const Quaternion& a, const Quaternion& b);
[[nodiscard]]
Quaternion operator-(const Quaternion& a);
[[nodiscard]]
Quaternion operator*(const Quaternion& a, const Quaternion& b);
[[nodiscard]]
Quaternion operator*(const Quaternion& q, const Vector3& v);
[[nodiscard]]
Quaternion operator*(const Quaternion& v, float factor);
[[nodiscard]]
Quaternion operator/(const Quaternion& v, float factor);

Quaternion& operator+=(Quaternion& a, const Quaternion& b);

Quaternion& operator-=(Quaternion& a, const Quaternion& b);

Quaternion& operator*=(Quaternion& a, const Quaternion& b);

Quaternion& operator*=(Quaternion& v, float factor);

Quaternion& operator/=(Quaternion& v, float factor);

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

using quat = Quaternion;
