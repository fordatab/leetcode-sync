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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> s(nums.begin(), nums.end());
        ListNode dummy(0);
        ListNode* node = &dummy;

        ListNode* h = head;
        while (h != nullptr) {
            if (s.find(h->val) != s.end()) {
                // do nothing
                cout << h->val << endl;
            } else {
                // cout << h->val << " a" << endl;
                node->next = new ListNode(h->val);
                node = node->next;
            }
            h = h->next;

        }
        return dummy.next;
        
    }
};