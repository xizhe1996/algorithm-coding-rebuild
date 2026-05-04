#include "leetcode_utils.h"

class Solution {
 public:
  int search(vector<int>& nums, int target) {
    if (nums.empty()) return -1;
    int left = 0, right = nums.size() - 1, mid = 0;
    while (left <= right) {
      mid = left + (right - left) / 2;
      if (nums[mid] == target) return mid;

      // 左侧单调
      if (nums[left] <= nums[mid]) {
        // 确认在左侧单调区间内
        if (nums[mid] > target && target >= nums[left])
          right = mid - 1;
        else
          left = mid + 1;
      }
      // 右侧单调
      else {
        // 确认在右侧单调区间内
        if (nums[mid] < target && target <= nums[right])
          left = mid + 1;
        else
          right = mid - 1;
      }
    }

    return -1;
  }
};

int main() { return 0; }