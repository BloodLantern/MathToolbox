#pragma once

#include <ostream>

class Vector2;
class Vector4;
class Matrix3x3;

/// <summary>
/// The Vector3 class represents either a three-dimensional vector or a point.
/// </summary>
class Vector3
{
public:
	float x, y, z;

	static constexpr Vector3 Zero();

	static constexpr Vector3 UnitX();

	static constexpr Vector3 UnitY();

	static constexpr Vector3 UnitZ();


	constexpr Vector3();

	/// <summary>
	/// Constructs a Vector3 with all its components set to 'xyz'.
	/// </summary>
	constexpr Vector3(float xyz);

	constexpr Vector3(float x, float y, float z);

	/// <summary>
	///	Gets a pointer to the first component of this vector.
	/// </summary>
	/// <returns>A pointer to the first component of this vector.</returns>
	[[nodiscard]]
	__forceinline
	constexpr const float* Raw() const;

	/// <summary>
	///	Gets a pointer to the first component of this vector.
	/// </summary>
	/// <returns>A pointer to the first component of this vector.</returns>
	[[nodiscard]]
	__forceinline
	constexpr float* Raw();

	/// <summary>
	/// Returns the length of the vector.
	/// </summary>
	[[nodiscard]]
	float Length() const;
	/// <summary>
	/// Returns the squared length of the vector.
	/// </summary>
	[[nodiscard]]
	float SquaredLength() const;
	/// <summary>
	/// Normalizes the vector.
	/// </summary>
	/// <returns>A vector with the same direction but a length of one.</returns>
	[[nodiscard]]
	Vector3 Normalized() const;
	/// <summary>
	/// Returns the dot product of this Vector3& with 'other'.
	/// </summary>
	[[nodiscard]]
	float Dot(const Vector3& other) const;
	/// <summary>
	/// Returns the cross product of this Vector3& with 'other'.
	/// </summary>
	[[nodiscard]]
	Vector3 Cross(const Vector3& other) const;
	
	/// <summary>
	/// Returns a · b.
	/// </summary>
	[[nodiscard]]
	static float Dot(const Vector3& a, const Vector3& b);
	/// <summary>
	/// Returns a x b.
	/// </summary>
	[[nodiscard]]
	static Vector3 Cross(const Vector3& a, const Vector3& b);

	/// <summary>
	/// Lerp between two positions in a 3-dimensional space.
	/// </summary>
	/// <param name="value">The current position.</param>
	/// <param name="target">The target position.</param>
	/// <param name="t">The time to lerp.</param>
	/// <returns>The lerp position.</returns>
	[[nodiscard]]
	static Vector3 Lerp(Vector3 value, Vector3 target, float t);

	/// <summary>
	///	Retrieves this vector's component at index i.
	/// </summary>
	/// <param name="i">The index of the component to get. It would be 0
	/// for x, 1 for y, etc...</param>
	/// <returns>The value of the component at index i.</returns>
	[[nodiscard]]
	float operator[](size_t i) const;
	
	/// <summary>
	///	Retrieves this vector's component at index i.
	/// </summary>
	/// <param name="i">The index of the component to get. It would be 0
	/// for x, 1 for y, etc...</param>
	/// <returns>The value of the component at index i.</returns>
	[[nodiscard]]
	float& operator[](size_t i);
	
    explicit operator Vector2() const;
	
	explicit operator Vector4() const;
	
    explicit operator Matrix3x3() const;
};

static_assert(std::is_default_constructible_v<Vector3>, "Class Vector3 must be default constructible.");
static_assert(std::is_copy_constructible_v<Vector3>, "Class Vector3 must be copy constructible.");
static_assert(std::is_move_constructible_v<Vector3>, "Class Vector3 must be move constructible.");
static_assert(std::is_copy_assignable_v<Vector3>, "Class Vector3 must be copy assignable.");
static_assert(std::is_move_assignable_v<Vector3>, "Class Vector3 must be move assignable.");

[[nodiscard]]
Vector3 operator+(const Vector3& a, const Vector3& b);

[[nodiscard]]
Vector3 operator-(const Vector3& a, const Vector3& b);

[[nodiscard]]
Vector3 operator-(const Vector3& a);

[[nodiscard]]
Vector3 operator*(const Vector3& a, const Vector3& b);

[[nodiscard]]
Vector3 operator*(const Vector3& v, float factor);

[[nodiscard]]
Vector3 operator*(const Matrix3x3& m, const Vector3& v);

[[nodiscard]]
Vector3 operator/(const Vector3& a, const Vector3& b);

[[nodiscard]]
Vector3 operator/(const Vector3& v, float factor);

Vector3& operator+=(Vector3& a, const Vector3& b);

Vector3& operator+=(Vector3& v, float factor);

Vector3& operator-=(Vector3& a, const Vector3& b);

Vector3& operator-=(Vector3& v, float factor);

Vector3& operator*=(Vector3& a, const Vector3& b);

Vector3& operator*=(Vector3& v, float factor);

Vector3& operator*=(const Matrix3x3& m, Vector3& v);

Vector3& operator/=(Vector3& a, const Vector3& b);

Vector3& operator/=(Vector3& v, float factor);

std::ostream& operator<<(std::ostream& out, const Vector3& v);

using vec3 = Vector3;
