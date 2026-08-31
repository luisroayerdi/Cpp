#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  long long size;
  std::cin >> size;

  std::vector<long long> coins(size);

  for (int i = 0; i < size; i++) {
    std::cin >> coins[i];
  }

  std::sort(coins.begin(), coins.end());

  long long count = 0;
  long long min;

  for (int i = 0; i < size; i++) {
    if (coins[i] <= count + 1) {
      count += coins[i];
    }
    min = count + 1;
  }
  std::cout << min;

  return 0;
}
