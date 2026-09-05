#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
  std::vector<std::vector<int>> threeSum(std::vector<int> &nums) {
    std::vector<std::vector<int>> solution;
    sort(nums.begin(), nums.end());

    int n = nums.size();
    int fixed = 0;

    while (fixed < n - 2) {
      // skip duplicate 'fixed values
      if (fixed > 0 && nums[fixed] == nums[fixed - 1]) {
        fixed++;
        continue;
      }

      int left = fixed + 1;
      int right = n - 1;

      while (left < right) {
        int sum = nums[fixed] + nums[left] + nums[right];

        if (sum > 0) {
          right--;
        } else if (sum < 0) {
          left++;
        } else {
          std::vector<int> triplet;
          triplet.push_back(nums[fixed]);
          triplet.push_back(nums[left]);
          triplet.push_back(nums[right]);
          solution.push_back(triplet);

          left++;
          right--;

          while (left < right && nums[left] == nums[left - 1]) {
            left++;
          }

          while (left < right && nums[right] == nums[right + 1]) {
            right--;
          }
        }
      }
      fixed++;
    }
    return solution;
  }
};

int main() {
  Solution sol;

  std::vector<int> nums = {1, 2, 0, 1, 0, 0, 0, 0};

  std::vector<std::vector<int>> result = sol.threeSum(nums);
  for (const auto &triplet : result) {
    for (int n : triplet) {
      std::cout << n << " ";
    }
    std::cout << std::endl;
  }

  return 0;
}
