#pragma once

#include <ostream>
#include <compare>
#include <cassert>

#pragma region Vector3
/// @brief The Vector3 class represents either a three-dimensional vector or a point.
class Vector3
{
public:
    float x, y, z;

    /// @brief A Vector3 with both its components equal to 0.
    static const Vector3 Zero;
    /// @brief A Vector3 with { x = 0, y = 1 }, used to represent a unit on the Y axis.
    static const Vector3 UnitY;
    /// @brief A Vector3 with { x = 1, y = 0 }, used to represent a unit on the X axis.
    static const Vector3 UnitX;

    /// @brief Constructs a Vector3 with both its components set to 'xyz'.
    Vector3(const float xyz);
    Vector3(const float x = 0, const float y = 0, const float z = 0);
    Vector3(const Vector3& other);
    constexpr Vector3(const std::initializer_list<float>& values)
    {
        assert(values.size() == 3 && "Cannot initialize Vector3 from initializer list with size != 3");

        const float* it = values.begin();
        x = it[0];
        y = it[1];
        z = it[2];
    }
    /// @brief Constructs a Vector3 from point 'p1' to point 'p2'
    Vector3(const Vector3& p1, const Vector3& p2);
    ~Vector3() {}

    /// @brief Returns the length of the vector.
    float GetNorm() const;
    /// @brief Returns the squared length of the vector.
    float GetSquaredNorm() const;
    /// @brief Normalizes the vector.
    /// @return A vector with the same direction but a length of one.
    Vector3 Normalize() const;
    /// @brief Returns the normal vector to this one.
    /// @return A vector with the same length but a normal direction.
    Vector3 GetNormal() const;
    /// @brief Returns the angle between the beginning and the end of this vector.
    /// @return An angle in radians.
    float Angle() const;
    /// @brief Rotates the vector by the specified angle.
    /// @param angle The angle in radians.
    Vector3 Rotate(float angle) const;

    friend auto operator<=>(const Vector3& a, const Vector3& b) = default;
};

/// @brief Returns the angle between 'a' and 'b'.
float Angle(const Vector3 a, const Vector3 b);
/// @brief Returns the dot product of 'a' and 'b'.
float DotProduct(const Vector3 a, const Vector3 b);
/// @brief Returns the determinant of 'a' and 'b'.
float Determinant(const Vector3 a, const Vector3 b);

Vector3 operator+(const Vector3 a, const Vector3 b);
Vector3 operator-(const Vector3 a);
Vector3 operator-(const Vector3 a, const Vector3 b);
Vector3 operator*(const Vector3 a, const Vector3 b);
Vector3 operator*(const Vector3 v, const float factor);
Vector3 operator/(const Vector3 a, const Vector3 b);
Vector3 operator/(const Vector3 v, const float factor);

Vector3& operator+=(Vector3& a, const Vector3 b);
Vector3& operator+=(Vector3& v, const float factor);
Vector3& operator-=(Vector3& a, const Vector3 b);
Vector3& operator-=(Vector3& v, const float factor);
Vector3& operator*=(Vector3& a, const Vector3 b);
Vector3& operator*=(Vector3& v, const float factor);
Vector3& operator/=(Vector3& a, const Vector3 b);
Vector3& operator/=(Vector3& v, const float factor);

std::ostream& operator<<(std::ostream& out, const Vector3& v);
#pragma endregion

#pragma region Point3
/// @brief Returns the distance between 'p1' and 'p2'.
extern inline float Dist(const Vector3 p1, const Vector3 p2);
/// @brief Returns the squared distance between 'p1' and 'p2'.
extern inline float DistSquared(const Vector3 p1, const Vector3 p2);
/// @brief Returns a Vector3 in between if 'p1' and 'p2'.
extern inline Vector3 Mid(const Vector3 p1, const Vector3 p2);
/// @brief Rotates 'p' of 'angle' radians around the origin.
extern inline Vector3 Rotate(const Vector3 p, const float angle);
/// @brief Rotates 'p' of 'angle' radians around 'center'.
extern inline Vector3 Rotate(const Vector3 p, const Vector3 center, float angle);
/// @brief Rotates 'p' using already-computed cosine and sine around the origin.
extern inline Vector3 Rotate(const Vector3 p, float cos, float sin);
/// @brief Rotates 'p' using already-computed cosine and sine around 'center'.
extern inline Vector3 Rotate(const Vector3 p, const Vector3 center, float cos, float sin);
/// @brief Scales 'p' 'scale' times around the origin.
extern inline Vector3 Scale(const Vector3 p, float scale);
/// @brief Scales 'p' 'scale' times around 'center'.
extern inline Vector3 Scale(const Vector3 p, const Vector3 center, float scale);
extern inline Vector3 Circumcenter(const Vector3 p1, const Vector3 p2, const Vector3 p3);
extern inline Vector3 IsobarycenterTriangle(const Vector3 p1, const Vector3 p2, const Vector3 p3);
#pragma endregion
