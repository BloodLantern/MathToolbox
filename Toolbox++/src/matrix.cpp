#include "matrix.hpp"

#include <cassert>
#include <iostream>

namespace calc
{
    Matrix Matrix::Identity(const size_t rows, const size_t cols)
    {
        Matrix result(rows, cols);
        if (rows == cols)
            for (size_t i = 0; i < rows; i++)
                result[i][i] = 1;
        else
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

    float Matrix::Trace() const
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

        Matrix result(rows, cols);

        for (size_t i = 0; i < rows; i++)
            for (size_t j = 0; j < cols; j++)
                result[i][j] = mData[(rowIndex + i) % mRows][(colIndex + j) % mCols];
        return result;
    }

    float Matrix::Determinant() const
    {
        assert(mIsSquare && "Cannot calculate the determinant of a non-square matrix");

        if (mRows == 2 && mCols == 2)
        {
            return mData[0][0] * mData[1][1] - mData[0][1] * mData[1][0];
        }
        else
        {
            float result = 0.f;
            for (size_t i = 0; i < mRows; i++)
                result += SubMatrix(i, 1, mRows - 1, mCols - 1).Determinant();
            return result;
        }
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

    Matrix Augmented(const Matrix& m1, const Matrix& m2)
    {
        assert(m1.GetRows() == m2.GetRows() && "Cannot augment matrices of different sizes");
        const size_t m1Rows = m1.GetRows(), m1Cols = m1.GetCols(),
            m2Cols = m2.GetCols(),
            resultCols = m1Cols + m2Cols;
        Matrix result(m1Rows, resultCols);

        for (size_t i = 0; i < m1Rows; i++)
        {
            for (size_t j = 0; j < m1Cols; j++)
                result[i][j] = m1[i][j];
            for (size_t j = 0; j < m2Cols; j++)
                result[i][m1Cols + j] = m2[i][j];
        }

        return result;
    }

    Matrix GaussJordan(const Matrix &m1, const Matrix &m2)
    {
        const size_t rows = m1.GetRows(), resultCols = m1.GetCols() + m2.GetCols();
        Matrix result = Augmented(m1, m2);
        std::cout << "m1: " << m1 << std::endl;
        std::cout << "m2: " << m2 << std::endl;
        
        // Last pivot rank
        size_t r = (size_t) -1;
        // j is the current column
        for (size_t j = 0; j < resultCols; j++)
        {
            std::cout << "j = " << j << std::endl;
            std::cout << "r = " << r << std::endl;
            std::cout << "result1: " << result << std::endl;
            // Max value row index
            size_t k = 0;
            {
                float maxValue = 0;
                for (size_t i = r + 1; i < rows; i++)
                {
                    float value = std::abs(result[i][j]);
                    if (value == 1)
                    {
                        k = i;
                        break;
                    }

                    if (value > maxValue)
                    {
                        maxValue = value;
                        k = i;
                    }
                }
            }

            float value = result[k][j];
            if (value != 0)
            {
                // r is the next pivot row index
                r++;
                // Normalize the pivot's row
                for (size_t i = 0; i < resultCols; i++)
                    result[k][i] /= value;
                std::cout << "result2: " << result << std::endl;

                if (k != r)
                    // Swap k and r rows
                    for (size_t i = 0; i < resultCols; i++)
                        std::swap(result[k][i], result[r][i]);
                std::cout << "result3: " << result << std::endl;

                for (size_t i = 0; i < rows; i++)
                    if (i != r)
                        for (size_t col = 0; col < resultCols; col++)
                            result[i][col] -= result[r][col] * result[i][j];
                std::cout << "result4: " << result << std::endl;
            }

            if (r == rows - 1)
                break;
        }

        return result;
    }

    Matrix GaussJordan(const Matrix &matrix)
    {
        return GaussJordan(matrix, Matrix::Identity(matrix.GetRows(), matrix.GetCols()));
    }

    Matrix Inverse(const Matrix &matrix)
    {
        // Get the non-identity half of the resulting matrix
        return GaussJordan(matrix).SubMatrix(0, matrix.GetCols(), matrix.GetRows(), matrix.GetCols() * 2);
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
        return m1 + (-m2);
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
    std::ostream &operator<<(std::ostream &out, const Matrix &m)
    {
        out << "{ ";
        for (size_t i = 0; i < m.GetRows(); i++)
        {
            out << "\n  { ";
            for (size_t j = 0; j < m.GetCols(); j++)
            {
                char buffer[10];
                sprintf_s(buffer, sizeof(buffer), "%6.3f", m[i][j]);
                out << buffer;
                if (j != m.GetCols() - 1)
                    out << ", ";
                else
                    out << " ";
            }
            out << "}";
        }
        return out << "\n}";
    }
}
