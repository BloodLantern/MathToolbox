#pragma once

#include <ostream>
#include <compare>
#include <cassert>
#include <vector>

#pragma region Vector
/// @brief The Vector class represents either a two-dimensional vector or a point.
class Vector
{
public:
    Vector();
    /// @brief Constructs a Vector with both its components set to 'xy'.
    Vector(const size_t size, const float defaultValue);
    Vector(const Vector& other);
    Vector(...);
    Vector(const std::initializer_list<float>& values);
    /// @brief Constructs a Vector from 'p1' to 'p2'
    Vector(const Vector& p1, const Vector& p2);
    ~Vector() {}

    /// @brief Returns the length of the vector.
    float GetNorm() const;
    /// @brief Returns the squared length of the vector.
    float GetSquaredNorm() const;
    /// @brief Normalizes the vector.
    /// @return A vector with the same direction but a length of one.
    Vector Normalize() const;
    /// @brief Returns the normal vector to this one.
    /// @return A vector with the same length but a normal direction.
    Vector GetNormal() const;
    /// @brief Returns the angle between the beginning and the end of this vector.
    /// @return An angle in radians.
    float Angle() const;
    /// @brief Rotates the vector by the specified angle.
    /// @param angle The angle in radians.
    Vector Rotate(float angle) const;

    size_t GetSize() const { return mData.size(); }

    friend auto operator<=>(const Vector& a, const Vector& b) = default;

private:
    std::vector<float> mData;
};

/// @brief Returns the angle between 'a' and 'b'.
float Angle(const Vector a, const Vector b);
/// @brief Returns the dot product of 'a' and 'b'.
float DotProduct(const Vector a, const Vector b);
/// @brief Returns the determinant of 'a' and 'b'.
float Determinant(const Vector a, const Vector b);

Vector operator+(const Vector a, const Vector b);
Vector operator-(const Vector a, const Vector b);
Vector operator-(const Vector a);
Vector operator*(const Vector a, const Vector b);
Vector operator*(const Vector v, const float factor);
Vector operator/(const Vector a, const Vector b);
Vector operator/(const Vector v, const float factor);

Vector& operator+=(Vector& a, const Vector b);
Vector& operator+=(Vector& v, const float factor);
Vector& operator-=(Vector& a, const Vector b);
Vector& operator-=(Vector& v, const float factor);
Vector& operator*=(Vector& a, const Vector b);
Vector& operator*=(Vector& v, const float factor);
Vector& operator/=(Vector& a, const Vector b);
Vector& operator/=(Vector& v, const float factor);

std::ostream& operator<<(std::ostream& out, const Vector& v);
#pragma endregion

#pragma region Point
/// @brief Returns the distance between 'p1' and 'p2'.
extern float Dist(const Vector p1, const Vector p2);
/// @brief Returns the squared distance between 'p1' and 'p2'.
extern float DistSquared(const Vector p1, const Vector p2);
/// @brief Returns a Vector in between if 'p1' and 'p2'.
extern Vector Mid(const Vector p1, const Vector p2);
/// @brief Rotates 'p' of 'angle' radians around the origin.
extern Vector Rotate(const Vector p, const float angle);
/// @brief Rotates 'p' of 'angle' radians around 'center'.
extern Vector Rotate(const Vector p, const Vector center, float angle);
/// @brief Rotates 'p' using already-computed cosine and sine around the origin.
extern Vector Rotate(const Vector p, float cos, float sin);
/// @brief Rotates 'p' using already-computed cosine and sine around 'center'.
extern Vector Rotate(const Vector p, const Vector center, float cos, float sin);
/// @brief Scales 'p' 'scale' times around the origin.
extern Vector Scale(const Vector p, float scale);
/// @brief Scales 'p' 'scale' times around 'center'.
extern Vector Scale(const Vector p, const Vector center, float scale);
extern Vector Circumcenter(const Vector p1, const Vector p2, const Vector p3);
extern Vector IsobarycenterTriangle(const Vector p1, const Vector p2, const Vector p3);
#pragma endregion
