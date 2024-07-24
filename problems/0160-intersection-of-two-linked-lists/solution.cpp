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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int x = 0;
        int a = 0;
        int b = 0;
        ListNode* h = headA;
        while (h) {
            h = h->next;
            a++;
        }
        h = headB;
        while (h) {
            h = h->next;
            b++;
        }
        while (a != b) {
            if (a > b) {
                headA = headA->next;
                a--;
            } else {
                headB = headB->next;
                b--;               
            }
        }
        while (headA || headB) {
            if (headA == headB) {
                return headA;
            }
            if (!headA) {
                headB = headB->next;
            } else if (!headB) {
                headA = headA->next;
            } else if (x%2) {
                headA = headA->next;
            } else {
                headB = headB->next;
            }
            x++;
        }
        return nullptr;
    }
};