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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) {
            return nullptr;
        }
        ListNode* n = head;
        int s = 1;
        while (n->next) {
            n = n->next;
            s++;
        }
        if (s == 1) {
            return head;
        }
        cout << s << endl;
        k %= s;
        if (k == 0) {
            return head;
        }
        cout << k << endl;
        ListNode* r = head;
        for (int x = 0; x < s - k - 1; x++) {
            r = r->next;
        }
        cout << r->val << endl;
        cout << n->val << endl;

        ListNode* o = r;
        r = r->next;
        o->next = nullptr;
        n->next = head;
        // r = r->next;
        // cout << r->val << endl;
        return r;
    }
};