#include "leetcode_utils.h"

class Solution {
 public:
  int climbStairs(int n) {
    if (n <= 2) return n;

    int prev1 = 1;    // 对应 dp[i-2]
    int prev2 = 2;    // 对应 dp[i-1]
    int current = 0;  // 对应 dp[i]

    for (int i = 3; i <= n; ++i) {
      current = prev1 + prev2;
      prev1 = prev2;
      prev2 = current;
    }

    return current;
  }
};

int main() {
  Solution so;
  debug(so.climbStairs(4));
  return 0;
}