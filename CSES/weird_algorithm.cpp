#include <iostream>

int main() {
  int x;
  std::cin >> x;

  while (x != 1) {
    if (x % 2 == 0) {
      x = x / 2;
      std::cout << x << " ";
    } else {
      x = x * 3;
      x++;
      std::cout << x << " ";
    }
  }
}
