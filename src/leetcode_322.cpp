#include "leetcode_utils.h"

class Solution {
 public:
  int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, amount + 1);

    dp[0] = 0;

    // 2. 外层循环：我们要把从 1 到 amount 的每一个金额的“最少硬币数”都算出来
    for (int i = 1; i <= amount; ++i) {
      // 3. 内层循环：对于当前金额 i，尝试手里的每一种硬币
      for (int coin : coins) {
        if (i >= coin) dp[i] = min(dp[i], dp[i - coin] + 1);
      }
    }

    return (dp[amount] == amount + 1) ? -1 : dp[amount];
    // 4. 返回结果：如果 dp[amount] 还是最初的 amount +
    // 1，说明怎么都凑不出，返回 -1 否则返回 dp[amount]
  }
};

int main() { return 0; }