#include "leetcode_utils.h"

class Solution {
 public:
  int removeDuplicates(vector<int>& nums) {
    if (nums.size() <= 1) return nums.size();

    int slow = 0, fast = 1;

    while (fast < nums.size()) {
      if (nums[fast] != nums[slow]) {
        nums[++slow] = nums[fast++];
      } else
        fast++;
    }

    return slow + 1;
  }
};

int main() {
  vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
  Solution so;
  so.removeDuplicates(nums);
  return 0;
}