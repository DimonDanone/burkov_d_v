#include "matrixa.h"
#include <iostream>

MatrixA::MatrixA(const std::ptrdiff_t col_count, const std::ptrdiff_t row_count) {
    if (col_count <= 0 || row_count <= 0) {
        throw std::invalid_argument("bad row or col count");
    }

    n_col_ = col_count;
    n_row_ = row_count;
    data_ = std::make_unique<float[]>(n_row_ * n_col_);

    for (size_t i = 0; i < n_row_ * n_col_; ++i) {
        data_[i] = 0;
    }
}

MatrixA::MatrixA(const MatrixA& old) {
    *this = old;
}

MatrixA& MatrixA::operator=(const MatrixA& old) {
    n_row_ = old.n_row_;
    n_col_ = old.n_col_;

    for (size_t i = 0; i < n_row_ * n_col_; ++i) {
        data_[i] = old.data_[i];
    }
}

const float& MatrixA::at(const std::ptrdiff_t row_i, const std::ptrdiff_t col_i) const {
    if (col_i < 0 || row_i < 0 || row_i >= n_row_ || col_i >= n_col_) {
        throw std::invalid_argument("bad row or col index");
    }

    return data_[row_i * (n_row_ + 1) + col_i];
}

float& MatrixA::at(const std::ptrdiff_t row_i, const std::ptrdiff_t col_i) {
    if (col_i < 0 || row_i < 0 || row_i >= n_row_ || col_i >= n_col_) {
        throw std::invalid_argument("bad row or col index");
    }

    return data_[row_i * (n_row_ + 1) + col_i];
}

MatrixA operator+(const MatrixA& first, const  MatrixA& second) {
    if (first.row_count() != second.row_count() || first.col_count() != second.col_count()) {
        throw std::invalid_argument("sizes are diff");
    }

    MatrixA res(first.row_count(), second.col_count());
    for (size_t i = 0; i < first.row_count(); ++i) {
        for (size_t j = 0; j < first.col_count(); ++j) {
            res.at(i, j) = first.at(i, j) + second.at(i, j);
        }
    }

    return res;
}

MatrixA operator-(const MatrixA& first, const  MatrixA& second) {
    if (first.row_count() != second.row_count() || first.col_count() != second.col_count()) {
        throw std::invalid_argument("sizes are diff");
    }

    MatrixA res(first.row_count(), second.col_count());
    for (size_t i = 0; i < first.row_count(); ++i) {
        for (size_t j = 0; j < first.col_count(); ++j) {
            res.at(i, j) = first.at(i, j) - second.at(i, j);
        }
    }

    return res;
}

MatrixA operator*(const MatrixA& first, const  MatrixA& second) {
    if (first.row_count() != second.col_count() || first.col_count() != second.row_count()) {
        throw std::invalid_argument("bad sizes for multiply");
    }

    MatrixA res(first.row_count(), second.col_count());
    for (size_t i = 0; i < first.row_count(); ++i) {
        for (size_t j = 0; j < first.col_count(); ++j) {
            res.at(i, j) = first.at(i, j) * second.at(j, i);
        }
    }
}

MatrixA MatrixA::Transponse() {
    MatrixA res(n_col_, n_row_);

    for (size_t i = 0; i < n_col_; ++i) {
        for (size_t j = 0; j < n_row_; ++j) {
            res.at(i, j) = at(j, i);
        }
    }

    return res;
}

std::ostream& operator<<(std::ostream& out, const MatrixA& matrix) {
    for (size_t i = 0; i < matrix.row_count(); ++i) {
        for (int j = 0; j < matrix.col_count(); ++j) {
            out << matrix.at(i, j) << " ";
        }
        out << '\n';
    }

    return out;
}
