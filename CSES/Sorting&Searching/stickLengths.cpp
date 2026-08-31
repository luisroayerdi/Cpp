#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  long long numberSticks;
  std::cin >> numberSticks;

  std::vector<long long> sticks(numberSticks);

  for (int i = 0; i < numberSticks; ++i) {
    std::cin >> sticks[i];
  }

  std::sort(sticks.begin(), sticks.end());

  int median = sticks[numberSticks / 2];

  long long count = 0;

  for (int i = 0; i < numberSticks; ++i) {
    int difference = sticks[i] - median;
    count += std::abs(difference);
  }

  std::cout << count;
}
