#include <cstddef>
#include <memory>

class MatrixA {
public:
    MatrixA() = default;
    MatrixA(const MatrixA&);
    MatrixA(const std::ptrdiff_t col_count, const std::ptrdiff_t row_count);
    ~MatrixA() = default;
    MatrixA& operator=(const MatrixA&);

    //MatrixA(MatrixA&&) = default;
    //MatrixA& operator=(MatrixA&&) = default;

    std::ptrdiff_t row_count() const { return n_row_;}
    std::ptrdiff_t col_count() const { return n_col_;}
    float& at(const std::ptrdiff_t row_i, const std::ptrdiff_t col_i);
    const float& at(const std::ptrdiff_t row_i, const std::ptrdiff_t col_i) const;
    MatrixA Transponse();

private:
    std::ptrdiff_t n_row_ = 0;
    std::ptrdiff_t n_col_ = 0;
    std::unique_ptr<float[]> data_;

};

MatrixA operator+(const MatrixA& first, const  MatrixA& second);
MatrixA operator-(const MatrixA& first, const  MatrixA& second);
MatrixA operator*(const MatrixA& first, const  MatrixA& second);

std::ostream& operator<<(std::ostream& out, const MatrixA& matrix);

#ifndef MATRIXA_MATRIXA_H
#define MATRIXA_MATRIXA_H

#endif //MATRIXA_MATRIXA_H
