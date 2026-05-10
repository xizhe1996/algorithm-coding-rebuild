#include "leetcode_utils.h"

class Solution {
 public:
  int rob(vector<int>& nums) {
    int n = nums.size();

    if (n == 1) return nums[0];
    if (n == 2) return max(nums[0], nums[1]);

    return max(robRange(nums, 0, nums.size() - 2),
               robRange(nums, 1, nums.size() - 1));
  }

 private:
  int robRange(vector<int>& nums, int start, int end) {
    int prev1 = 0, prev2 = 0, current = 0;

    for (int i = start; i <= end; ++i) {
      current = max(prev1 + nums[i], prev2);
      prev1 = prev2;
      prev2 = current;
    }

    return current;
  }
};

int main() {
  vector<int> nums = {2, 3, 2};
  Solution so;
  debug(so.rob(nums));
  return 0;
}