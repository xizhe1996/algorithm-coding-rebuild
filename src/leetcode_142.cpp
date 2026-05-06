#include "leetcode_utils.h"

class Solution {
 public:
  ListNode* detectCycle(ListNode* head) {
    ListNode *slow = head, *fast = head;
    while (fast != nullptr && fast->next != nullptr) {
      slow = slow->next;
      fast = fast->next->next;
      if (slow == fast) {
        fast = head;
        while (fast != slow) {
          fast = fast->next;
          slow = slow->next;
        }

        return fast;
      }
    }
    return nullptr;
  }
};

int main() { return 0; }