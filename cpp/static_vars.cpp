#include <iostream>

using namespace std;

void some_foo(int n) {
  static int some_var = 42; // !!! инициализируется только при первом запуске функции
                            // поумолчанию инициализируется 0
  cout << some_var << endl; // существует всегда после вызова и хранит предыдущее значение
  some_var = n;
}

int main2() {
  some_foo(1);  // cout 0
  some_foo(2);  // cout 1
  some_foo(3);  // cout 2
  some_foo(4);  // cout 3
                // :)
  return 0;
}