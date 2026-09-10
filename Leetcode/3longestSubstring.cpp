// /*
// *
// *
// *
// *
// *
// * class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         int left = 0;
//         int right = 0;
//         unordered_set<char> set;
//         int maxLen = 1;
//
//         if (s.size() == 0) { return 0;}
//
//
//         while (right < s.size()) {
//
//             if (set.find(s[right]) == end(set) && right < s.size()) {
//                 set.insert(s[right]);
//                 right++;
//                 continue;
//             }
//
//             int count = right - left;
//
//             if (left < right) {
//                 set.erase(s[left]);
//                 left++;
//                 continue;
//             }
//
//             if (count > maxLen) {
//                 maxLen = count;
//             }
//
//             left++;
//             right++;
//         }
//         return maxLen;
//     }
// };
// * /
