/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* i = l1;
        ListNode* j = l2;
        while (!(i->next == nullptr && j->next == nullptr)) {
            if (i->next == nullptr) {
                i->next = new ListNode(0);
            }
            if (j->next == nullptr) {
                j->next = new ListNode(0);
            }
            i = i->next;
            j = j->next;
        }
        i->next = new ListNode(0);
        j->next = new ListNode(0);

        ListNode* head = l1;
        while (l1 && l2) {
            int sum = l1->val + l2->val;
            if (sum < 10) {
                l1->val = sum;
            } else {
                l1->val = sum % 10;
                cout << l1->val << endl;
                l1->next->val = l1->next->val + 1;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        if (i->next->val == 0) {
            i->next = nullptr;
        }
        return head;
    }
};
