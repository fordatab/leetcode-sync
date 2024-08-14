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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<ListNode*> f;
        stack<ListNode*> s;
        ListNode* l = l1;
        ListNode* dummy = new ListNode(0, l1);
        ListNode* dummy1 = new ListNode(0, l2);
        l1 = dummy;
        l2 = dummy1;
        while (l1) {
            f.push(l1);
            l1 = l1->next;
        }
        while (l2) {
            s.push(l2);
            l2 = l2->next;
        }
        int carry = 0;
        while (!f.empty() && !s.empty()) {
            auto a = f.top();
            auto b = s.top();
            cout << a->val << " " << b->val << endl;
            f.pop();
            s.pop();
            int n = a->val + b->val + carry;
            a->val = n%10;
            carry = n/10;
        }
        ListNode* du = dummy;
        while (du) {
            cout << du->val << endl;
            du = du->next;
        } 
        if (!s.empty()) {
            cout << "a" << endl;
            cout << s.top()->val << endl;
            s.top()->next = dummy;
            while (!s.empty()) {
                auto a = s.top();
                cout << a->val << endl;
                s.pop();
                int n = carry + a->val;
                cout << n << endl;
                a->val = n%10;
                carry = n/10;
            }
            return dummy1->val ? dummy1 : dummy1->next; 
        } else {
            while (!f.empty()) {
                auto a = f.top();
                f.pop();
                int n = carry + a->val;
                a->val = n%10;
                carry = n/10;
            }
            return dummy->val ? dummy : dummy->next; 
        }
    }
};