#include "leetcode_utils.h"

class Solution {
  int max_sum = INT_MIN;  // 全公司的最高纪录榜单，初始设为极小值

  int dfs(TreeNode* root) {
    // 1. 绝对拦截线
    if (root == nullptr) return 0;

    // 2. 派副总裁去搜山（听汇报）
    // 技巧：加门神！如果是负资产，直接按 0 处理
    int left_profit = max(0, dfs(root->left));
    int right_profit = max(0, dfs(root->right));

    // 3. 自己偷偷挑战世界纪录（办自己的事：架设包含自己的彩虹桥）
    int my_profit = root->val + left_profit + right_profit;
    max_sum = max(max_sum, my_profit);

    // 4. 向上级交单行道业绩 (汇报)
    return max(root->val + left_profit, root->val + right_profit);
  }

 public:
  int maxPathSum(TreeNode* root) {
    dfs(root);
    return max_sum;
  }
};

int main() { return 0; }