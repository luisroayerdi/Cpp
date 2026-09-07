#include <iostream>
#include <vector>

class Solution {
public:
  int maxProfit(std::vector<int> &prices) {
    int left = 0;
    int right = 1;
    int max = 0;

    while (right < prices.size()) {
      int new_max = prices[right] - prices[left];
      if (new_max > max) {
        max = new_max;
      }
      if (prices[left] >= prices[right]) {
        right++;
        left = right - 1;
      } else {
        right++;
      }
    }
    return max;
  }
};

int main() {
  Solution sol;

  std::vector<int> prices = {7, 1, 5, 3, 6, 4};

  std::cout << sol.maxProfit(prices) << std::endl;

  return 0;
}
