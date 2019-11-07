#include "dynarray.h"

DynArray& DynArray::operator=(const DynArray &rhs) {
  if (data_ != rhs.data_ ) {
      capacity_ = rhs.capacity_;
      size_ = rhs.size_;
      delete data_;
      data_ = new float[capacity_];
      for (int i = 0; i < rhs.size_; ++i) {
          data_[i] = rhs.data_[i];
      }
  }
}

DynArray::DynArray(const std::ptrdiff_t size) {
    if (size < 0) {
        throw std::invalid_argument("negative number in constructor");
    }

    data_ = new float[size];
    capacity_ = size;
    size_ = size;

    for (size_t i = 0; i < size; ++i) {
        data_[i] = 0;
    }
}

DynArray::DynArray(const DynArray& arr) {
    *this = arr;
}

float& DynArray::operator[](const std::ptrdiff_t i) {
    if (i >= size_ || i < 0) {
        throw std::invalid_argument("bad position");
    }

    return data_[i];
}

const float& DynArray::operator[](const std::ptrdiff_t i) const {
    if (i >= size_ || i < 0) {
        throw std::invalid_argument("bad position");
    }

    return data_[i];
}

void DynArray::transfer(const std::ptrdiff_t size) {
    float* new_data = new float[size];

    int now_size = 0;
    for (int i = 0; i < size && i < size_; ++i) {
        new_data[i] = data_[i];
        now_size++;
    }
    delete[] data_;

    while (now_size < size) {
        new_data[now_size] = 0;
        now_size++;
    }
    data_ = new_data;
}

void DynArray::resize(const std::ptrdiff_t size) {
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

void DynArray::push_back(const float val) {
    if (size_ == capacity_) {
        capacity_ = 2 * capacity_;
        transfer(capacity_);
    }

    data_[size_] = val;
    size_ += 1;
}

void DynArray::pop_back() {
    if (size_ == 0) {
        throw std::invalid_argument("size == 0 u cant pop");
    }

    size_ -= 1;
}

void DynArray::insert(const std::ptrdiff_t pos, const float val) {
    if (pos >= size_ || pos < 0) {
        throw std::invalid_argument("bad position");
    }

    if (size_ == capacity_) {
        capacity_ = 2 * capacity_;
        transfer(capacity_);
    }

    size_ += 1;
    float prev = data_[pos];
    data_[pos] = val;
    for (int i = pos + 1; i < size_; ++i) {
        float now = data_[i];
        data_[i] = prev;
        prev = now;

    }
}

float DynArray::erase(const std::ptrdiff_t pos) {
    if (pos >= size_ || pos < 0) {
        throw std::invalid_argument("bad position");
    }
    float res = data_[pos];
    for (int i = pos; i < size_ - 1; ++i) {
        data_[i] = data_[i + 1];
    }

    size_ -= 1;
    return res;
}

std::ostream& operator<<(std::ostream& out, const DynArray& arr) {
    for (size_t i = 0; i < arr.size(); ++i) {
        out << arr[i] << " ";
    }

    return out;
}
