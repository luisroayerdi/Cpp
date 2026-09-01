#include <iostream>
#include <vector>

class Solution {
public:
  std::vector<int> twoSum(std::vector<int>& numbers, int target) {
    // TODO implement
    return {};
  }
};

int main() {
  Solution sol;

  std::vector<int> numbers = {2, 7, 11, 15};
  int target = 9;

  std::vector<int> result = sol.twoSum(numbers, target);
  std::cout << result[0] << " " << result[1] << std::endl;

  return 0;
}
