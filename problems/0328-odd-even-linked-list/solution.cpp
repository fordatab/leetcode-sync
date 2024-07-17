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
    ListNode* oddEvenList(ListNode* head) {
        ListNode odds(0);
        ListNode* a = &odds;
        ListNode evens(0);
        ListNode* b = &evens;
        ListNode* curr = head;
        int c = 0;
        while (curr) {
            if (c % 2 == 0) {
                a->next = curr;
                a = a->next;
            } else {
                b->next = curr;
                b = b->next;
            }
            curr = curr->next;
            c++;
            cout << c << endl;

        }
        a->next = nullptr;
        b->next = nullptr;

        b = &evens;
        if (!a) {
            cout << " a" << endl;
        }
        a->next = b->next;
        cout << "b" << endl;
        if (odds.next) {
            cout << "c" << endl;
        }
        return odds.next;
    }
};