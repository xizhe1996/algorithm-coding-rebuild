#include "leetcode_utils.h"

class solution {
 public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == p || root == q || root == nullptr) return root;

    TreeNode* left_result = lowestCommonAncestor(root->left, p, q);
    TreeNode* right_result = lowestCommonAncestor(root->right, p, q);

    if (left_result != nullptr && right_result != nullptr)
      return root;
    else if (left_result != nullptr)
      // 2个值都在左侧
      return left_result;
    else
      //
      return right_result;
  }
};

int main() { return 0; }