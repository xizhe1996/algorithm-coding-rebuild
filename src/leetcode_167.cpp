#include "leetcode_utils.h"

class Solution {
 public:
  vector<int> twoSum(vector<int>& numbers, int target) {
    int left = 0, right = numbers.size() - 1;
    while (left < right) {
      int sum = numbers[left] + numbers[right];
      if (sum == target)
        return {left + 1, right + 1};
      else if (sum > target)
        --right;
      else
        ++left;
    }
    return {};
  }
};

int main() {
  Solution so;
  vector<int> nums{2, 7, 8, 10};
  int target = 9;
  debug(so.twoSum(nums, target), "nums:");
  return 0;
}