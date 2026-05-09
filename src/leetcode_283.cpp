#include "leetcode_utils.h"
class Solution {
 public:
  void moveZeroes(vector<int>& nums) {
    int fast = 0, slow = 0;
    while (fast < nums.size()) {
      if (nums[fast] != 0) {
        swap(nums[slow++], nums[fast++]);
      } else
        fast++;
    }
  }
};

int main() {
  vector<int> nums = {0, 1, 0, 3, 12};
  Solution so;
  so.moveZeroes(nums);
  debug(nums);
  return 0;
}