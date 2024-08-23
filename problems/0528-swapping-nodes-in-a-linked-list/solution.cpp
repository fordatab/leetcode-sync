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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* p = head;
        int l = (-k)+1;
        int f = 1;
        ListNode* a;
        ListNode* b;

        ListNode* prev = head;
        while (p) {
            cout << l << endl;
            if (l++ > 0) {
                prev = prev->next;
            
                                cout << " a" << endl;

                // b = p;
            }
            if (f++ == k) {
                cout << " a" << endl;
                a = p;
            }

            p = p->next;
        }
        b = prev;
        cout << a->val << " " <<b->val << endl;
        int x = a->val;
        a->val = b->val;
        b->val = x;
        // swap(a->val, b->val);
        return head;
    }
};