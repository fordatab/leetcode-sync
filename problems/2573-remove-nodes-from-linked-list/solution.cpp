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
    ListNode* removeNodes(ListNode* head) {
        stack<ListNode*> s;
        ListNode dummy(-1, head);

        ListNode* h = &dummy;
        while (h) {
            s.push(h);
            h = h->next;
        }
        ListNode* prev;
        while (s.size() > 1) {
            ListNode* t = s.top();
            s.pop();
            if (prev && t->val < prev->val) {
                s.top()->next = prev;
                // prev = t;
            } else {
                prev = t;
            }
            // prev = t;
        }
        return dummy.next;
    }
};