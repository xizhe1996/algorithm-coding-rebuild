#include "leetcode_utils.h"

class solution {
 public:
  vector<vector<int>> levelOrder(TreeNode* root) {
    // 每一层放到一个数组中
    queue<TreeNode*> q;
    vector<vector<int>> ans;
    if (root != nullptr) q.push(root);

    while (!q.empty()) {
      // 每一层元素的数量 在一次遍历中处理完成
      int n = q.size();
      TreeNode* node;
      vector<int> levelAns;
      while (n--) {
        node = q.front();
        levelAns.push_back(node->val);
        q.pop();
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
      }
      ans.push_back(levelAns);
    }

    return ans;
  }
};

int main() { return 0; }