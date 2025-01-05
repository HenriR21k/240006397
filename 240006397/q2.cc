#include <iostream>
using namespace std;    // File: q2.cc

template <typename T>
class person { 
  T age;
 public:
  person() : age(0) {}
  person(T a) : age(a) {}
  T get_age() const;
  void set_age(T a);
  
};

template <typename T>
T person<T>::get_age() const {
  return age;
}

template <typename T>
void person<T>::set_age(T a) {
  age = a;
}

int main() {
  person<unsigned long> p1;
  p1.set_age(25);
  cout << p1.get_age() << endl;
  return 0;
}
