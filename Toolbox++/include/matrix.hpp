#pragma once

#include <vector>

namespace calc
{
    class Matrix
    {
    public:
        static const Matrix Zero;
        static const Matrix Identity;

        Matrix(const size_t rows, const size_t cols, const float defaultValue = 0.f);
        Matrix(const Matrix& matrix);

    private:
        std::vector<std::vector<float>> mData;
        const size_t mRows;
        const size_t mCols;
    };
}
