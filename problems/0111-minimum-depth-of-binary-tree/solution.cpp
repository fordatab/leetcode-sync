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
    int minDepth(TreeNode* root) {
        int m = INT_MAX;
        dfs(root, m, 1);
        return m;
    }

    void dfs(TreeNode* root, int& m, int d) {
        if (!root) {
            if (d == 1) {
                m = 0;
            }
            return;
        }
        if (!root->left && !root->right) {
            m = min(d, m);
        }
        dfs(root->left, m, d + 1);
        dfs(root->right, m, d + 1);

    } 
};