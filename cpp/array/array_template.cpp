#include <cstddef>

template <typename T>
class Array
{
 public:
  explicit Array(size_t size = 0, const T& value = T()) {
    size_ = size;
    data_ = new T[size_];
    for (int i = 0; i < size_; ++i) {
      data_[i] = value;
    }    
  }

  Array(const Array& array) {
    size_ = array.size_;
    data_ = new T[size_];
    for (int i = 0; i < size_; ++i) {
      data_[i] = array.data_[i];
    }
  }
  
  ~Array() {
    delete[] data_;
    data_ = 0;
  }
  
  Array& operator=(const Array& array) {
    if (this != &array) {
      size_ = array.size_;
      delete[] data_;
      data_ = new T[size_];
      for (int i = 0; i < size_; ++i) {
        data_[i] = array.data_[i];
      }
    }
    return *this;
  }
  
  size_t size() const {
    return size_;
  }
  
  T& operator[](size_t i) {
    return data_[i];  
  }
  
  const T& operator[](size_t i) const {
    return data_[i];
  }
    
 private:
  T* data_;
  size_t size_;
};


