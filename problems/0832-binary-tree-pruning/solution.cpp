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
    TreeNode* pruneTree(TreeNode* root) {
        return dfs(root) ? root : nullptr;
    }

    bool dfs(TreeNode* root) {
        if (!root) {
            return false;
        }
        bool l = dfs(root->left);
        bool r = dfs(root->right);
        if (!l) {
            root->left = nullptr; 
        }
        if (!r) {
            root->right = nullptr;
        }
        return l or r or root->val == 1;
    } 
};