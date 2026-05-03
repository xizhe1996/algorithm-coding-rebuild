#include "leetcode_utils.h"

class Solution {
 public:
  bool check(vector<int>& piles, int speed, int h) {
    int sum = 0;
    for (auto& num : piles) {
      sum += (num + speed - 1) / speed;
    }
    return (sum <= h);
  }

  int minEatingSpeed(vector<int>& piles, int h) {
    int left = 1,
        right = *max_element(piles.begin(), piles.end()), mid = 0;

    while (left < right) {
      mid = left + (right - left) / 2;
      if (check(piles, mid, h)) {
        right = mid;
      } else
        left = mid + 1;
    }
    return left;
  }
};

int main() { 
    vector<int> piles {3, 6, 7, 11};
    int h = 8;
    Solution so;
    debug(so.minEatingSpeed(piles, h));
    return 0; }