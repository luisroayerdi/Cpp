#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>

class Solution {
public:
  int lengthOfLongestSubstring(std::string s) {
    int left = 0;
    int right = 0;
    std::unordered_set<char> set;
    int maxLen = 1;

    if (s.size() == 0) {
      return 0;
    }

    while (right < s.size()) {
      if (set.find(s[right]) == set.end()) {
        set.insert(s[right]);
        maxLen = std::max(maxLen, right - left + 1);
        right++;
      } else {
        while (set.count(s[right]) == 1) {
          set.erase(s[left]);
          left++;
        }
      }
    }
    return maxLen;
  }
};

int main() {
  Solution sol;

  std::cout << sol.lengthOfLongestSubstring("dvdf") << std::endl;
  std::cout << sol.lengthOfLongestSubstring("abcabcbb") << std::endl;
  std::cout << sol.lengthOfLongestSubstring("bbbbb") << std::endl;
  std::cout << sol.lengthOfLongestSubstring("pwwkew") << std::endl;
  std::cout << sol.lengthOfLongestSubstring("") << std::endl;

  return 0;
}
