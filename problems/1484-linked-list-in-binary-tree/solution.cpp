class Solution {
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        if (!head) return true;
        if (!root) return false;
        
        // Check if a path starting from the current root node matches the linked list
        if (matchPath(head, root)) return true;
        
        // If not, check in the left and right subtrees
        return isSubPath(head, root->left) || isSubPath(head, root->right);
    }
    
private:
    bool matchPath(ListNode* head, TreeNode* node) {
        if (!head) return true;
        if (!node) return false;
        if (head->val != node->val) return false;
        
        // Continue matching the next elements in the linked list
        return matchPath(head->next, node->left) || matchPath(head->next, node->right);
    }
};