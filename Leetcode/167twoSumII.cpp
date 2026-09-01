#include <iostream>
#include <vector>

class Solution {
public:
  std::vector<int> twoSum(std::vector<int> &numbers, int target) {
    int left = 0;
    int right = numbers.size() - 1;

    std::vector<int> solution;

    while (left < right) {
      if (numbers[left] + numbers[right] > target) {
        right--;
      } else if (numbers[left] + numbers[right] < target) {
        left++;
      } else {
        solution.push_back(left + 1);
        solution.push_back(right + 1);
        return solution;
      }
    }
    return solution;
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
