#include "Vector.h"
#include <iostream>

int main() {
  // Test default constructor
  Vector<int> a;
  // Test Copy Constructor
  Vector<int> b = a;
  // Test Copy assignment operator=
  Vector<int> c;
  c = a;
  // Test Move Constructor
  Vector<int> d = std::move(a);
  // Test Move assignment operator
  Vector<int> e;
  e = std::move(a);

  // Test size with constant vector
  const Vector<int> v;
  std::cout << v.size();
}
