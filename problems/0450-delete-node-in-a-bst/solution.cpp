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
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* curr = root;
        TreeNode* parent = nullptr;
        
        // Find the node to delete
        while (curr && curr->val != key) {
            parent = curr;
            if (key < curr->val)
                curr = curr->left;
            else
                curr = curr->right;
        }
        
        if (!curr) return root;  // Node not found

        if (!curr->left && !curr->right) {
            if (curr == root) {
                delete root;
                return nullptr;
            }
            if (parent->left == curr)
                parent->left = nullptr;
            else
                parent->right = nullptr;
            delete curr;
        }

        else if (!curr->left || !curr->right) {
            TreeNode* child = curr->left ? curr->left : curr->right;
            if (curr == root) {
                delete root;
                return child;
            }
            if (parent->left == curr)
                parent->left = child;
            else
                parent->right = child;
            delete curr;
        }

        else {
            TreeNode* succParent = curr;
            TreeNode* succ = curr->right;
            
            while (succ->left) {
                succParent = succ;
                succ = succ->left;
            }
            
            curr->val = succ->val;
            
            if (succParent->left == succ)
                succParent->left = succ->right;
            else
                succParent->right = succ->right;
            
            delete succ;
        }
        return root;
    }
};