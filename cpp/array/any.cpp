#include <cstddef>
#include <iostream>

struct ICloneable
{
  virtual ICloneable* clone() const = 0;
  virtual ~ICloneable() { }
};


template <typename T>
struct ValueHolder: ICloneable {
  T data_;

  ValueHolder(const T& data): data_(data) {}

  ValueHolder* clone() const {
    return new ValueHolder(*this);
  }

};

class Any {
public:
  ICloneable* obj;

  Any(): obj(0) {}

  template<class A>
  Any(const A& any) {
    obj = new ValueHolder<A>(any);
  }

  virtual ~Any() {
    delete obj;
  }

  Any(const Any& any) {
    if (any.obj == 0) {
      obj = 0;
    } else {
      obj = (any.obj)->clone();
    }
  }

  Any& operator=(const Any& any) {
    if (this != &any) {
      delete obj;
      obj = 0;
      if (any.obj != 0) {
        obj = (any.obj)->clone();
      }a
    }
    return *this;
  }

  template<class A>
  Any& operator=(const A& a) {
    delete obj;
    obj = new ValueHolder<A>(a);
    return *this;
  }

  template<typename A>
  A* cast() {
    if (obj != 0) {
      ValueHolder<A>* any = dynamic_cast< ValueHolder<A>* >(obj);
      if (any != 0) return &(any->data_);
    }
    return 0;
  }
};

