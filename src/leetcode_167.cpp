#include "leetcode_utils.h"

class Solution {
 public:
  vector<int> twoSum(vector<int>& numbers, int target) {
    int left = 0, right = numbers.size() - 1;

    while (left < right) {
      int sum = numbers[left] + numbers[right];
      if (sum == target)
        break;
      else if (sum > target)
        --right;
      else
        ++left;
    }

    return {left + 1, right + 1};
  }
};

int main() {
  // 你可以在这里写测试用例
  return 0;
}