#include <iostream>
#include <vector>

int main() {
  int size;
  std::cin >> size;

  std::vector<long long> array(size);

  for (int i = 0; i < size; i++) {
    std::cin >> array[i];
  }

  int i = 1;
  long long current = array[0];
  long long best = array[0];

  while (i + 1 <= size) {
    current = std::max(current + array[i], array[i]);
    best = std::max(best, current);
    i++;
  }

  std::cout << best;

  return 0;
}
