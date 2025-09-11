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
    int closestValue(TreeNode* root, double target) {
        int closest = root->val;
        dfs(closest, target, root);
        return closest;
    }

    void dfs(int& closest, double target, TreeNode* root) {
        if (!root) return;
        if (abs(root->val - target) < abs(closest - target)) {
            closest = root->val;
        }
        if (abs(root->val - target) == abs(closest - target)) {
            if (root->val < closest) {
                closest = root->val;
            } 
        }
        dfs(closest, target, root->right);  
        dfs(closest, target, root->left);  
    }
};