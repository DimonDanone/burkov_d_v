#pragma once
#include <cstddef>
#include <iostream>

class DynArray {
public:
    DynArray() = default;
    DynArray(const DynArray& arr);
    explicit DynArray(const std::ptrdiff_t size);
    DynArray& operator=(const DynArray& rhs);
    ~DynArray() { delete[] data_; }
    std::ptrdiff_t size() const { return size_; }
    float& operator[](const std::ptrdiff_t i);
    const float& operator[](const std::ptrdiff_t i) const;
    void resize(const std::ptrdiff_t size);

    void push_back(const float val);
    void pop_back();
    void insert(const std::ptrdiff_t pos, const float val);
    float erase(const std::ptrdiff_t pos);

    const float* begin() const { return data_; }
    const float* end() const { return data_ + size_; }
    float* begin() { return data_; }
    float* end() { return data_ + size_; }

private:
    std::ptrdiff_t capacity_ = 0;
    std::ptrdiff_t size_ = 0;
    float* data_ = nullptr;

    void transfer(const std::ptrdiff_t size);

};

std::ostream& operator<<(std::ostream& out, const DynArray& arr);

//--------------------------------------------------------------------------

#ifndef DYNARRAY_DYNARRAY_H
#define DYNARRAY_DYNARRAY_H
#endif //DYNARRAY_DYNARRAY_H
