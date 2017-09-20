/*
 * Классы памяти локальных переменных:
 *   автоматический -- локальные переменные (тело функции, тело цикла и проч.)
 *   static -- глобальные переменные (прост в файле)
 *
 * Глобальные и статические локальные переменные автоматически инициализируются дефолтными значениями.
 *
 */
#include <iostream>
#include <iomanip>

using namespace std;

int variable; // сама инициализируется нулем. + висит в памяти до конца жизни программы

struct Position {
  float x;
  float y;
  float z;
};

// прототипы функций + пример перегрузки функций
void getSum();
float getSum(int, int, int); // передача аргументов по значению
float getSum(float, float);
//float getSum(float num1, float num2); // то же, что и предыдущий прототип. Разницы нет

// + примеры возвращения функциями нескольких переменных
Position getPosition(float x, float y, float z); // возвращение нескольких переменных обернутых в структуру
void computePi(float& pi, float l, float r); // передача аргументов по ссылке (одновременно и возвращение)
void computePi(float& pi, float l = 12*3.1415F, float r = 12); // аргумнты по умолчанию
//void computePi(float& pi, float = 12*3.1415F, float = 12); // аргумнты по умолчанию без имен переменных

// Встраиваемая функция. Аналог в С #define.
// Предпочтительней, чем СИшный define, так как нет проблем с типизацией.
// Директива inline только намекает компилятору, что неплохо бы
//  эту функцию сделать встраиваемой, но решать компилятору.
// Функция должна быть как можно короче!
inline float mmToM(int mm) {
  return mm / 1000.0F;
}

unsigned long factorial(int n);

// передеча аргумента по ссылке без возможности изменять значение исходного аргумента
void some_foo(const int& x) {
  int a = x + 3;
}

// возвращение переменной из фунции по ссылке
int& getx(int& x) {
  return x;
}

int main1() {
  int variable_local; // не инициализируется сама + в памяти лежит только пока выполняется функция
  static int static_varible_local; // в памяти лежит с начала выполнения функции
                                    // до конца жизни программы. Инициализируется сама.

  cout << "2.0 + 2.1 = " << getSum(2.0, 2.1) << endl;
  cout << "2 + 2 + 1 = " << getSum(2, 2, 1) << endl;
  getSum(); // Ooops! Dont work...

  // 1 способ возвращение функцией нескольких переменных
  Position pos = getPosition(1, 2, 3);
  cout << "pos = " << pos.x << setw(3) << pos.y << setw(3) << pos.z << endl;

  // передача аргументов по ссылке + оно же, возвращение
  float pi = 0;
  computePi(pi, 12 * 3.14F, 12);
  cout << "pi = " << pi << endl;  // pi = 3.14
  computePi(pi);
  cout << "pi = " << pi << endl;  // pi = 3.14

  // вызов встраиваемой функции
  cout << "[mm] 123 is [m] " << mmToM(123) << endl;

  cout << "3! = " << factorial(3) << endl;

  int x = 13;
  getx(x) = 42;
  cout << "возвращение по ссылке = " << x << endl;

  return 0;
}

void getSum() {
  cout << "Ooops! Dont work..." << endl;
}


float getSum(int a, int b, int c) {
  return a + b + c;
}

float getSum(float a, float b) {
  return a + b;
}

Position getPosition(float x, float y, float z) {
  Position pos = {x, y, z};
  return pos;
}

void computePi(float& pi, float l, float r) {
  pi = l / r;
}

unsigned long factorial(int n) {
  if (n > 1) {
    return n * factorial(n-1);
  } else {
    return 1;
  }
}