#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
  bool checkInclusion(string s1, string s2) {
    // TODO
    return false;
  }
};

int main() {
  Solution sol;

  std::cout << sol.checkInclusion("ab", "eidbaooo") << std::endl;
  std::cout << sol.checkInclusion("ab", "eidboaoo") << std::endl;

  return 0;
}
