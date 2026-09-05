#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
  std::vector<std::vector<int>> threeSum(std::vector<int> &nums) {
    std::vector<std::vector<int>> solution;
    std::sort(nums.begin(), nums.end());

    // use for loop instead of while loop easier to keep track

    return solution;
  }
};

int main() {
  Solution sol;

  std::vector<int> nums = {-1, 0, 1, 2, -1, -4};

  std::vector<std::vector<int>> result = sol.threeSum(nums);
  for (const auto &triplet : result) {
    for (int n : triplet) {
      std::cout << n << " ";
    }
    std::cout << std::endl;
  }

  return 0;
}
