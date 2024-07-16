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
private:

    int dfs(TreeNode* root, int& d) {
        if (!root) {
            return 0;
        }
        int l = dfs(root->left, d);
        int r = dfs(root->right, d);
        d = max(l + r, d);
        return 1 + max(l , r);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int out = 0;
        dfs(root, out);
        return out;
    }

};
