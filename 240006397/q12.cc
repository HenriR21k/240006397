#include <iostream>
using namespace std;      // File: q12.cc
class my_array_mem {
  int len = 1;
  int *a = new int [1];
 public:
  my_array_mem() { a[0] = 0; }
  my_array_mem(int l, const int *o) : len(l), a(new int [l]) {
    for (int n = 0; n < l; ++n) a[n] = o[n];
  }
  ~my_array_mem() { delete[] a; }

  my_array_mem(const my_array_mem& other) : len(other.len), a(new int[other.len]) {
    for (int i = 0; i < len; ++i) {
      a[i] = other.a[i];
    }
  }

  my_array_mem& operator=(const my_array_mem& other) {
    if (this != &other) {
      delete[] a;
      len = other.len;
      a = new int[len];
      for (int i = 0; i < len; ++i) {
        a[i] = other.a[i];
      }
    }
    return *this;
  }

  int get(int n) { return a[n]; }
  int set(int n, int v) { 
    int tmp = a[n]; 
    a[n] = v; 
    return tmp; 
  }
};

void foo() {
  int zero12[] = {13, 14, 15};
  my_array_mem a1(3, zero12);
  my_array_mem a2 = a1;
  my_array_mem a3;
  a3 = a2; 
  std::cout << a3.set(0, a2.get(1)) << std::endl;
}

int main() {
  std::cout << 1 << std::endl;
  foo();
  std::cout << 3 << std::endl;
  return 0;
}
