#include "matrix.hpp"

#include <cassert>

namespace calc
{
    Matrix Matrix::Identity(const size_t rows, const size_t cols)
    {
        Matrix result(rows, cols);
        for (size_t i = 0; i < rows; i++)
            for (size_t j = 0; j < cols; j++)
                if (i == j)
                    result[i][j] = 1;
        return result;
    }

    Matrix::Matrix(const size_t rows, const size_t cols, const float defaultValue)
        : mRows(rows), mCols(cols)
    {
        assert(mRows > 0 && mCols > 0 && "Invalid matrix size");

        mIsSquare = mRows == mCols;

        mData.resize(mRows);
        for (size_t i = 0; i < mRows; i++)
        {
            mData[i].resize(mCols);
            for (size_t j = 0; j < mCols; j++)
            {
                mData[i][j] = defaultValue;
            }
        }
    }

    Matrix::Matrix(std::initializer_list<std::initializer_list<float>> data)
        : mData(data), mRows(mData.size()), mCols(mData[0].size())
    {
    }

    Matrix::Matrix(const Matrix &matrix)
        : mRows(matrix.mRows), mCols(matrix.mCols), mIsSquare(matrix.mIsSquare)
    {
        mData.resize(mRows);
        for (size_t i = 0; i < mRows; i++)
        {
            mData[i].resize(mCols);
            for (size_t j = 0; j < mCols; j++)
            {
                mData[i][j] = matrix.mData[i][j];
            }
        }
    }

    bool Matrix::IsDiagonal() const
    {
        // A matrix can't be diagonal if it isn't a square matrix
        if (!mIsSquare)
            return false;

        for (size_t i = 0; i < mRows; i++)
            for (size_t j = 0; j < mCols; j++)
                if (i != j && mData[i][j] != 0)
                    return false;
        return true;
    }

    bool Matrix::IsIdentity() const
    {
        if (!IsDiagonal())
            return false;

        for (size_t i = 0; i < mRows; i++)
            if (mData[i][i] != 1)
                return false;
        return true;
    }

    bool Matrix::IsNull() const
    {
        if (!IsDiagonal())
            return false;

        for (size_t i = 0; i < mRows; i++)
            if (mData[i][i] != 0)
                return false;
        return true;
    }

    bool Matrix::IsSymmetric() const
    {
        if (!mIsSquare)
            return false;

        for (size_t i = 0; i < mRows; i++)
            for (size_t j = i + 1; j < mRows; j++)
                if (mData[i][j]!= mData[j][i])
                    return false;
        return true;
    }

    bool Matrix::IsAntisymmetric() const
    {
        if (!mIsSquare)
            return false;

        for (size_t i = 0; i < mRows; i++)
            for (size_t j = 0; j < mCols; j++)
                if (mData[i][j] != -mData[j][i])
                    return false;
        return true;
    }

    float Matrix::GetTrace() const
    {
        float result = 0.f;
        for (size_t i = 0; i < mRows; i++)
            for (size_t j = 0; j < mCols; j++)
                result += mData[i][j];
        return result;
    }

    Matrix Matrix::SubMatrix(const size_t rowIndex, const size_t colIndex, const size_t rows, const size_t cols) const
    {
        assert(rowIndex < mRows && colIndex < mCols && "Cannot submatrix out of bounds");
        assert(rows > 0 && cols > 0 && "Cannot submatrix of size 0");

        const size_t rowCount = rowIndex + rows, colCount = colIndex + cols;
        Matrix result(rowCount, colCount);

        for (size_t i = 0; i < rowCount; i++)
            for (size_t j = 0; j < colCount; j++)
                result[i][j] = mData[(rowIndex + i) % mRows][(colIndex + j) % mCols];
        return result;
    }

    float Matrix::GetDeterminant() const
    {
        float result = 0.f;
        for (size_t i = 0; i < mRows; i++)
            result += SubMatrix(i, 1, mRows - 1, mCols - 1).GetDeterminant();
        return result;
    }

    Matrix Transpose(const Matrix& matrix)
    {
        const size_t rows = matrix.GetRows(), cols = matrix.GetCols();
        Matrix result(cols, rows);
        for (size_t i = 0; i < rows; i++)
            for (size_t j = 0; j < cols; j++)
                result[j][i] = matrix[i][j];
        return result;
    }

    Matrix operator-(const Matrix& matrix)
    {
        Matrix result = matrix;
        for (size_t i = 0; i < matrix.GetRows(); i++)
            for (size_t j = 0; j < matrix.GetCols(); j++)
                result[i][j] = -matrix[i][j];
        return result;
    }

    Matrix operator+(const Matrix &m1, const Matrix &m2)
    {
        const Vector2& size = m1.GetSize();
        assert(size == m2.GetSize() && "Cannot add matrices of different sizes");

        Matrix result(size);
        for (size_t i = 0; i < size.x; i++)
            for (size_t j = 0; j < size.y; j++)
                result[i][j] = m1[i][j] + m2[i][j];
        return result;
    }

    Matrix operator-(const Matrix &m1, const Matrix &m2)
    {
        const Vector2& size = m1.GetSize();
        assert(size == m2.GetSize() && "Cannot substract matrices of different sizes");

        Matrix result(size);
        for (size_t i = 0; i < size.x; i++)
            for (size_t j = 0; j < size.y; j++)
                result[i][j] = m1[i][j] - m2[i][j];
        return result;
    }

    Matrix operator*(const Matrix &m, const float scalar)
    {
        const Vector2& size = m.GetSize();
        Matrix result(size);
        for (size_t i = 0; i < size.x; i++)
            for (size_t j = 0; j < size.y; j++)
                result[i][j] = m[i][j] * scalar;
        return result;
    }

    Matrix operator*(const Matrix &m1, const Matrix &m2)
    {
        const Vector2& size = m1.GetSize();
        assert(size.y == m2.GetRows() && "Cannot multiply matrices of incompatible sizes");
        Matrix result((size_t) size.x, m2.GetCols());
        for (size_t i = 0; i < size.x; i++)
            for (size_t j = 0; j < size.y; j++)
                result[i][j] = m1[i][j] * m2[i][j];
        return result;
    }
}
