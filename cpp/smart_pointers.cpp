#include <iostream>

using namespace std;

class Number {
  private:
    int num;
    
  public:
    Number(int num): num(num) {}
    
    ~Number() {}
    
    int get() {
      return num;
    }
};


class ScopedPtr {
  private:
    Number *pObj;
    
    // deny to copy of the objects
    ScopedPtr(const ScopedPtr&);
    ScopedPtr& operator=(const ScopedPtr&);
    
  public:
    explicit ScopedPtr(Number *pObj = 0): pObj(pObj) {}
    ~ScopedPtr() {
      if (!this->isNull()) delete pObj;
    }
    
    Number& operator*() {
      return *pObj;
    }
  
    Number* operator->() {
      return pObj;
    }
  
    bool isNull() {
      return (pObj == 0);
    }    
};


class Storage {
  public: // it wants to be private
    Storage(Number *pObj = 0): pObj(pObj) {}
    ~Storage() {
      delete pObj;
    }
    
    Number *pObj;
    int count;
};

class SharedPtr {
  private:
    Storage *st;

  public:
    SharedPtr(Number *pObj = 0) {
      st = new Storage(pObj);
      st->count = 1;
    }

    SharedPtr(const SharedPtr& shp) {
      st = shp.getStorage();
    }
    
    ~SharedPtr() {
      if (st->count == 0) {
        delete st;
      } else {
        --(st->count);
      }
    }

    SharedPtr& operator=(const SharedPtr& sptr) {
      st = sptr.getStorage;
      return *this;
    }

    Storage* getStorage() const {
      return this->st;
    }


    Number* get() {
      return st->pObj;
    }    
    
    


};

int main() {

  Number *num = new Number(7);
  cout << num << ' ' << num->get() << endl;

  {
    ScopedPtr sp(num);
    //ScopedPtr sp = num;           // error: constructor is emplicit
    cout << sp->get() << endl;      // 7
    cout << (*sp).get() << endl;    // 7
  }

  {
    SharedPtr shp = new Number(13);
    SharedPtr shp1 = shp;

  }

  return 0;
}
