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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode dummy(0);
        ListNode* a = &dummy;
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>> > pq;
        for (ListNode* node : lists) {
                    cout << "a" << endl;

            while (node) {
                pq.push({node->val, node});
                node = node->next;
            }
        }
        while (!pq.empty()) {
            ListNode* top = pq.top().second;
            a->next = top;
            a = a->next;
            pq.pop();
                        cout << top->val << endl;

        }
        return dummy.next;
    }
};
