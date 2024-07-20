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
    int pairSum(ListNode* head) {
        int x = 0;
        vector<int> vals;
        while (head) {
            vals.push_back(head->val);
            head = head->next;
            x++;
        }
        int out = 0;
        for (int y = 0; y < x; y++) {
            out = max(out, vals[y] + vals[x-y-1]);
        }
        return out;        
    }
};