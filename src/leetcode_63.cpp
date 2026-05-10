#include "leetcode_utils.h"

class Solution {
 public:
  int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();

    vector<int> dp(n, 0);

    // 初始化第一个节点状态
    dp[0] = (obstacleGrid[0][0]) ? 0 : 1;

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        // 有石头 直接赋0 完成节点计算
        if (obstacleGrid[i][j]) {
          dp[j] = 0;
          continue;
        }

        // 没有石头&&  如果j == 0 保持数值不变 否则 进行状态转移

        if (j >= 1) dp[j] = dp[j - 1] + dp[j];
      }
    }

    return dp[n - 1];
  }
};

int main() {
  // 测试用例：3x3 网格，中间 (1,1) 位置有一个石头 (1)
  vector<vector<int>> obstacleGrid = {{0, 0}, {1, 1}, {0, 0}};

  Solution so;
  // 预期输出应该是 2
  debug(so.uniquePathsWithObstacles(obstacleGrid));

  return 0;
}