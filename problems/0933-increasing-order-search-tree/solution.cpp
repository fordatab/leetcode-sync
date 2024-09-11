class Solution {
private:
    TreeNode* newRoot = nullptr;  // This will store the root of the new tree
    TreeNode* prev = nullptr;     // This tracks the previously visited node

    // Helper function for in-order traversal and tree reconstruction
    void inorder(TreeNode* node) {
        if (!node) return;
        
        // Traverse the left subtree
        inorder(node->left);
        
        // Processing the current node
        if (prev) {
            // Link the current node to the right of the previous node
            prev->right = node;
        } else {
            // Set the new root when we reach the first node
            newRoot = node;
        }
        // Set the left of the current node to null
        node->left = nullptr;
        
        // Move the 'prev' pointer to the current node
        prev = node;
        
        // Traverse the right subtree
        inorder(node->right);
    }

public:
    TreeNode* increasingBST(TreeNode* root) {
        inorder(root);
        return newRoot;
    }
};