#include <iostream>
using namespace std;        // File: q6.cc

class my_array_over2 {
  size_t len = 1;
  int *a = new int[1];
 public:
  my_array_over2() { a[0] = 0; }
  my_array_over2(size_t ln, const int *o) : len(ln), a(new int[ln])
    { for (size_t n = 0; n < ln; ++n) a[n] = o[n]; }
  ~my_array_over2() { delete[] a; }
  
  size_t get_length() const { return len; }
  
  int& operator[](size_t n) { return a[n]; }
  
  int operator[](size_t n) const { return a[n]; }
};

void foo(const my_array_over2 &a2, size_t i) {
  if (i < a2.get_length())
    std::cout << a2[i] << std::endl;
}

int main() {
  int zero12[] = {13, 1, 2};
  my_array_over2 a1(3, zero12);
  a1[1] = 14;
  foo(a1, 1);
  return 0;
}
