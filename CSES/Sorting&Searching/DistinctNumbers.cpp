#include <iostream>
#include <set>

int main() {
  int values;
  std::cin >> values;

  // set to keep track of distinct numbers
  std::set<int> s;

  // count of unique numbers
  int count = 0;

  for (auto i = 0; i < values; ++i) {
    int x;
    std::cin >> x;
    if (s.find(x) == end(s)) {
      count++;
      s.insert(x);
    }
  }

  std::cout << count;
}
