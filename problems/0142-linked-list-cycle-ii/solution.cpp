/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head) {
            return nullptr;
        }
        ListNode* s = head;
        ListNode* f = head;
        while (f->next && f->next->next) {
            f = f->next->next;
            s = s->next;
            if (f == s) {
                while (head != f) {
                    head = head->next;
                    f = f->next;
                }
                return f;
            }
        }
        return nullptr;        
    }
};


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

