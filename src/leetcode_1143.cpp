#include "leetcode_utils.h"

class Solution {
 public:
  int longestCommonSubsequence(string text1, string text2) {
#if 0
    int m = text1.size(), n = text2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    // dp[i][j]
    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (text1[i - 1] == text2[j - 1]) {
          dp[i][j] = dp[i - 1][j - 1] + 1;
        } else {
          dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
      }
    }

    return dp[m][n];
#endif

    int m = text1.size(), n = text2.size();
    vector<int> dp(n + 1, 0);

    for (int i = 1; i <= m; ++i) {
      int left_up = 0;
      for (int j = 1; j <= n; ++j) {
        int tmp = dp[j];
        if (text1[i - 1] == text2[j - 1]) {
          dp[j] = left_up + 1;
        } else {
          dp[j] = max(dp[j], dp[j - 1]);
        }
        left_up = tmp;
      }
    }

    return dp[n];
  }
};

int main() {
  Solution so;
  string text1 = "abcba";
  string text2 = "abcbcba";
  // 预期输出：3
  debug(so.longestCommonSubsequence(text1, text2));
  return 0;
}