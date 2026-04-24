#include "leetcode_utils.h"

class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    unordered_set<char> us;
    int length = 0, left = 0;
    for (int right = 0; right < s.size(); ++right) {
      while(us.find(s[right]) != us.end()) {
        us.erase(s[left++]);
      }
      us.insert(s[right]);
      length = max(length, right - left + 1);
    }

    return length;
  }
};

int main() {
  Solution so;
  debug(so.lengthOfLongestSubstring("123451"), "ret:");
  return 0;
}