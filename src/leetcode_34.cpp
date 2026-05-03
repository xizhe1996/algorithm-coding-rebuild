#include "leetcode_utils.h"

class Solution {
 public:
  vector<int> searchRange(vector<int>& nums, int target) {
    if (nums.empty()) return {-1, -1};
    int left = 0, right = nums.size() - 1, mid = 0;
    int ret_left = 0;
    // left
    while (left < right) {
      mid = left + (right - left) / 2;
      if (nums[mid] == target)
        right = mid;
      else if (nums[mid] > target)
        right = mid - 1;
      else
        left = mid + 1;
    }

    // left == right
    if (nums[left] != target) return {-1, -1};
    ret_left = left;

    // right
    right = nums.size() - 1;
    while (left < right) {
      mid = left + (right - left + 1) / 2;
      if (nums[mid] == target)
        left = mid;
      else
        right = mid - 1;
    }

    return {ret_left, left};
  }
};
int main() { return 0; }