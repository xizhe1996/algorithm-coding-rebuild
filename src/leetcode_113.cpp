#include "leetcode_utils.h"

class solution {
 public:
  void dfs(TreeNode* root, int targetSum, vector<vector<int>>& ret,
           vector<int>& ans) {
    if (root == nullptr) return;

    ans.push_back(root->val);

    if (root->left == nullptr && root->right == nullptr &&
        root->val == targetSum)
      ret.push_back(ans);
    else {
      dfs(root->left, targetSum - root->val, ret, ans);
      dfs(root->right, targetSum - root->val, ret, ans);
    }

    ans.pop_back();
  }

  vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    vector<vector<int>> ret;
    vector<int> ans;

    dfs(root, targetSum, ret, ans);

    return ret;
  }
};

int main() { return 0; }