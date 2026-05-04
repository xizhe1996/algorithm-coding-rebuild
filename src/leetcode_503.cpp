#include "leetcode_utils.h"

class Solution {
 public:
  vector<int> nextGreaterElements(vector<int>& nums) {
    stack<int> st;
    int n = nums.size();
    vector<int> ans(n, -1);
    for (int i = 0; i < 2 * n; ++i) {
      while (!st.empty() && nums[st.top()] < nums[i % n]) {
        ans[st.top()] = nums[i % n];
        st.pop();
      }

      if (i < n) st.push(i);
    }
    return ans;
  }
};

int main() {
  vector<int> nums{1, 2, 1};
  Solution so;
  debug(so.nextGreaterElements(nums), "ans");
  return 0;
}