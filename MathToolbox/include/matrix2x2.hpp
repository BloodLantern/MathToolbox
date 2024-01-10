#pragma once

#include <ostream>

#include "vector2.hpp"

class Matrix3x3;
class Matrix4x4;

/// <summary>
/// The Matrix2x2 class represents a two-dimensional array mainly used for mathematical operations.
/// </summary>
class Matrix2x2
{
public:
    /// <summary>
    /// Returns the identity matrix.
    /// The identity matrix is a matrix with its diagonal
    /// set to one and everything else set to zero.
    /// </summary>
    static Matrix2x2 Identity();

    /// <summary>
    /// Creates a matrix with all its values set to this default value.
    /// </summary>
    explicit constexpr Matrix2x2(float defaultValue = 0.f);

    constexpr Matrix2x2(const Vector2& r0, const Vector2& r1);

    constexpr Matrix2x2(
        float r00, float r01,
        float r10, float r11
    );
    
    /// <summary>
    /// Copies the content of the given matrix to this one.
    /// </summary>
    constexpr Matrix2x2(const Matrix2x2& matrix) = default;

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
    /// Returns whether the matrix has everything except its diagonal set to zero.
    /// </summary>
    [[nodiscard]]
    bool IsDiagonal() const;
    
    /// <summary>
    /// Returns whether the matrix is the identity matrix.
    /// </summary>
    ///        If this returns true, Matrix2x2::Identity() == *this should be true.
    [[nodiscard]]
    bool IsIdentity() const;
    
    /// <summary>
    /// Returns wether this matrix has everything set to zero.
    /// </summary>
    [[nodiscard]]
    bool IsNull() const;
    
    /// <summary>
    /// Returns whether the matrix is symmetric by its diagonal elements.
    /// </summary>
    [[nodiscard]]
    bool IsSymmetric() const;
    
    /// <summary>
    /// Returns whether the matrix is symmetric by its diagonal elements
    /// </summary>
    ///        but one of the sides is the opposite of the other.
    [[nodiscard]]
    bool IsAntisymmetric() const;
    
    /// <summary>
    /// Returns the diagonal elements of the matrix.
    /// </summary>
    [[nodiscard]]
    Vector2 Diagonal() const;
    
    /// <summary>
    /// Returns the sum of the diagonal elements of the matrix.
    /// </summary>
    [[nodiscard]]
    float Trace() const;
    
    /// <summary>
    /// Returns a matrix with its data set to the given indices of this one.
    /// </summary>
    [[nodiscard]]
    Matrix2x2 SubMatrix(size_t rowIndex, size_t colIndex, size_t rows, size_t cols) const;
    
    /// <summary>
    /// Returns the determinant of this matrix.
    /// </summary>
    [[nodiscard]]
    float Determinant() const;
    
    /// <summary>
    /// Sets this matrix to the identity matrix.
    /// </summary>
    Matrix2x2& LoadIdentity();
    
    /// <summary>
    /// Switches the matrix by its diagonal elements.
    /// </summary>
    Matrix2x2& Transpose();

    /// <summary>
    /// Switches the given matrix by its diagonal elements.
    /// </summary>
    [[nodiscard]]
    static Matrix2x2 Transpose(const Matrix2x2& matrix);
    /// <summary>
    /// Creates a 2D scaling matrix from the given Vector2.
    /// </summary>
    [[nodiscard]]
    static Matrix2x2 Scaling2D(Vector2 scale);
    /// <summary>
    /// Creates a 2D rotation matrix from the given angle.
    /// </summary>
    /// <param name="angle">The angle in radians.<param>
    [[nodiscard]]
    static Matrix2x2 Rotation2D(float angle);
    /// <summary>
    /// Creates a 3D rotation matrix around the X axis from the given angle.
    /// </summary>
    /// <param name="cos">The cosine of the angle in radians.<param>
    /// <param name="sin">The sine of the angle in radians.<param>
    [[nodiscard]]
    static Matrix2x2 Rotation2D(float cos, float sin);

    [[nodiscard]]
    constexpr const Vector2& operator[](size_t row) const;
    
    [[nodiscard]]
    constexpr Vector2& operator[](size_t row);
    
    explicit operator Vector2() const;
    
    explicit operator Matrix3x3() const;
    
    explicit operator Matrix4x4() const;

private:
    Vector2 r0, r1;
};

[[nodiscard]]
Matrix2x2 operator-(const Matrix2x2& matrix);

[[nodiscard]]
Matrix2x2 operator+(const Matrix2x2& m1, const Matrix2x2& m2);

[[nodiscard]]
Matrix2x2 operator-(const Matrix2x2& m1, const Matrix2x2& m2);

[[nodiscard]]
Matrix2x2 operator*(const Matrix2x2& m, float scalar);

[[nodiscard]]
Matrix2x2 operator*(const Matrix2x2& m1, const Matrix2x2& m2);

Matrix2x2& operator+=(Matrix2x2& m1, const Matrix2x2& m2);

Matrix2x2& operator-=(Matrix2x2& m1, const Matrix2x2& m2);

Matrix2x2& operator*=(Matrix2x2& m, float scalar);

Matrix2x2& operator*=(Matrix2x2& m1, const Matrix2x2& m2);

std::ostream& operator<<(std::ostream& out, const Matrix2x2& m);

using mat2 = Matrix2x2;
