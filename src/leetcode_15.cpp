#include "leetcode_utils.h"

class Solution {
 public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());
    // debug(nums);

    int fixed = 0;
    while (fixed < nums.size() - 2) {
      if (fixed > 0 && nums[fixed] == nums[fixed - 1]) {
        fixed++;
        continue;
      }

      int target_num = 0 - nums[fixed];
      int left = fixed + 1, right = nums.size() - 1;

      while (left < right) {
        int sum = nums[left] + nums[right];
        if (sum == target_num) {
          result.push_back({nums[fixed], nums[left], nums[right]});
          while (left < right && nums[left] == nums[left + 1]) {
            left++;
          }
          while (left < right && nums[right] == nums[right - 1]) {
            right--;
          }
          left++;
          right--;
        } else if (sum > target_num) {
          right--;
        } else {
          left++;
        }
      }

      fixed++;
    }

    return result;
  }
};

int main() {
  vector<int> nums{1, 2, 0, 1, 0, 0, 0, 0};
  Solution so;

  so.threeSum(nums);
  // debug(so.threeSum(nums), "f result:");

  return 0;
}