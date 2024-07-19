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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* first = head;
        ListNode* second = head->next;
        while (second) {
            int g = __gcd(first->val, second->val);
            first->next = new ListNode(g, second);
            first = first->next->next;
            second = second->next;
        }
        return head;
    }
};