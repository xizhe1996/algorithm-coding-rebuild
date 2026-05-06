#include "leetcode_utils.h"

class Solution {
 public:
  ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* dummy = new ListNode(-1);
    ListNode *node1 = list1, *node2 = list2, *curr = dummy;
    while (node1 != nullptr && node2 != nullptr) {
      if (node1->val < node2->val) {
        curr->next = node1;
        node1 = node1->next;
      } else {
        curr->next = node2;
        node2 = node2->next;
      }
      curr = curr->next;
    }

    curr->next = (node1 != nullptr) ? node1 : node2;

    return dummy->next;
  }
};

int main() { return 0; }