#include "leetcode_utils.h"

class Solution {
 public:
  void moveZeroes(vector<int>& num) {
    int fast = 0, slow = 0;
    while (fast < num.size()) {
      if (num[fast] != 0) num[slow++] = num[fast];
      fast++;
    }

    while (slow < num.size()) {
      num[slow++] = 0;
    }
  }
};

int main() {
  Solution so;
  vector<int> num{0, 1, 0, 3, 12};
  so.moveZeroes(num);
  debug(num, "num:");
  return 0;
}