#include "leetcode_utils.h"

class solution {
 public:
  bool hasPathSum(TreeNode* root, int targetSum) {
    if (root == nullptr) return false;

    if (root->left == nullptr && root->right == nullptr &&
        root->val == targetSum)
      return true;

    return (hasPathSum(root->left, targetSum - root->val)) ||
           (hasPathSum(root->right, targetSum - root->val));
  }
};

int main() { return 0; }