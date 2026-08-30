#include <iostream>
#include <map>
#include <vector>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int size, sum;
  std::cin >> size >> sum;

  std::vector<int> nums(size);

  for (int i = 0; i < size; i++) {
    std::cin >> nums[i];
  }

  std::map<int, int> map;

  for (int i = 0; i < size; i++) {
    int complement = sum - nums[i];
    auto it = map.find(complement);
    if (it != map.end()) {
      std::cout << i + 1 << " " << it->second + 1;
      return 0;
    }
    map[nums[i]] = i;
  }

  std::cout << "IMPOSSIBLE";
  return 0;
}
