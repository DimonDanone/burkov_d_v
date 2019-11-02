#include <cstddef>
#include <iostream>

template <class T>
class DynArray {
public:
    DynArray() = default;
    DynArray(const DynArray& arr);
    explicit DynArray(const std::ptrdiff_t size);
    DynArray& operator=(const DynArray& rhs);
    ~DynArray() { delete[] data_; }
    std::ptrdiff_t size() const { return size_; }
    T& operator[](const std::ptrdiff_t i);
    const T& operator[](const std::ptrdiff_t i) const;
    void resize(const std::ptrdiff_t size);

    void push_back(const T val);
    void pop_back();
    void insert(const std::ptrdiff_t pos, const T val);
    void erase(const std::ptrdiff_t pos);

    const T* begin() const { return data_; }
    const T* end() const { return data_ + size_; }
    T* begin() { return data_; }
    T* end() { return data_ + size_; }

private:
    std::ptrdiff_t capacity_ = 0;
    std::ptrdiff_t size_ = 0;
    T* data_ = nullptr;

    void transfer(const std::ptrdiff_t size);

};

#ifndef DYNARRAY_DYNARRAY_H
#define DYNARRAY_DYNARRAY_H
#endif //DYNARRAY_DYNARRAY_H