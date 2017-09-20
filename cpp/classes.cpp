#include <iostream>

class Square {
 //private: // по умолчанию все члены класса private (а в структоруах public)
  float a;
  float S;
  float P;

 public:
  Square() : a(0), S(0), P(0) {}
  explicit Square(int a) : a(a) { // explicit т.к. конструктор с одним аргументом вообще-то
                                  // уже есть и называется копирующим конструктором
    this->S = a * a;
    this->P = 4 * a;
  }
  void set_a(int a) {
    this->a = a;
    this->S = a * a;
    this->P = 4 * a;
  }

  float get_s() const { // const гарантирует, что метод не изменяет поля экземпляра класса
    // set_a(3); // ошибка: нельзя вызываеть неконсантную функцию из константной
    return S;
  }

  void set_s() const {
    //S = 99; // в константном методе нельзя изменить поле объекта
  }

};

int main() {
  Square s;
  // доказательство того, что все члены класса по умолчанию с доступом  private
  // int a = s.a  // ошибка, так как поле a инкапсулировано
  s.set_a(5);
  std::cout << s.get_s() << std::endl;

  // константный объект, у которого могут быть вызваны только константные методы
  const Square s1(13);
  // s1.set_a(3); // ошибка: метод set_a() неконстантный!
  std::cout << "Вызов константного метода у константного объекта " << s1.get_s() << std::endl;

  return 0;
}
