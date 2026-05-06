#include "leetcode_utils.h"

class Solution {
 public:
  void reorderList(ListNode* head) {
    //
    ListNode *slow = head, *fast = head;

    while (fast != nullptr && fast->next != nullptr) {
      slow = slow->next;
      fast = fast->next->next;
    }

    ListNode *firstL = head, *secondL = slow->next;
    slow->next = nullptr;

    //
    ListNode *curr = secondL, *prev = nullptr, *save = nullptr;
    while (curr != nullptr) {
      save = curr->next;
      curr->next = prev;
      prev = curr;
      curr = save;
    }

    secondL = prev;

    //
    ListNode *dummy = new ListNode(-1), *node = dummy;
    while (firstL != nullptr && secondL != nullptr) {
      node->next = firstL;
      firstL = firstL->next;
      node = node->next;

      node->next = secondL;
      secondL = secondL->next;
      node = node->next;
    }

    node->next = (firstL != nullptr) ? firstL : secondL;

    head = dummy->next;
  }
};

int main() { return 0; }