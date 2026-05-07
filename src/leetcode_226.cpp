#include "leetcode_utils.h"

class solution {
 public:
  TreeNode* invertTree(TreeNode* root) {
    if (root == nullptr) return nullptr;

    TreeNode *left = root->left, *right = root->right;

    root->left = right;
    root->right = left;
    invertTree(root->left);
    invertTree(root->right);

    return root;
  }
};

int main() { return 0; }