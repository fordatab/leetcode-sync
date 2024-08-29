class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(-1, head);
        ListNode* a = &dummy;

        for (ListNode* cur = a->next; cur && cur->next; /* updated inside the loop */) {
            if (cur->val == cur->next->val) {
                int d = cur->val;
                while (cur && cur->val == d) {
                    cur = cur->next;
                }
                a->next = cur;  // Skip all nodes with the duplicate value
            } else {
                a = a->next;  // Move to the next node if no duplicate is found
                cur = cur->next;  // Update cur within the loop
            }
        }

        return dummy.next;
    }
};
