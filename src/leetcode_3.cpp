#include "leetcode_utils.h"

class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    unordered_set<char> stomach;
    int left = 0;
    int max_len = 0;

    for (int right = 0; right < s.length(); right++) {
      char new_char = s[right];

      while (stomach.count(new_char)) {
        stomach.erase(s.at(left++));
      }

      stomach.insert(new_char);

      max_len = max(max_len, right - left + 1);
    }
    return max_len;
  }
};

int main() {
  Solution so;
  debug(so.lengthOfLongestSubstring("123451"), "ret:");
  return 0;
}