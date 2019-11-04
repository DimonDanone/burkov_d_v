#include "matrixa.h"
#include <iostream>

template <class T>
MatrixA<T>::MatrixA(const std::ptrdiff_t col_count, const std::ptrdiff_t row_count) {
    data_ = std::make_unique<T[]>(n_row_ * n_col_);
}

template <class T>
MatrixA<T>::MatrixA(const MatrixA<T>& old) {
    *this = old;
}

template <class T>
MatrixA<T>& MatrixA<T>::operator=(const MatrixA<T> & old) {
    n_row_ = old.n_row_;
    n_col_ = old.n_col_;

    for (size_t i = 0; i < n_row_ * n_col_; ++i) {
        data_[i] = old.data_[i];
    }
}

template <class T>
const T& MatrixA<T>::at(const std::ptrdiff_t row_i, const std::ptrdiff_t col_i) const {
    if (col_i < 0 || row_i < 0 || row_i > n_row_ || col_i > n_col_) {
        throw std::invalid_argument("bad row or col index");
    }

    return data_[row_i * n_row_ + col_i * n_col_];
}

template <class T>
T& MatrixA<T>::at(const std::ptrdiff_t row_i, const std::ptrdiff_t col_i) {
    if (col_i < 0 || row_i < 0 || row_i > n_row_ || col_i > n_col_) {
        throw std::invalid_argument("bad row or col index");
    }

    return data_[row_i * n_row_ + col_i * n_col_];
}

template <class T>
MatrixA<T> operator+(const MatrixA<T>& first, const  MatrixA<T>& second) {
    if (first.row_count() != second.row_count() || first.col_count() != second.col_count()) {
        return std::invalid_argument("sizes are diff");
    }

    MatrixA<T> res(first.row_count(), second.col_count());
    for (size_t i = 0; i < first.row_count(); ++i) {
        for (size_t j = 0; j < first.col_count(); ++j) {
            res.at(i, j) = first.at(i, j) + second.at(i, j);
        }
    }

    return res;
}

template <class T>
MatrixA<T> operator-(const MatrixA<T>& first, const  MatrixA<T>& second) {
    if (first.row_count() != second.row_count() || first.col_count() != second.col_count()) {
        return std::invalid_argument("sizes are diff");
    }

    MatrixA<T> res(first.row_count(), second.col_count());
    for (size_t i = 0; i < first.row_count(); ++i) {
        for (size_t j = 0; j < first.col_count(); ++j) {
            res.at(i, j) = first.at(i, j) - second.at(i, j);
        }
    }

    return res;
}

template <class T>
MatrixA<T> operator*(const MatrixA<T>& first, const  MatrixA<T>& second) {
    if (first.row_count() != second.col_count() || first.col_count() != second.row_count()) {
        return std::invalid_argument("bad sizes for multiply");
    }

    MatrixA<T> res(first.row_count(), second.col_count());
    for (size_t i = 0; i < first.row_count(); ++i) {
        for (size_t j = 0; j < first.col_count(); ++j) {
            res.at(i, j) = first.at(i, j) * second.at(j, i);
        }
    }
}

template <class T>
MatrixA<T> MatrixA<T>::Transponse() {
    MatrixA<T> res(n_col_, n_row_);

    for (size_t i = 0; i < n_col_; ++i) {
        for (size_t j = 0; j < n_row_; ++j) {
            res.at(i, j) = at(j, i);
        }
    }

    return res;
}

template <class T>
std::ostream& operator<<(std::ostream& out, const MatrixA<T>& matrix) {
    for (size_t i = 0; i < matrix.row_count(); ++i) {
        for (int j = 0; j < matrix.col_count(); ++j) {
            out << matrix.at(i, j) << " ";
        }
        out << '\n';
    }

    return out;
}