#pragma once

#include <vector>
#include "vector2.hpp"

namespace calc
{
    class Matrix
    {
    public:
        static Matrix Identity(const size_t rows, const size_t cols);

        /// @brief Creates a 1x1 null matrix
        Matrix() : Matrix(1, 1) {};
        Matrix(const size_t rows, const size_t cols, const float defaultValue = 0.f);
        Matrix(const Vector2 size, const float defaultValue = 0.f)
            : Matrix((size_t) size.x, (size_t) size.y, defaultValue) {}
        Matrix(std::initializer_list<std::initializer_list<float>>);
        Matrix(const Matrix& matrix);

        bool IsDiagonal() const;
        bool IsIdentity() const;
        bool IsNull() const;
        bool IsSymmetric() const;
        bool IsAntisymmetric() const;
        float GetTrace() const;
        Matrix SubMatrix(const size_t rowIndex, const size_t colIndex, const size_t rows, const size_t cols) const;
        float GetDeterminant() const;

        const std::vector<float>& operator[](const size_t row) const { return mData[row]; }
        std::vector<float>& operator[](const size_t row) { return mData[row]; }

        Vector2 GetSize() const { return Vector2((float) mRows, (float) mCols); }
        size_t GetRows() const { return mRows; }
        size_t GetCols() const { return mCols; }
        bool IsSquare() const { return mIsSquare; }

    private:
        std::vector<std::vector<float>> mData;
        const size_t mRows;
        const size_t mCols;
        bool mIsSquare;
    };

    Matrix Transpose(const Matrix& matrix);

    Matrix operator-(const Matrix& matrix);
    Matrix operator+(const Matrix& m1, const Matrix& m2);
    Matrix operator-(const Matrix& m1, const Matrix& m2);
    Matrix operator*(const Matrix& m, const float scalar);
    Matrix operator*(const Matrix& m1, const Matrix& m2);
}
