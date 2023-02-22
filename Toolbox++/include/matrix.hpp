#pragma once

#include <vector>
#include "vector2.hpp"
#include "vector3.hpp"

class Matrix
{
public:
    static Matrix Identity(const size_t rows, const size_t cols);

    /// @brief Creates a 1x1 null matrix
    Matrix() : Matrix(1, 1) {};
    Matrix(const size_t rows, const size_t cols = 1, const float defaultValue = 0.f);
    Matrix(const Vector2 size, const float defaultValue = 0.f)
        : Matrix((size_t) size.x, (size_t) size.y, defaultValue) {}
    Matrix(const Matrix& matrix);
    constexpr Matrix(const std::initializer_list<std::vector<float>> data)
        : mData(data), mRows(data.size()), mCols(data.begin()[0].size()), mIsSquare(mRows == mCols) {}

    [[nodiscard]] bool IsDiagonal() const;
    [[nodiscard]] bool IsIdentity() const;
    [[nodiscard]] bool IsNull() const;
    [[nodiscard]] bool IsSymmetric() const;
    [[nodiscard]] bool IsAntisymmetric() const;
    [[nodiscard]] Matrix Diagonal() const;
    [[nodiscard]] float Trace() const;
    [[nodiscard]] Matrix SubMatrix(const size_t rowIndex, const size_t colIndex, const size_t rows, const size_t cols) const;
    [[nodiscard]] float Determinant() const;
    Matrix& Transpose();
    Matrix& Augmented(const Matrix& other);

    [[nodiscard]] const std::vector<float>& operator[](const size_t row) const { return mData[row]; }
    [[nodiscard]] std::vector<float>& operator[](const size_t row) { return mData[row]; }
    Matrix& operator=(const Matrix& matrix);
    operator Vector2();
    operator Vector3();

    [[nodiscard]] Vector2 GetSize() const { return Vector2((float) mRows, (float) mCols); }
    [[nodiscard]] size_t GetRows() const { return mRows; }
    [[nodiscard]] size_t GetCols() const { return mCols; }
    [[nodiscard]] bool IsSquare() const { return mIsSquare; }

    [[nodiscard]] static Matrix Transpose(const Matrix& matrix);
    [[nodiscard]] static Matrix Augmented(const Matrix& m1, const Matrix& m2);
    [[nodiscard]] static Matrix GaussJordan(const Matrix& m1, const Matrix& m2);
    [[nodiscard]] static Matrix GaussJordan(const Matrix& matrix);
    [[nodiscard]] static Matrix Inverse(const Matrix& matrix);
    [[nodiscard]] static Matrix RotationMatrix2D(const float angle);
    // Currently doesn't work
    [[nodiscard]] static Matrix RotationMatrix3D(const float angle, const Vector3& axis);
    [[nodiscard]] static Matrix ScalingMatrix2D(const Vector2 scale);
    [[nodiscard]] static Matrix ScalingMatrix3D(const Vector3& scale);
    [[nodiscard]] static Matrix TRS(const Vector3& translation, const Matrix& rotation, const Vector3& scale);

	[[nodiscard]] friend auto operator<=>(const Matrix& a, const Matrix& b) = default;

private:
    std::vector<std::vector<float>> mData;
    const size_t mRows;
    const size_t mCols;
    const bool mIsSquare;
};

[[nodiscard]] Matrix operator-(const Matrix& matrix);
[[nodiscard]] Matrix operator+(const Matrix& m1, const Matrix& m2);
[[nodiscard]] Matrix operator-(const Matrix& m1, const Matrix& m2);
[[nodiscard]] Matrix operator*(const Matrix& m, const float scalar);
[[nodiscard]] Matrix operator*(const Matrix& m1, const Matrix& m2);

Matrix& operator+=(Matrix& m1, const Matrix& m2);
Matrix& operator-=(Matrix& m1, const Matrix& m2);
Matrix& operator*=(Matrix& m, const float scalar);
Matrix& operator*=(Matrix& m1, const Matrix& m2);

std::ostream& operator<<(std::ostream& out, const Matrix& m);
