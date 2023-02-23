#include "matrix.hpp"
#include "vector3.hpp"

#include <cassert>
#include <iostream>

#define SQ(var) ((var) * (var))

#pragma region constructors
Matrix Matrix::Identity(const size_t rows, const size_t cols)
{
    Matrix result(rows, cols);
    if (rows == cols) [[likely]]
        for (size_t i = 0; i < rows; i++)
            result[i][i] = 1;
    else [[unlikely]]
        for (size_t i = 0; i < rows; i++)
            for (size_t j = 0; j < cols; j++)
                if (i == j)
                    result[i][j] = 1;
    return result;
}

Matrix Matrix::Identity(const Vector2 size)
{
    return Matrix::Identity((size_t) size.x, (size_t) size.y);
}

Matrix::Matrix(const size_t rows, const size_t cols, const float defaultValue)
    : mRows(rows), mCols(cols), mIsSquare(mRows == mCols)
{
    assert(mRows > 0 && mCols > 0 && "Invalid matrix size");
    __assume(mRows > 0 && mCols > 0);

    mData.resize(mRows);
    for (size_t i = 0; i < mRows; i++)
    {
        mData[i] = Vector(mCols);
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
        mData[i] = Vector(mCols);
        for (size_t j = 0; j < mCols; j++)
        {
            mData[i][j] = matrix.mData[i][j];
        }
    }
}
#pragma endregion

#pragma region functions
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

Vector Matrix::Diagonal() const
{
    Vector result(std::min(mRows, mCols));
    for (size_t i = 0; i < std::min(mRows, mCols); i++)
        result[i] = mData[i][i];
    return result;
}

float Matrix::Trace() const
{
    float result = 0.f;
    for (size_t i = 0; i < std::min(mRows, mCols); i++)
        result += mData[i][i];
    return result;
}

Matrix Matrix::SubMatrix(const size_t rowIndex, const size_t colIndex, const size_t rows, const size_t cols) const
{
    assert(rowIndex < mRows && colIndex < mCols && "Cannot submatrix out of bounds");
    assert(rows > 0 && cols > 0 && "Cannot submatrix of size 0");
    assert(colIndex + cols >= mCols && "Cannot overflow submatrix columns");
    __assume(rowIndex < mRows && colIndex < mCols);
    __assume(rows > 0 && cols > 0);
    __assume(colIndex + cols >= mCols);

    Matrix result(rows, cols);
    size_t overflow = rowIndex + rows - mRows;

    for (size_t i = 0; i < rows; i++)
        for (size_t j = 0; j < cols; j++)
        {
            if (i < overflow)
                result[i][j] = mData[i][colIndex + j];
            else
                result[i][j] = mData[rowIndex + i - overflow][colIndex + j];
        }
    return result;
}

float Matrix::Determinant() const
{
    assert(mIsSquare && "Cannot calculate the determinant of a non-square matrix");
    __assume(mIsSquare && mRows == mCols);

    if (mRows == 2 && mCols == 2)
    {
        return mData[0][0] * mData[1][1] - mData[0][1] * mData[1][0];
    }
    else
    {
        float result = 0.f;
        for (size_t i = 0; i < mRows; i++)
        {
            result += mData[i][0]
                * SubMatrix((i + 1) % mRows, 1, mRows - 1, mCols - 1).Determinant()
                * std::powf(-1.f, (float)i);
        }
        return result;
    }
}

Matrix &Matrix::Transpose(this Matrix& self)
{
    return self = Matrix::Transpose(self);
}

Matrix &Matrix::Augmented(this Matrix& self, const Matrix &other)
{
    return self = Matrix::Augmented(self, other);
}

Matrix &Matrix::GaussJordan(this Matrix& self)
{
    return self = Matrix::GaussJordan(self);
}

Matrix &Matrix::Inverse(this Matrix& self)
{
    return self = Matrix::Inverse(self);
}

Matrix Matrix::Transpose(const Matrix& matrix)
{
    const size_t rows = matrix.GetRows(), cols = matrix.GetCols();
    Matrix result(cols, rows);
    for (size_t i = 0; i < rows; i++)
        for (size_t j = 0; j < cols; j++)
            result[j][i] = matrix[i][j];
    return result;
}

Matrix Matrix::Augmented(const Matrix& m1, const Matrix& m2)
{
    assert(m1.GetRows() == m2.GetRows() && "Cannot augment matrices of different sizes");
    __assume(m1.GetRows() == m2.GetRows());

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

Matrix Matrix::GaussJordan(const Matrix &matrix)
{
    const size_t rows = matrix.GetRows(), cols = matrix.GetCols();
    Matrix result = matrix;
    
    // Last pivot rank
    size_t r = (size_t) -1;
    // j is the current column
    for (size_t j = 0; j < cols; j++)
    {
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
            result[k] /= value;

            if (k != r)
                // Swap k and r rows
                for (size_t i = 0; i < cols; i++)
                    std::swap(result[k][i], result[r][i]);

            for (size_t i = 0; i < rows; i++)
                if (i != r)
                    result[i] /= result[r] * result[i][j];
                    //for (size_t col = 0; col < cols; col++)
                        //result[i][col] -= result[r][col] * result[i][j];
        }

        if (r == rows - 1)
            break;
    }

    return result;
}

Matrix Matrix::Inverse(const Matrix &matrix)
{
    assert(matrix.IsSquare() && "Matrix must be square to get the inverse");
    __assume(matrix.IsSquare() && matrix.GetRows() == matrix.GetCols());
    Matrix m = matrix;
    // Get the non-identity half of the resulting matrix
    return Matrix::GaussJordan(m.Augmented(m, Matrix::Identity(matrix.GetRows(), matrix.GetCols()))).SubMatrix(0, matrix.GetCols(), matrix.GetRows(), matrix.GetCols());
}

Matrix Matrix::RotationMatrix2D(const float angle)
{
    return RotationMatrix2D(std::cos(angle), std::sin(angle));
}

Matrix Matrix::RotationMatrix2D(const float cos, const float sin)
{
    return {
        { cos, -sin,  0 },
        { sin,  cos,  0 },
        { 0,  0,  1 }
    };
}

Matrix Matrix::RotationMatrix3D(const float angle, const Vector3& axis)
{
    return RotationMatrix3D(std::cos(angle), std::sin(angle), axis);
}

Matrix Matrix::RotationMatrix3D(const float cos, const float sin, const Vector3 &axis)
{
    const float c2 = 1 - cos;

    return {
        { SQ(axis.x) * c2 + cos, axis.y * axis.x * c2 - axis.z * sin, axis.z * axis.x * c2 + axis.y * sin },
        { axis.x * axis.y * c2 - axis.z * sin, SQ(axis.y) * c2 + cos, axis.z * axis.y * c2 - axis.x * sin },
        { axis.x * axis.z * c2 - axis.y * sin, axis.y * axis.z * c2 + axis.x * sin, SQ(axis.z) * c2 + cos }
    };
}

Matrix Matrix::ScalingMatrix2D(const Vector2 scale)
{
    return {
        { scale.x,       0,       0 },
        {       0, scale.y,       0 },
        {       0,       0,       1 }
    };
}

Matrix Matrix::ScalingMatrix3D(const Vector3 &scale)
{
    return {
        { scale.x,       0,       0,       0 },
        {       0, scale.y,       0,       0 },
        {       0,       0, scale.z,       0 },
        {       0,       0,       0,       1 }
    };
}

Matrix Matrix::TRS(const Vector3& translation, const Matrix& rotation, const Vector3& scale)
{
    assert(rotation.GetRows() == 3 && rotation.GetCols() == 3 && "Rotation must be a 3x3 matrix");
    __assume(rotation.GetRows() == 3 && rotation.GetCols() == 3);

    Matrix result = Matrix::Identity(4, 4);

    result[0][3] = translation.x;
    result[1][3] = translation.y;
    result[2][3] = translation.z;

    for (size_t i = 0; i < 3; i++)
        for (size_t j = 0; j < 3; j++)
        {
            result[i][j] = rotation[i][j];
            if (i == j)
                result[i][j] *= scale[i];
        }

    return result;
}
#pragma endregion

#pragma region operators
Matrix &Matrix::operator=(const Matrix &matrix)
{
    std::memcpy(this, &matrix, sizeof(Matrix));
    return *this;
}

Matrix::operator Vector2() const
{
    assert((mRows == 2 && mCols == 1) || (mRows == 1 && mCols == 2) && "Matrix must be 2x1 or 1x2 for a cast to Vector2");
    __assume((mRows == 2 && mCols == 1) || (mRows == 1 && mCols == 2));

    if (mRows == 2)
        return { mData[0][0], mData[1][0] };
    else
        return { mData[0][0], mData[0][1] };
}

Matrix::operator Vector3() const
{
    assert((mRows == 3 && mCols == 1) || (mRows == 1 && mCols == 3) && "Matrix must be 3x1 or 1x3 for a cast to Vector3");
    __assume((mRows == 3 && mCols == 1) || (mRows == 1 && mCols == 3));

    if (mRows == 3)
        return { mData[0][0], mData[1][0], mData[2][0] };
    else
        return { mData[0][0], mData[1][0], mData[2][0] };
}

Matrix::operator Vector() const
{
    assert(mRows == 1 || mCols == 1 && "Matrix must be 3x1 or 1x3 for a cast to Vector3");
    __assume(mRows == 1 || mCols == 1);

    const bool rows = mCols == 1;
    if (!rows)
        return mData[0];

    const size_t vecSize = rows ? mRows : mCols;
    Vector result(vecSize);

    for (size_t i = 0; i < vecSize; i++)
        result[i] = mData[i][0];

    return result;
}

Matrix operator-(const Matrix& matrix)
{
    Matrix result = matrix;
    for (size_t i = 0; i < matrix.GetRows(); i++)
        result[i] = -matrix[i];
    return result;
}

Matrix operator+(const Matrix &m1, const Matrix &m2)
{
    const Vector2& size = m1.GetSize();
    assert(size == m2.GetSize() && "Cannot add matrices of different sizes");
    __assume(size == m2.GetSize());

    Matrix result(size);
    for (size_t i = 0; i < size.x; i++)
        result[i] = m1[i] + m2[i];
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
    __assume(size.y == m2.GetSize());

    Matrix result((size_t) size.x, m2.GetCols());
    const Vector2& resultSize = result.GetSize();

    // size.x == 2, size.y == 4
    for (size_t i = 0; i < resultSize.x; i++)
        for (size_t j = 0; j < resultSize.y; j++)
            for (size_t k = 0; k < size.y; k++)
                result[i][j] += m1[i][k] * m2[k][j];
    return result;
}

Matrix &operator+=(Matrix &m1, const Matrix &m2)
{
    return m1 = m1 + m2;
}

Matrix &operator-=(Matrix &m1, const Matrix &m2)
{
    return m1 = m1 - m2;
}

Matrix &operator*=(Matrix &m, const float scalar)
{
    return m = m * scalar;
}

Matrix &operator*=(Matrix &m1, const Matrix &m2)
{
    return m1 = m1 * m2;
}

std::ostream &operator<<(std::ostream &out, const Matrix &m)
{
    for (size_t i = 0; i < m.GetRows(); i++)
    {
        out << m[i];
        if (i != m.GetRows() - 1)
            out << "\n";
    }
    return out;
}
#pragma endregion
