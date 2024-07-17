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
    int goodNodes(TreeNode* root) {
        return dfs(root, root->val);
    }
    int dfs(TreeNode* root, int m) {
        if (!root) {
            return 0;
        }
        int i = 0;
        if (root->val >= m) {
            i = 1;
            m = root->val;
        }
        i += dfs(root->left, m);
        i += dfs(root->right, m);
        return i;
    }
};
