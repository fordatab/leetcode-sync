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
    ListNode* merge(ListNode* l1, ListNode* l2) {
		if(!l1) {
			return l2;
		}
		if(!l2) {
			return l1;
		} 
		if (l1->val <= l2->val) {
			l1->next = merge(l1->next, l2);
			return l1;
		} else {
			l2->next = merge(l1, l2->next);
			return l2;            
		}
	}
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        if (!head->next->next) {
            if (head->val > head->next->val) {
                head->next->next = head;
                ListNode* tmp = head->next;
                head->next = nullptr;
                return tmp;
            }
        }
        ListNode* prev = nullptr;
        ListNode* s = head;
        ListNode* f = head;
        while (f && f->next) {
            prev = s;
            s = s->next;
            f = f->next->next;
        }
        // cout << prev->val << endl;
        ListNode* r = prev->next;
        prev->next = nullptr;
        ListNode* l = head;
        cout << r->val << endl;
        cout << l->val << endl;
        r = sortList(r);
        l = sortList(l);
        ListNode* merged = merge(l, r);
        return merged;
    }
};