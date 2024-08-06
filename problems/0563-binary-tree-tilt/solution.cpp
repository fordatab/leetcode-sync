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
    int findTilt(TreeNode* root) {
        int out = 0;
        dfs(root, out);
        return out;
    }

    int dfs(TreeNode* root, int& out) {
        if (!root) {
            return 0;
        }
        int l = dfs(root->left, out);
        int r = dfs(root->right, out);
        out += abs(l-r);
        return root->val + l + r;
    }
};