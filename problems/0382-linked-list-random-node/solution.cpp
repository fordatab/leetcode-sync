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
private:
    ListNode* h;
public:
    Solution(ListNode* head) {
        h = head;
    }
    
    int getRandom() {
        int res = 1;
        int len = 1;
        ListNode* x = h;
        for (x ; x ; x = x->next) {
            if (rand() % len == 0) {
                res = x->val;
            }
            len++;
            // x = x->next;
        }
        // while (x) {

        // }
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */