#include <iostream>
using namespace std;    // File: q3.cc
class person {
  int age;
 public:
  person(int a = 10) : age(a) {}
  int get_age() const;
};             
int person::get_age() const {
  return age;
}
int main() {
  person p1;
  cout << p1.get_age() << endl;
  int* age_ptr = (int*)&p1;
  *age_ptr = 25;
  cout << p1.get_age() << endl;
  return 0;
}
