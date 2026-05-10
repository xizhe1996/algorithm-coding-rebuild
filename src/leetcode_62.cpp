#include "leetcode_utils.h"

class Solution {
 public:
  int uniquePaths(int m, int n) {
    // 1. 定义二维备忘录 dp，大小为 m 行 n 列
    vector<vector<int>> dp(m, vector<int>(n, 0));

    // 2. 初始化边界（大爆炸起点）：第 0 行和第 0 列
    // ❓ 你的任务：把 dp[0][j] 和 dp[i][0] 填上正确的初始值

    // 只能通过向下移动一条路径到达
    for (int k = 0; k < m; ++k) {
      dp[k][0] = 1;
    }

    // 只能通过向右移动一条路径到到
    for (int k = 0; k < n; ++k) {
      dp[0][k] = 1;
    }

    // 3. 双层循环，推导未来 (注意：既然第 0 行和第 0 列已经初始化了，i 和 j
    // 应该从几开始循环？)
    for (int i = 1; i < m; ++i) {
      for (int j = 1; j < n; ++j) {
        // ❓ 你的任务：填入状态转移方程
        dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
      }
    }

    // 4. 返回终点的路径数
    return dp[m - 1][n - 1];
  }
};

int main() { return 0; }