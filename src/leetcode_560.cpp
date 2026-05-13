#include "leetcode_utils.h"

int subarraySum(vector<int>& nums, int k) {
  if (nums.empty()) return 0;

  int count = 0, presum = 0;
  unordered_map<int, int> presum_map;
  presum_map[0] = 1;

  for (int i = 0; i < nums.size(); ++i) {
    presum += nums[i];

    if (presum_map.count(presum - k)) {
      count += presum_map[presum - k];
    }

    ++presum_map[presum];
  }
  return count;
}

int main() { return 0; }