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
    int getMinimumDifference(TreeNode* root) {
        int m = INT_MAX;
        TreeNode* prev = nullptr;
        dfs(root, prev, m);
        return m;
    }

    void dfs(TreeNode* root, TreeNode*& prev, int& m) {
        if (!root) {
            return;
        }
        dfs(root->left, prev, m);
        if (prev) {
            m = min(m, abs(root->val - prev->val));
        }
        prev = root;
        dfs(root->right, prev, m);
    }
};