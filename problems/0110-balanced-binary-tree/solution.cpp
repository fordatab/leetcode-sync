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
    pair<bool, int> dfs(TreeNode* root) {
        if (!root) {
            return {true, 0};
        }
        pair<bool, int> l = dfs(root->left);
        pair<bool, int> r = dfs(root->right);
        if (l.first && r.first && abs(l.second - r.second) < 2) {
                return {true, 1 + max(l.second, r.second)};
        } else {
            return {false, -1};
        }
    }
    bool isBalanced(TreeNode* root) {
        return dfs(root).first;
    }
};
