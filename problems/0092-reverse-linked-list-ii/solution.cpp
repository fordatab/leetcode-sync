class Solution {
private:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr) {
            ListNode* next_node = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next_node;
        }
        return prev;  // Return the new head of the reversed list
    }

public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;  // No need to reverse if the list is empty or left == right

        // Create a dummy node to handle the case when left == 1
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;

        // Move `prev` to the node just before the `left` position
        for (int i = 1; i < left; ++i) {
            prev = prev->next;
        }

        // `s` will point to the start of the sublist to be reversed
        ListNode* s = prev->next;
        ListNode* f = s;

        // Move `f` to the `right` position
        for (int i = left; i < right; ++i) {
            f = f->next;
        }

        // Keep the node after the `right` position
        ListNode* n = f->next;

        // Detach the sublist and reverse it
        f->next = nullptr;
        ListNode* reversedHead = reverseList(s);

        // Reconnect the reversed sublist
        prev->next = reversedHead;
        s->next = n;  // `s` now points to the tail of the reversed sublist

        return dummy->next;  // Return the head of the modified list
    }
};
