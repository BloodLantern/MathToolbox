#pragma once

#include <ostream>

#include "vector4.hpp"

class Vector2;
class Vector3;
class Quaternion;

/// <summary>
/// The Matrix class represents a two-dimensional array mainly used for mathematical operations.
/// </summary>
/// Matrices are stored using the row-major convention.
class Matrix
{
public:
    /// <summary>
    /// Returns the identity matrix.
    /// The identity matrix is a matrix with its diagonal
    /// set to one and everything else set to zero.
    /// </summary>
    [[nodiscard]]
    
    static Matrix Identity();

    /// <summary>
    /// Creates a matrix with all its values set to 0.
    /// </summary>
    constexpr Matrix() = default;

    /// <summary>
    /// Creates a matrix with all its values set to this default value.
    /// </summary>
    explicit constexpr Matrix(const float defaultValue);

    constexpr Matrix(
        const Vector4& r0,
        const Vector4& r1,
        const Vector4& r2,
        const Vector4& r3
    );

    constexpr Matrix(
        const float r00, const float r01, const float r02, const float r03,
        const float r10, const float r11, const float r12, const float r13,
        const float r20, const float r21, const float r22, const float r23,
        const float r30, const float r31, const float r32, const float r33
    );

    /// <summary>
    ///	Gets a pointer to the first value of this matrix.
    /// </summary>
    /// <returns>A pointer to the first value of this matrix.</returns>
    [[nodiscard]]
    
    constexpr const float* Raw() const;

    /// <summary>
    ///	Gets a pointer to the first value of this matrix.
    /// </summary>
    /// <returns>A pointer to the first value of this matrix.</returns>
    [[nodiscard]]
    
    constexpr float* Raw();

    /// <summary>
    /// Returns whether the matrix has everything except its diagonal set to zero.
    /// </summary>
    [[nodiscard]]
    bool IsDiagonal() const;
    
    /// <summary>
    /// Returns whether the matrix is the identity matrix.
    /// If this returns true, Matrix::Identity() == *this should be true.
    /// </summary>
    [[nodiscard]]
    bool IsIdentity() const;
    
    /// <summary>
    /// Returns whether this matrix has everything set to zero.
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
    /// but one of the sides is the opposite of the other.
    /// </summary>
    [[nodiscard]]
    bool IsAntisymmetric() const;
    
    /// <summary>
    /// Returns the diagonal elements of the matrix.
    /// </summary>
    [[nodiscard]]
    Vector4 Diagonal() const;
    
    /// <summary>
    /// Returns the sum of the diagonal elements of the matrix.
    /// </summary>
    [[nodiscard]]
    float Trace() const;
    
    /// <summary>
    /// Returns the determinant of this matrix.
    /// </summary>
    [[nodiscard]]
    float Determinant() const;
    
    /// <summary>
    /// Sets this matrix to the identity matrix.
    /// </summary>
    Matrix& LoadIdentity();
    
    /// <summary>
    /// Switches the matrix by its diagonal elements.
    /// </summary>
    Matrix& Transpose();

    /// <summary>
    /// Computes the invert of this matrix, e.g. <code>*this * Invert() == Identity()</code> is true.
    /// </summary>
    Matrix& Invert();

    /// <summary>
    /// Switches the given matrix by its diagonal elements.
    /// </summary>
    [[nodiscard]]
    static Matrix Transpose(const Matrix& matrix);
    
    /// <summary>
    /// Computes the inverse of the given matrix using the Gauss-Jordan pivot.
    /// </summary>
    [[nodiscard]]
    static Matrix Invert(const Matrix& matrix);
    
    /// <summary>
    /// Creates a 3D translation matrix from the given angle for each of the x, y, and z axis.
    /// </summary>
    [[nodiscard]]
    static Matrix Translation3D(const Vector3& translation);
    
    /// <summary>
    /// Creates a 3D rotation matrix from the given angle and axis.
    /// </summary>
	/// <param name="angle">The angle in radians.</param>
    [[nodiscard]]
    static Matrix Rotation3D(float angle, const Vector3& axis);
    
    /// <summary>
    /// Creates a 3D rotation matrix around the X axis from the given angle.
    /// </summary>
    /// <param name="angle">The angle in radians.</param>
    [[nodiscard]]
    static Matrix Rotation3DX(float angle);
    
    /// <summary>
    /// Creates a 3D rotation matrix around the X axis from the given angle.
    /// </summary>
    /// <param name="cos">The cosine of the angle in radians.</param>
    /// <param name="sin">The sine of the angle in radians.</param>
    [[nodiscard]]
    static Matrix Rotation3DX(float cos, float sin);
    
    /// <summary>
    /// Creates a 3D rotation matrix around the Y axis from the given angle.
    /// </summary>
    /// <param name="angle">The angle in radians.</param>
    [[nodiscard]]
    static Matrix Rotation3DY(float angle);
    
    /// <summary>
    /// Creates a 3D rotation matrix around the Y axis from the given angle.
    /// </summary>
    /// <param name="cos">The cosine of the angle in radians.</param>
    /// <param name="sin">The sine of the angle in radians.</param>
    [[nodiscard]]
    static Matrix Rotation3DY(float cos, float sin);
    
    /// <summary>
    /// Creates a 3D rotation matrix around the Z axis from the given angle.
    /// </summary>
    /// <param name="angle">The angle in radians.</param>
    [[nodiscard]]
    static Matrix Rotation3DZ(float angle);
    
    /// <summary>
    /// Creates a 3D rotation matrix around the Z axis from the given angle.
    /// </summary>
    /// <param name="cos">The cosine of the angle in radians.</param>
    /// <param name="sin">The sine of the angle in radians.</param>
    [[nodiscard]]
    static Matrix Rotation3DZ(float cos, float sin);
    
    /// <summary>
    /// Creates a 3D rotation matrix from the given angle for each of the x, y, and z axis.
    /// </summary>
    [[nodiscard]]
    static Matrix Rotation3D(const Vector3& rotation);
    
    [[nodiscard]]
    static Matrix Rotation3D(const Quaternion& rotation);
    
    /// <summary>
    /// Creates a 3D rotation matrix from the given cosine, sine and axis.
    /// </summary>
	/// <param name="cos">The cosine of the angle in radians.</param>
	/// <param name="sin">The sine of the angle in radians.</param>
    [[nodiscard]]
    static Matrix Rotation3D(float cos, float sin, const Vector3& axis);
    
    /// <summary>
    /// Creates a 3D scaling matrix from the given Vector3.
    /// </summary>
    [[nodiscard]]
    static Matrix Scaling3D(const Vector3& scale);
    
    /// <summary>
    /// Creates a Translation-Rotation-Scaling (TRS) matrix from the given translation, rotation and scaling.
    /// </summary>
    [[nodiscard]]
    static Matrix Trs(const Vector3& translation, const Vector3& rotation, const Vector3& scale);
    
    /// <summary>
    /// Creates a Translation-Rotation-Scaling (TRS) matrix from the given translation, rotation and scaling.
    /// </summary>
	/// <param name="rotationAngle">The angle in radians.</param>
    [[nodiscard]]
    static Matrix Trs(const Vector3& translation, float rotationAngle, const Vector3& axis, const Vector3& scale);
    
    /// <summary>
    /// Creates a Translation-Rotation-Scaling (TRS) matrix from the given translation, rotation and scaling.
    /// </summary>
    [[nodiscard]]
    static Matrix Trs(const Vector3& translation, const Matrix& rotation, const Vector3& scale);
    
    [[nodiscard]]
    static Matrix Trs(const Vector3& translation, const Quaternion& rotation, const Vector3& scale);
    
    static void View(const Vector3& eye, const Vector3& center, const Vector3& up, Matrix& result);
    
    static void PerspectiveProjection(float fov, float aspectRatio, float near, float far, Matrix& result);
    
    static void OrthographicProjection(float left, float right, float bottom, float top, float near, float far, Matrix& result);

    /// <summary>
    ///	Retrieves this matrix's row at index i.
    /// </summary>
    /// <param name="row">The index of the row to get.</param>
    /// <returns>The row at index i as a vector.</returns>
    [[nodiscard]]
    constexpr const Vector4& operator[](size_t row) const;
    
    /// <summary>
    ///	Retrieves this matrix's row at index i.
    /// </summary>
    /// <param name="row">The index of the row to get.</param>
    /// <returns>The row at index i as a vector.</returns>
    [[nodiscard]]
    constexpr Vector4& operator[](size_t row);
    
    explicit operator Vector4() const;

private:
    Vector4 r0, r1, r2, r3;
};

static_assert(std::is_default_constructible_v<Matrix>, "Class Matrix must be default constructible.");
static_assert(std::is_copy_constructible_v<Matrix>, "Class Matrix must be copy constructible.");
static_assert(std::is_move_constructible_v<Matrix>, "Class Matrix must be move constructible.");
static_assert(std::is_copy_assignable_v<Matrix>, "Class Matrix must be copy assignable.");
static_assert(std::is_move_assignable_v<Matrix>, "Class Matrix must be move assignable.");

[[nodiscard]]
Matrix operator-(const Matrix& matrix);

[[nodiscard]]
Matrix operator+(const Matrix& m1, const Matrix& m2);

[[nodiscard]]
Matrix operator-(const Matrix& m1, const Matrix& m2);

[[nodiscard]]
Matrix operator*(const Matrix& m, float scalar);

[[nodiscard]]
Matrix operator*(const Matrix& m1, const Matrix& m2);

Matrix& operator+=(Matrix& m1, const Matrix& m2);

Matrix& operator-=(Matrix& m1, const Matrix& m2);

Matrix& operator*=(Matrix& m, float scalar);

Matrix& operator*=(Matrix& m1, const Matrix& m2);

/// <summary>
///	Checks if two Matrices are considered equal using <code>calc::Equals</code>.
/// </summary>
[[nodiscard]]

bool operator==(Matrix a, Matrix b);

/// <summary>
///	Checks if two Matrices are considered different using <code>calc::Equals</code>.
/// </summary>
[[nodiscard]]

bool operator!=(Matrix a, Matrix b);

std::ostream& operator<<(std::ostream& out, const Matrix& m);

using mat4 = Matrix;
