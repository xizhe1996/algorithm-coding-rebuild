#include "leetcode_utils.h"

class Solution {
 public:
  int dfs(TreeNode* root, int current_num) {
    if (root == nullptr) return 0;

    int _sum = current_num * 10 + root->val;

    if (root->left == nullptr && root->right == nullptr) return _sum;

    int left = dfs(root->left, _sum);
    int right = dfs(root->right, _sum);

    return left + right;
  }

  int sumNumbers(TreeNode* root) {
    if (root == nullptr) return 0;
    return dfs(root, 0);
  }
};

int main() { return 0; }