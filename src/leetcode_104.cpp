#include "leetcode_utils.h"

class solution {
 public:
  int maxDepth(TreeNode* root) {
    if (root == nullptr) return 0;
    return std::max(1 + maxDepth(root->left), 1 + maxDepth(root->right));
  }
};

int main() { return 0; }