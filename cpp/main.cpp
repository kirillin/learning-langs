#include <iostream>

using namespace std;

int& getx(int& x) {
  int a = 42;
  return a;
}

int main2(){
    int x = 13;
    getx(x) = 42;
//    int l = getx1(x);
    cout << x << endl;
    return 0;
}
