#include <iostream>
using namespace std;    // File: q4.cc

class my_array_class {
  size_t len = 3;
  int *a = new int[3];
 public:
  my_array_class() { a[0] = 1; a[1] = 2; a[2] = 3; }
  my_array_class(size_t ln, const int *o) : len(ln), a(new int[ln])
    { for (size_t n = 0; n < len; ++n) a[n] = o[n]; }
  ~my_array_class() { delete[] a; }
  size_t get_length() const { return len; }
  int get(size_t n) const { return a[n]; }
  int set(size_t n, int v) { int tmp = a[n]; a[n] = v; return tmp; }
};

void foo(const my_array_class &a2, size_t i) {
  if (i < a2.get_length())
    std::cout << a2.get(i) << std::endl;
}

int main() {
  int zero12[] = {13, 1, 2};
  my_array_class a1(3, zero12);
  foo(a1, 0);
  return 0;
}
