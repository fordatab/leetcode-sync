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
    int longestZigZag(TreeNode* root) {
        int r = dfs(root, true, -1);
        int l = dfs(root, false, -1);
        return max(l, r);
    }

    int dfs(TreeNode* root, bool is_right, int d) {
        if (!root) {
            return d;
        }
        if (is_right) {
            return max(dfs(root->left, false, d + 1), dfs(root->right, true, 0));
        } else {
            return max(dfs(root->left, false, 0), dfs(root->right, true, d + 1));
        }
    }
};