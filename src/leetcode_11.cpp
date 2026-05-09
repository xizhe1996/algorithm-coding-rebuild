#include "leetcode_utils.h"

class Solution {
 public:
  int maxArea(vector<int>& height) {
    int left = 0, right = height.size() - 1;
    int maxArea = 0;

    while (left < right) {
      int area = (right - left) * min(height[left], height[right]);
      maxArea = max(area, maxArea);

      if (height[left] < height[right]) {
        left++;
      } else
        right--;
    }

    return maxArea;
  }
};

int main() {
  // 你可以在这里写测试用例
  return 0;
}