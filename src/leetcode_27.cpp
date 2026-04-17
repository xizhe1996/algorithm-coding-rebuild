#include "leetcode_utils.h"

class Solution {
 public:
  int removeElement(vector<int>& nums, int val) {
    int slow = 0;
    for (int fast = 0; fast < nums.size(); ++fast) {
      if (nums[fast] != val) {
        nums[slow++] = nums[fast];
      }
    }

    return slow;
  }
};

int main() {
  Solution so;
  vector<int> nums{3, 2, 2, 3};
  int val = 3;
  int ret = so.removeElement(nums, val);
  debug(ret);
  debug(nums, "nums");
  return 0;
}