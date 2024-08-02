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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    ListNode* current;
    int getLength(ListNode* head) {
        int len = 0;
        while (head) {
            len++;
            head = head->next;
        }
        return len;
    }
    
    TreeNode* convertListToBST(int left, int right) {
        if (left > right) return nullptr;
        
        int mid = left + (right - left) / 2;
        
        TreeNode* leftChild = convertListToBST(left, mid - 1);
        
        TreeNode* root = new TreeNode(current->val);
        root->left = leftChild;
        
        current = current->next;
        
        root->right = convertListToBST(mid + 1, right);
        
        return root;
    }
    
public:
    TreeNode* sortedListToBST(ListNode* head) {
        int length = getLength(head);
        current = head;
        return convertListToBST(0, length - 1);
    }
};