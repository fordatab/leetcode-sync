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
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode *prev = NULL;
        ListNode *curr = head;

        while (curr != NULL) {
            ListNode *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0);
        ListNode* a = &dummy;
        a->next = head;
        ListNode* first = a;
        for(int x = 0; x < k; x++) {
            first = first->next;
        }
        ListNode* second = a;

        int count = 0;
        while (first) {
            // cout << count << " " << first->val << endl;
            if (count % k == 0) {
                ListNode* next = first->next;
                ListNode* start = second->next;
                first->next = nullptr;
                // cout << start->val << " " << next->val << " " << second->val << " " << first->val << endl;

                reverseList(start);

                second->next = first;
                start->next = next;
                first = start;

            }
            first = first->next;
            second = second->next;
            count++;
        }
        return dummy.next;
    }
};
