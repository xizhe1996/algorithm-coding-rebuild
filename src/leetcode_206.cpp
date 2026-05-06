#include "leetcode_utils.h"

#if 0
class Solution {
 public:
  ListNode* reverseList(ListNode* head) {
    ListNode *curr = head, *prev = nullptr, *save = curr;
    while (curr != nullptr) {
      save = curr->next;
      curr->next = prev;
      prev = curr;
      curr = save;
    }
    return prev;
  }
};
#endif

class Solution {
 public:
  ListNode* reverseList(ListNode* head) {
    if (head == nullptr || head->next == nullptr) return head;
    ListNode* newNode = reverseList(head->next);
    head->next->next = head;
    head->next = nullptr;
    return newNode;
  }
};

int main() { return 0; }