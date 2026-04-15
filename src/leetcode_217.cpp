#include "leetcode_utils.h"

class solution {
 public:
  bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> us;
    for (auto& num : nums) {
      auto it = us.find(num);
      if (it != us.end()) return true;
      us.insert(num);
    }
    return false;
  }
};

int main() { return 0; }