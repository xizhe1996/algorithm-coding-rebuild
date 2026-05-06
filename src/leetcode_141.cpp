#include "leetcode_utils.h"

class Solution {
 public:
  bool hasCycle(ListNode* head) {
    ListNode *slow = head, *fast = head;
    while (fast != nullptr && fast->next != nullptr) {
      slow = slow->next;
      fast = fast->next->next;
      if (fast == slow) return true;
    }

    return false;
  }
};

int main() { return 0; }