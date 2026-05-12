#include "leetcode_utils.h"

// 合并石头 (基础版：每次合并 2 堆)
int mergeStones(vector<int>& stones) {
  int n = stones.size();
  if (n <= 1) return 0;  // 1 堆或 0 堆不用合并

  // 1. 预处理前缀和 (为了能 O(1) 算出任意区间的重量之和)
  vector<int> prefix(n + 1, 0);
  for (int i = 0; i < n; ++i) {
    prefix[i + 1] = prefix[i] + stones[i];
  }

  // 2. 定义备忘录并初始化大爆炸起点
  vector<vector<int>> dp(n, vector<int>(n, INT_MAX / 2));
  for (int i = 0; i < n; ++i) {
    dp[i][i] = 0;  // 自己一堆，不需要合并消耗
  }

  // 3. 区间 DP 灵魂三层循环
  // 外层：枚举区间长度 len
  for (int len = 2; len <= n; ++len) {
    // 中层：枚举起点 i (保证 j 不越界)
    for (int i = 0; i <= n - len; ++i) {
      int j = i + len - 1;  // 自动定位终点

      // 提取当前这最后一次大合并的消耗 (区间 [i, j] 的重量和)
      int current_interval_weight = prefix[j + 1] - prefix[i];

      // 内层：枚举断点 k (将区间一分为二)
      for (int k = i; k < j; ++k) {
        // 状态转移：左边历史 + 右边历史 + 当前合并消耗
        dp[i][j] =
            min(dp[i][j], dp[i][k] + dp[k + 1][j] + current_interval_weight);
      }
    }
  }

  return dp[0][n - 1];
}

int main() { return 0; }