#include "leetcode_utils.h"

class solution {
 public:
  vector<int> twosum(vector<int>& nums, int target) {
    unordered_map<int, int> mp;

    for (int i = 0; i < (int)nums.size(); ++i) {
      auto it = mp.find(target - nums[i]);
      if (it != mp.end()) {
        return {it->second, i};
    }
      mp[nums[i]] = i;
    }

    return {};
  }
};

int main() {
  vector<int> nums{3, 2, 3};
  int target = 6;
  solution so;
  so.twosum(nums, target);
  return 0;
}