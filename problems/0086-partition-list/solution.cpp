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
    ListNode* partition(ListNode* head, int x) {
        ListNode lt(-1);
        ListNode gte(-1);
        ListNode* l = &lt;
        ListNode* g = &gte;
        while (head) {
            if (head->val < x) {
                l->next = head;
                l = l->next;
            } else {
                g->next = head;
                g = g->next;
            }
            head = head->next;
        } 
        g->next = nullptr;
        // cout << l->next << endl;
        // cout << gte.next->val << endl; 
        l->next = gte.next;
        return lt.next;

    }
};