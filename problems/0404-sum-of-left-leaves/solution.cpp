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
    int sumOfLeftLeaves(TreeNode* root) {
        int out = 0;
        dfs(root, false, out);
        return out;
    }

    void dfs(TreeNode* root, bool is_left, int& sum) {
        if (!root) {
            return;
        }
        if (is_left && !root->left && !root->right) {
            sum += root->val;
        }
        dfs(root->left, true, sum);
        dfs(root->right, false, sum);
    }
};