#include "leetcode_utils.h"

class Solution {
 public:
  bool isPalindrome(string s) {
    int left = 0, right = s.size() - 1;

    while (left < right) {
      while (left < right && !isalnum(s[left])) ++left;
      while (left < right && !isalnum(s[right])) --right;

      if (tolower(s[left]) != tolower(s[right])) {
        return false;
      }
      ++left;
      --right;
    }
    return true;
  }
};

int main() {
  Solution so;
  debug(so.isPalindrome("ba"), "string");
  debug(so.isPalindrome("a"), "string");
  debug(so.isPalindrome(""), "string");

  return 0;
}