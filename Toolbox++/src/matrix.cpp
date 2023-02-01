#include "matrix.hpp"

#include <cassert>

calc::Matrix::Matrix(const size_t rows, const size_t cols, const float defaultValue)
    : mRows(rows), mCols(cols)
{
    assert(mRows > 0);
    assert(mCols > 0);

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

calc::Matrix::Matrix(const Matrix &matrix)
    : mRows(matrix.mRows), mCols(matrix.mCols)
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
