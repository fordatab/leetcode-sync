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
    bool hasCycle(ListNode* head) {
        if (!head) {
            return false;
        }
        ListNode* s = head;
        ListNode* f = head;
        while (f->next) {
            f = f->next->next;
            if (!f) {
                return false;
            }
            s = s->next;
            if (f == s) {
                return true;
            }
        }
        return false;
    }
};
