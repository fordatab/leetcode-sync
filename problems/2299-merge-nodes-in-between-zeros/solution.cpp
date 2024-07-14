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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* a = head->next;
        int c = 0;
        ListNode dummy(0);
        ListNode* n = &dummy;
        while (a) {
            if (a->val != 0) {
                c+= a->val;
            } else {
                cout << c<< endl;
                n->next = new ListNode(c);
                n = n->next;
                c = 0;
            }
            a = a->next;
        }
        return dummy.next;
    }
};