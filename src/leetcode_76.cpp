#include "leetcode_utils.h"

class Solution {
 public:
  string minWindow(string s, string t) {
    vector<int> windows(128, 0);
    vector<int> need(128, 0);
    int need_count = 0, reday = 0;

    for (char c : t) {
      if (need[c] == 0) need_count++;
      need[c]++;
    }

    int left = 0, right = 0, min_left = 0, min_len = s.size() + 1;

    while (right < s.size()) {
      // 更新窗口
      windows[s[right]]++;
      // 更新reday
      if (need[s[right]] > 0 && windows[s[right]] == need[s[right]]) {
        ++reday;
      }
      // 判断 && 执行 缩减窗口 && 更新极值
      while (reday == need_count) {
        if (right - left + 1 < min_len) {
          min_len = right - left + 1;
          min_left = left;
        }

        windows[s[left]]--;

        if (need[s[left]] > 0 && windows[s[left]] < need[s[left]]) reday--;

        left++;
      }

      right++;
    }

    return (min_len == s.size() + 1) ? "" : s.substr(min_left, min_len);
  }
};

int main() { return 0; }
