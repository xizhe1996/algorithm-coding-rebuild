#include "leetcode_utils.h"

class solution {
 public:
  bool isMirror(TreeNode* leftNode, TreeNode* rightNode) {
    // one nullptr
    if (leftNode == nullptr && rightNode != nullptr) return false;
    if (rightNode == nullptr && leftNode != nullptr) return false;
    // both nullptr
    if (leftNode == nullptr && rightNode == nullptr) return true;

    // both not nullptr
    if (leftNode->val != rightNode->val) return false;

    return  (isMirror(leftNode->left, rightNode->right) && isMirror(leftNode->right, rightNode->left));
  }

  bool isSymmetric(TreeNode* root) {

    return (isMirror(root->left, root->right));
  }
};

int main() { return 0; }