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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* a = head;
        while (head && head->next) {
            ListNode* next = head->next;
            while (next && head->val == next->val) {
                next = next->next;
            }
            head->next = next;
            head = head->next;
        }
        return a;
    }
};