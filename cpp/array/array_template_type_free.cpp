#include <cstddef>
#include <iostream>

template <typename T>
class Array
{
public:
  explicit Array(size_t size, const T& value = T()) {
    size_ = size;

    data_ = (T*) new char[size_ * sizeof(T)];

    int i = 0;
    while (i < size_) {
      new (data_ + i) T(value);
      ++i;
    }
  }

  Array() {
    size_ = 0;
    data_ = 0;
  }

  Array(const Array& array) {
    size_ = array.size_;

    data_ = (T*) new char[size_ * sizeof(T)];

    int i = 0;
    while (i < size_) {
      new (data_ + i) T(*(array.data_ + i));
      ++i;
    }
  }

  ~Array() {
    free_memory();
  }

  void free_memory() {
    if (data_ != 0) {
      // delete objects
      int i = 0;
      while (i < size_) {
        (data_ + i)->~T();
        ++i;
      }
      // free memory
      delete [] (char*) data_;
      data_ = 0;
    }
  }

  Array& operator=(const Array& array) {
    if (this != &array) {
      size_ = array.size_;

      free_memory();

      data_ = (T*) new char[size_ * sizeof(T)];

      int i = 0;
      while (i < size_) {
        new (data_ + i) T(*(array.data_ + i));
        ++i;
      }
    }
    return *this;
  }

  size_t size() const {
    return size_;
  }

  T& operator[](size_t i) {
    return *(data_ + i);
  }

  const T& operator[](size_t i) const {
    return *(data_ + i);
  }

private:
  T* data_;
  size_t size_;
};

template <typename T>
void flatten(const T& array, std::ostream& out) {
    out << array << ' ';
}

template <typename T>
void flatten(const Array<T>& array, std::ostream& out) {
  size_t n = array.size();
  for (size_t i = 0; i < n; ++i) {
    flatten(array[i], out);
  }
}

