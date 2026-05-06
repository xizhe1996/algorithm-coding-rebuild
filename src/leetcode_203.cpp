#include "leetcode_utils.h"

class Solution {
 public:
  ListNode* removeElements(ListNode* head, int val) {
    ListNode* dummy = new ListNode(0, head);
    ListNode* curr = dummy;
    while (curr->next != nullptr) {
      ListNode* next = curr->next;
      if (next->val == val)
        curr->next = next->next;
      else
        curr = curr->next;
    }
    return dummy->next;
  }
};

int main() { return 0; }