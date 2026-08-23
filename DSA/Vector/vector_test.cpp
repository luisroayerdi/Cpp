#include "Vector.h"
#include <cassert>
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

  // Test reserve
  Vector<int> reserveTest;
  reserveTest.reserve(10);
  assert(reserveTest.size() == 0);

  // Test resize
  Vector<int> resizeTest;
  resizeTest.resize(5);
  assert(resizeTest.size() == 5);

  // Test push_back
  Vector<int> pushBackTest;
  pushBackTest.push_back(1);
  pushBackTest.push_back(2);
  pushBackTest.push_back(3);
  assert(pushBackTest.size() == 3);
  assert(pushBackTest[0] == 1 && pushBackTest[1] == 2 && pushBackTest[2] == 3);

  // Test pop_back
  Vector<int> popBackTest;
  popBackTest.pop_back();
  assert(popBackTest.size() == 0);
  popBackTest.push_back(1);
  popBackTest.push_back(2);
  popBackTest.pop_back();
  assert(popBackTest.size() == 1);
  assert(popBackTest[0] == 1);

  // Test size
  Vector<int> sizeTest;
  assert(sizeTest.size() == 0);
  sizeTest.push_back(42);
  assert(sizeTest.size() == 1);

  // Test operator[] mutator
  Vector<int> subscriptMutatorTest;
  subscriptMutatorTest.push_back(10);
  subscriptMutatorTest[0] = 99;
  assert(subscriptMutatorTest[0] == 99);

  // Test operator[] accessor on a const vector
  Vector<int> subscriptAccessorSource;
  subscriptAccessorSource.push_back(7);
  const Vector<int> &subscriptAccessorTest = subscriptAccessorSource;
  assert(subscriptAccessorTest[0] == 7);

  std::cout << "\nall tests passed\n";
}
