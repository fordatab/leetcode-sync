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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        int c = 1;
        ListNode* head = list1;
        ListNode* first;
        ListNode* last;
        while (list1) {
            if (c == a) {
                first = list1;
                cout << first->val << endl;
            }
            if (c == b + 1) {
                last = list1->next;
                cout << last->val << endl;
            }
            c++;
            list1 = list1->next;
        }
        first->next = list2;
        cout << first->next->val << endl;
        while (first->next) {
            first = first->next;
        }
        first->next = last;
        return head; 
    }
};