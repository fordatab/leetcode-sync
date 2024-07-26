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
    int deepestLeavesSum(TreeNode* root) {
        int d = depth(root);
        // cout << d << endl;
        return dfs(root, d);
    }

    int dfs(TreeNode* root, int d) {
        if (!root) {
            return 0;
        }
        if (!root->left && !root->right && d == 1) {
            return root->val;
        }
        return dfs(root->left, d - 1) + dfs(root->right, d - 1);
    }
    int depth(TreeNode* root) {
        if (!root) {
            return 0;
        }
        return 1 + max(depth(root->left), depth(root->right));
    }
};