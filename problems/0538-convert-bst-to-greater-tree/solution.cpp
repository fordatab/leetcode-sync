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
    TreeNode* convertBST(TreeNode* root) {
        int v = s(root);
        dfs(root, v);
        return root;
    }
    void dfs(TreeNode* root, int& v) {
        if (!root) {
            return;
        }

        dfs(root->left, v);
        int t = root->val;
        root->val = v;
        v -= t;
        dfs(root->right, v);
    }

    int s(TreeNode* root) {
        if (!root) {
            return 0;
        }
        return root->val + s(root->left) + s(root->right);
    }
};