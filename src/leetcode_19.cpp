#include "leetcode_utils.h"

class Solution {
 public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy = new ListNode(0, head), *slow = dummy, *fast = dummy;
        //
        while (n > 0) {
        fast = fast->next;
        n--;
        }

        // move
        while (fast != nullptr && fast->next != nullptr) {
        fast = fast->next;
        slow = slow->next;
        }

        // delete next
        slow->next = slow->next->next;

        return dummy->next;
  }
};

int main() { return 0; }