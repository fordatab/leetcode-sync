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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> out(k);
        int s = 0;
        ListNode* n = head;
        while (n) {
            n = n->next;
            s++;
        }
        int g = s/k;
        int h = s%k;
        cout << g << " " << h << endl;
        for (int x = 0; x < k; x++) {
            ListNode dummy(-1);
            ListNode* a = &dummy;
            // return {};
            if (head) {
                for (int i = 0; i < g; i++) {
                    a->next = head;
                    a = a->next;
                    head = head->next;
                    cout << " a" << endl;
                    a->next = nullptr;

                }
                // return {};
                if (h-- > 0) {
                    a->next = head;
                    head = head->next;
                    a->next->next = nullptr;
                }
                    // a->next->next = nullptr;

                out[x] = dummy.next;
            }

        }
        return out;
    }
};