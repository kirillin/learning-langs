#include <iostream>
//#include "array_template.cpp"
#include "array_template_type_free.cpp"
#include "any.cpp"


using namespace std;

class Int {
public:
  int a;
  Int(int a): a(a) {}

  Int(const Int& obj) {
    a = obj.a;
  }

  ~Int() {}

  void print() {
    cout << a << endl;
  }
};


int main() {

  Any a;
  Any b(5);
  Any c(3.14);
  Any d('r');
  a = b;
  d = c;
  Any* e = new Any(Array<int>(2,2));
  int* f = (new Any(11))->cast<int>();
  cout << *f;

  Array<int> ints(2, 0);
  ints[0] = 13;
  ints[1] = 42;
  flatten(ints, std::cout); // 13 42

  Array<Array<int>> array_of_ints(2, ints);
  flatten(array_of_ints, std::cout); // 13 42 13 42

  Array<int> a1;

  int c = 13;
  Array<int> a2(5, c);
  a1 = a2;

  Array<int> a1(5);
  Array<int> a2(5);
  a1 = a2;
  Array<int> a3 = a2;

  return 0;
}
