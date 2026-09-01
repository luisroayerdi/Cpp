#include <cctype>
#include <iostream>
#include <string>

class Solution {
public:
  bool isPalindrome(std::string s) {
    // TODO implement

    int left = 0;
    int right = s.size() - 1;

    while (left < right) {
      while (left < right && !isalnum(s[left])) {
        left++;
      }
      while (left < right && !isalnum(s[right])) {
        right--;
      }
      if (tolower(s[right]) != tolower(s[left])) {
        return false;
      }
      left++;
      right--;
    }
    return true;
  }
};

int main() {
  Solution sol;

  std::string s = "A man, a plan, a canal: Panama";
  std::cout << std::boolalpha << sol.isPalindrome(s) << std::endl;

  return 0;
}
