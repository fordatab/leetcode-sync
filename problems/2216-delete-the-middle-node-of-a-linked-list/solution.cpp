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
    ListNode* deleteMiddle(ListNode* head) {
        if (!head) {
            return nullptr;
        }
        if (!head->next) {
            return nullptr;
        }
        ListNode dummy(0, head);
        ListNode* fast = head;
        ListNode* slow = &dummy;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return head;

    }
};