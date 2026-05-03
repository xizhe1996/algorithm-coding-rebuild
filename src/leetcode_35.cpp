#include "leetcode_utils.h"

class Solution {
 public:
  int serachInsert(vector<int>& nums, int target) {
    if (nums.empty()) return 0;

    int left = 0, right = nums.size() - 1, mid = 0;

    while (left <= right) {
      mid = left + (right - left) / 2;
      if (nums[mid] == target)
        return mid;
      else if (nums[mid] > target)
        right = mid - 1;
      else
        left = mid + 1;
    }

    return left;
  }
};

int main() { return 0; }