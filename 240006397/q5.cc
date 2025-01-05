#include <iostream>
using namespace std;      // File: q5.cc
class my_array_over {
  size_t len = 1;
  int *a = new int[1];
 public:
  my_array_over() { a[0] = 0; }
  my_array_over(size_t ln, const int *o) : len(ln), a(new int[ln])
    { for (size_t n = 0; n < ln; ++n) a[n] = o[n]; }
  ~my_array_over() { delete[] a; }
  
  size_t get_length() const { return len; }

  int operator[](size_t n) const { return a[n]; }

  void set(size_t n, int value) { if (n < len) a[n] = value; }
};

void foo(const my_array_over &a2, size_t i) {
  if (i < a2.get_length())
    std::cout << a2[i] << std::endl;
}

int main() {
  int zero12[] = {23, 1, 2};
  my_array_over a1(3, zero12);
  a1.set(0, 13);
  foo(a1, 0);
  return 0;
}
