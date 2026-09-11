#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
  int characterReplacement(string s, int k) {

    int left = 0;
    int right = 0;
    unordered_map<char, int> frequencies;
    int lenMax = 1;
    int maxFreq = 0;

    while (right < s.size()) {
      frequencies[s[right]]++;
      maxFreq = max(maxFreq, frequencies[s[right]]);
      int currentWindow = right - left + 1;
      if (currentWindow - maxFreq > k) {
        frequencies[s[left]]--;
        left++;
      }
      currentWindow = right - left + 1;
      lenMax = max(lenMax, currentWindow);
      right++;
    }

    return lenMax;
  }
};

int main() {
  Solution sol;

  std::cout << sol.characterReplacement("ABAB", 2) << std::endl;
  std::cout << sol.characterReplacement("AABABBA", 1) << std::endl;
  std::cout << sol.characterReplacement("AAAA", 0) << std::endl;

  return 0;
}
