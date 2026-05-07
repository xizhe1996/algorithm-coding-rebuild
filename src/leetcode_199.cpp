#include "leetcode_utils.h"

class solution {
 public:
  vector<int> rightSideView(TreeNode* root) {
    queue<TreeNode*> q;
    vector<int> ans;
    if (root) q.push(root);

    while (!q.empty()) {
      int n = q.size();
      TreeNode* node;
      while (n--) {
        node = q.front();
        q.pop();
        if (n == 0) ans.push_back(node->val);
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
      }
    }

    return ans;
  }
};

int main() { return 0; }