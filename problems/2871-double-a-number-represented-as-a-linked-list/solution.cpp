class Solution {
public:
    ListNode* doubleIt(ListNode* head) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* a = dummy;
        stack<ListNode*> stk;
        
        while (a) {
            stk.push(a);
            a = a->next;
        }
        int carry = 0;
        while (!stk.empty()) {
            ListNode* t = stk.top();
            stk.pop();
            int n = t->val * 2 + carry;
            t->val = n % 10;
            carry = n / 10;
        }

        return dummy->val ? dummy : dummy->next;
    }
};