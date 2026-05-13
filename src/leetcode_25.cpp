#include "leetcode_utils.h"

class Solution {
 public:
  ListNode* reverseList(ListNode* head) {
    ListNode *prev = nullptr, *curr = head, *save = nullptr;
    while (curr != nullptr) {
      save = curr->next;
      curr->next = prev;
      prev = curr;
      curr = save;
    }
    return prev;
  }

  ListNode* reverseKGroup(ListNode* head, int k) {
    if (head == nullptr || k == 1) return head;

    ListNode* dummy = new ListNode(0, head);
    ListNode *pre = dummy, *end = dummy;

    while (end->next != nullptr) {
      for (int i = 0; i < k && end != nullptr; i++) end = end->next;
      if (end == nullptr) break;

      ListNode* start = pre->next;
      ListNode* next = end->next;

      end->next = nullptr;
      pre->next = reverseList(start);

      start->next = next;

      pre = start;
      end = pre;
    }

    ListNode* res = dummy->next;
    delete dummy;
    return res;
  }
};

int main() { return 0; }