#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
  std::vector<std::vector<int>> threeSum(std::vector<int> &nums) {
    std::vector<std::vector<int>> solution;
    std::sort(nums.begin(), nums.end());

    int fixed = 0;

    while (fixed <= nums.size() - 1) {
      int left = fixed + 1;
      int right = nums.size() - 1;
      while (left <= right) {
        // if (left == fixed) {
        //  left++;
        // }
        if (right == fixed) {
          right--;
        }

        if ((nums[left] + nums[right] + nums[fixed]) == 0) {
          std::vector<int> triplet = {nums[fixed], nums[left], nums[right]};
          solution.push_back(triplet);
          while (nums[fixed] == nums[fixed + 1]) {
            right--;
            left++;
          }
        }

        if ((nums[left] + nums[right]) + nums[fixed] > 0) {
          if (right != nums.size() - 1) {
            while (nums[right] == nums[right + 1]) {
              right--;
            }
          }
        }

        if ((nums[left] + nums[right]) + nums[fixed] < 0) {
          if (left != nums.size() - 1) {
            while (nums[left] == nums[left - 1]) {
              left++;
            }
          }
        }
        left++;
        right--;
      }
      fixed++;
    }
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
