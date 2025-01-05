#include <iostream>
using namespace std;    // File: q1.cc

class person {
  int age;
 public:
  person(int a = 10) : age(a) {}
  int get_age() const { return age; }
  void set_age(int a) { age = a; }
};

int main() {
  person p1;
  p1.set_age(25);
  cout << p1.get_age() << endl;
  return 0;
}
