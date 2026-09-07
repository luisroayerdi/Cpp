#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
  int maxArea(std::vector<int> &height) {
    int left = 0;
    int right = height.size() - 1;
    int max = 0;

    while (left < right) {
      int length = std::min(height[left], height[right]);
      int width = right - left;
      int new_max = length * width;

      if (new_max > max) {
        max = new_max;
      }

      if (height[right] > height[left]) {
        left++;
      } else {
        right--;
      }
    }

    return max;
  }
};

int main() {
  Solution sol;

  std::vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};

  std::cout << sol.maxArea(height) << std::endl;

  return 0;
}
