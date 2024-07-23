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
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(0, head);
        ListNode* a = &dummy;
        ListNode* n = head;
        while (n && n->next) {
            ListNode* tmp = n->next->next;
            a->next = n->next;
            n->next->next = n;
            n->next = tmp;
            a = n;
            n = n->next;
        }
        return dummy.next;
    }
};