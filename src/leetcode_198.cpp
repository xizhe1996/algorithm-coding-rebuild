#include "leetcode_utils.h"

class Solution {
 public:
  int rob(vector<int>& nums) {
    int prev1 = 0, prev2 = 0, current = 0;

    for (int i = 0; i < nums.size(); ++i) {
      current = max(prev1 + nums[i], prev2);
      prev1 = prev2;
      prev2 = current;
    }

    return current;
  }
};

int main() {
  vector<int> nums = {1, 2, 3, 1};
  Solution so;
  debug(so.rob(nums));
  return 0;
}