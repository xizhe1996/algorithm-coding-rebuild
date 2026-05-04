#include "leetcode_utils.h"

class Solution {
 public:
  vector<int> dailyTemperatures(vector<int>& temperatures) {
    stack<int> st;
    int n = temperatures.size();
    if (n == 0) return {};
    vector<int> ans(n, 0);
    for (int i = 0; i < n; ++i) {
      while (!st.empty() && temperatures[st.top()] < temperatures[i]) {
        ans.at(st.top()) = i - st.top();
        debug(ans, "ans");
        st.pop();
      }
      st.push(i);
    }
    return ans;
  }
};

int main() {
  vector<int> tem{73, 74, 75, 71, 69, 72, 76, 73};
  Solution so;
  so.dailyTemperatures(tem);
  return 0;
}