#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  bool checkInclusion(string s1, string s2) {
    //Edge case no possible permutation s1 longer than s2
    if (s1.size() > s2.size()) {
      return false;
    }
    // creating frequency map for s1
    vector<int> frequency_s1(26);
    for (int i = 0; i < s1.size(); i++) {
      int letter = s1[i] - 'a';
      frequency_s1[letter]++;
    }
    //creating frequency map for s2 first window
    int left = 0;
    int right = s1.size() - 1;
    vector<int> frequency_window(26);
    for (int j = 0; j <= right; j++) {
      int letter = s2[j] - 'a';
      frequency_window[letter]++;
    }
    //Loop to traverse all windows in s2
    while (right <= s2.size() - 1) {
      // check equality
      if (frequency_s1 == frequency_window) {
        return true;
      }
      if (right < s2.size() - 1) {
        //move window
        int letter = s2[left] - 'a';
        frequency_window[letter]--;
        left++;

        right++;
        letter = s2[right] - 'a';
        frequency_window[letter]++;
      } else {
        right++;
      }
    }
    return false;
  }
};

int main() {
  Solution sol;

  std::cout << sol.checkInclusion("ab", "eidbaooo") << std::endl;
  std::cout << sol.checkInclusion("ab", "eidboaoo") << std::endl;

  return 0;
}
