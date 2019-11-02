#include "dynarray.h"

template <class T>
DynArray<T>& DynArray<T>::operator=(const DynArray <T> &rhs) {
    capacity_ = rhs.capacity_;
    size_ = rhs.size_;
    delete data_;
    data_ = new T[capacity_];
    for (int i = 0; i < rhs.size_; ++i) {
        data_[i] = rhs.data_[i];
    }
}

template <class T>
DynArray<T>::DynArray(const std::ptrdiff_t size) {
    if (size < 0) {
        throw std::invalid_argument("negative number in constructor");
    }
    capacity_ = size;
    size_ = size;
    data_ = new T[size];
}

template <class T>
DynArray<T>::DynArray(const DynArray <T> &arr) {
    *this = arr;
}

template <class T>
T& DynArray<T>::operator[](const std::ptrdiff_t i) {
    if (i >= size_ || i < 0) {
        throw std::invalid_argument("bad position");
    }

    return data_[i];
}

template <class T>
const T& DynArray<T>::operator[](const std::ptrdiff_t i) const {
    if (i >= size_ || i < 0) {
        throw std::invalid_argument("bad position");
    }

    return data_[i];
}


template <class T>
void DynArray<T>::transfer(const std::ptrdiff_t size) {
    T *new_data = new T[size];

    int now_size = 0;
    for (int i = 0; i < size && i < size_; ++i) {
        new_data[i] = data_[i];
        now_size++;
    }
    delete[] data_;

    while (now_size < size) {
        new_data[now_size - 1] = 0;
        now_size++;
    }
    data_ = new_data;
}

template <class T>
void DynArray<T>::resize(const std::ptrdiff_t size) {
    if (size < 0) {
        throw std::invalid_argument("negative number in constructor");
    }

    if (size > capacity_) {
        capacity_ = size;
        transfer(size);
    } else {
        int now_size = size_;
        while (now_size < size) {
            data_[now_size - 1] = 0;
            now_size++;
        }
    }

    size_ = size;
}

template <class T>
void DynArray<T>::push_back(const T val) {
    if (size_ == capacity_) {
        capacity_ = 2 * capacity_;
        resize(capacity_);
    }

    data_[size_] = val;
    size_ += 1;
}

template <class T>
void DynArray<T>::pop_back() {
    if (size_ == 0) {
        throw std::invalid_argument("size == 0 u cant pop");
    }

    size_ -= 1;
}

template <class T>
void DynArray<T>::insert(const std::ptrdiff_t pos, const T val) {
    if (pos >= size_ || pos < 0) {
        throw std::invalid_argument("bad position");
    }

    if (size_ == capacity_) {
        capacity_ = 2 * capacity_;
        resize(capacity_);
    }

    size_ += 1;
    T prev = data_[pos];
    data_[pos] = val;
    for (int i = pos + 1; i < size_; ++i) {
        T now = data_[i];
        data_[i] = prev;
        prev = now;

    }
}

template <class T>
void DynArray<T>::erase(const std::ptrdiff_t pos) {
    if (pos >= size_ || pos < 0) {
        throw std::invalid_argument("bad position");
    }

    for (int i = pos; i < size_ - 1; ++i) {
        data_[i] = data_[i + 1];
    }

    size_ -= 1;
}