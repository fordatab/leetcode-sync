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
    vector<int> nextLargerNodes(ListNode* head) {
        stack<pair<int, int>> stk;

        int sz = 0;
        for (ListNode* t = head; t; t = t->next) {
            sz++;
        }
        vector<int> out(sz);
        cout << sz;
        int i = 0;
        for (head; head; head = head->next) {
            while (!stk.empty() && stk.top().first < head->val) {
                out[stk.top().second] = head->val;
                stk.pop();
            }
            stk.push({head->val, i++});
        }
        return out;
    }
};