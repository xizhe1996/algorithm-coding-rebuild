#include "leetcode_utils.h"

class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int n = prices.size();
    if (n == 0) return 0;

    // 1. 定义备忘录 (n 天，每天 3 个状态)
    vector<vector<int>> dp(n, vector<int>(3, 0));

    // 2.
    // 状态0: 当日买入 或者 继续持有
    // 状态1: 当日卖出
    // 状态2: 卖出冷静期 或者 继续不持有
    dp[0][0] = -prices[0];
    dp[0][1] = INT_MIN / 2;
    dp[0][2] = 0;

    // 3. 循环推导未来 (从第 1 天开始)
    for (int i = 1; i < n; ++i) {
      dp[i][0] = max(dp[i - 1][0], dp[i - 1][2] - prices[i]);
      dp[i][1] = dp[i - 1][0] + prices[i];
      dp[i][2] = max(dp[i - 1][2], dp[i - 1][1]);
    }

    // 4. 返回最终结果
    return max(dp[n - 1][1], dp[n - 1][2]);
  }
};

int main() {
  Solution so;
  vector<int> prices = {1, 2, 3, 0, 2};
  // 预期输出：3
  debug(so.maxProfit(prices));
  return 0;
}