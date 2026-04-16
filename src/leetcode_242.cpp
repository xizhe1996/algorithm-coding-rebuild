#include "leetcode_utils.h"

class Solution {
 public:
  bool isAnagram(string s, string t) {
    if (s.size() != t.size()) return false;
    vector<int> cnt(26, 0);
    for (auto& c : s) {
      ++cnt[c - 'a'];
    }
    debug(cnt, "test1");

    for (char c : t) {
      --cnt[c - 'a'];
    }
    debug(cnt, "test2");

    for (int x : cnt) {
      if (x != 0) return false;
    }
    return true;
  }
};

int main() {
  Solution so;
  so.isAnagram("rat", "car");
  return 0;
}