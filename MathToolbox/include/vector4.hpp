#pragma once

#include <ostream>

class Vector2;
class Vector3;
class Matrix4x4;

/// <summary>
/// The Vector4 class represents either a four-dimensional vector or a point.
/// </summary>
class Vector4
{
public:
	float x, y, z, w;

	static constexpr Vector4 Zero();

	static constexpr Vector4 UnitX();

	static constexpr Vector4 UnitY();

	static constexpr Vector4 UnitZ();

	static constexpr Vector4 UnitW();

	constexpr Vector4();

	/// <summary>
	/// Constructs a Vector4 with all its components set to 'xyzw'.
	/// </summary>
	constexpr Vector4(float xyzw);

	constexpr Vector4(float x, float y, float z, float w);

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
	Vector4 Normalized() const;
	/// <summary>
	/// Returns the dot product of this Vector4& with 'other'.
	/// </summary>
	[[nodiscard]]
	float Dot(const Vector4& other) const;

	/// <summary>
	/// Returns a · b.
	/// </summary>
	[[nodiscard]]
	static float Dot(const Vector4& a, const Vector4& b);

	/// <summary>
	/// Lerp between two positions in a 4-dimensional space.
	/// </summary>
	/// <param name="value">The current position.</param>
	/// <param name="target">The target position.</param>
	/// <param name="t">The time to lerp.</param>
	/// <returns>The lerp position.</returns>
	[[nodiscard]]
	static Vector4 Lerp(Vector4 value, Vector4 target, float t);

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
	
	constexpr explicit operator Vector2() const;
	
    explicit operator Vector3() const;
	
	constexpr explicit operator Matrix4x4() const;
};

static_assert(std::is_default_constructible_v<Vector4>, "Class Vector4 must be default constructible.");
static_assert(std::is_copy_constructible_v<Vector4>, "Class Vector4 must be copy constructible.");
static_assert(std::is_move_constructible_v<Vector4>, "Class Vector4 must be move constructible.");
static_assert(std::is_copy_assignable_v<Vector4>, "Class Vector4 must be copy assignable.");
static_assert(std::is_move_assignable_v<Vector4>, "Class Vector4 must be move assignable.");

[[nodiscard]]
Vector4 operator+(const Vector4& a, const Vector4& b);

[[nodiscard]]
Vector4 operator-(const Vector4& a, const Vector4& b);

[[nodiscard]]
Vector4 operator-(const Vector4& a);

[[nodiscard]]
Vector4 operator*(const Vector4& a, const Vector4& b);

[[nodiscard]]
Vector4 operator*(const Vector4& v, float factor);

[[nodiscard]]
Vector4 operator*(const Matrix4x4& m, const Vector4& v);

[[nodiscard]]
Vector4 operator/(const Vector4& a, const Vector4& b);

[[nodiscard]]
Vector4 operator/(const Vector4& v, float factor);

Vector4& operator+=(Vector4& a, const Vector4& b);

Vector4& operator+=(Vector4& v, float factor);

Vector4& operator-=(Vector4& a, const Vector4& b);

Vector4& operator-=(Vector4& v, float factor);

Vector4& operator*=(Vector4& a, const Vector4& b);

Vector4& operator*=(Vector4& v, float factor);

Vector4& operator*=(const Matrix4x4& m, Vector4& v);

Vector4& operator/=(Vector4& a, const Vector4& b);

Vector4& operator/=(Vector4& v, float factor);

std::ostream& operator<<(std::ostream& out, const Vector4& v);

using vec4 = Vector4;
