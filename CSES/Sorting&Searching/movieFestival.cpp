#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

int main() {
  int number_movies;
  std::cin >> number_movies;

  std::vector<std::pair<int, int>> movies_times(number_movies);

  for (int i = 0; i < number_movies; ++i) {
    std::cin >> movies_times[i].first >> movies_times[i].second;
  }

  std::sort(movies_times.begin(), movies_times.end(),
            [](const auto &a, const auto &b) { return a.second < b.second; });

  int p_end = 0;
  int p_begin = 1;
  int count = 1;

  while (p_begin + 1 <= number_movies) {
    if (movies_times[p_end].second <= movies_times[p_begin].first) {
      count++;
      p_begin++;
      p_end = p_begin - 1;
    } else {
      p_begin++;
    }
  }

  std::cout << count;
  return 0;
}
