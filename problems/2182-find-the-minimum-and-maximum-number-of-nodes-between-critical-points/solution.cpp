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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int mn = INT_MAX;
        int mx = -1;
        int prev_p = -1;
        int first_p = -1;
        int prev = head->val;

        int i = 0;
        for (head; head && head->next; head = head->next) {
            if ((prev < head->val && head->next->val < head->val) || (prev > head->val && head->next->val > head->val)) {
                if (first_p == -1) {
                    first_p = i;
                    prev_p = i;
                } else {
                    cout << i << " " << first_p << endl;
                    mx = max(mx, i - first_p);
                    mn = min(mn, i - prev_p);
                    prev_p = i;
                }
            }
                            i++;

                            prev = head->val;

        }
        if (mn == INT_MAX) {
            mn = -1;
        }
        return {mn, mx};
    }
};