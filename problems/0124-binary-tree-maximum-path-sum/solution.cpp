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
    int maxPathSum(TreeNode* root) {
        int out = root->val;
        dfs(root, out);
        return out;

    }

    int dfs(TreeNode* root, int& i) {
        if (!root) {
            return 0; 
        }
        int l_m = max(dfs(root->left, i), 0);                
        int r_m = max(dfs(root->right, i), 0);
        i = max(i, root->val + l_m + r_m);

        return root->val + max(l_m, r_m);

    }
};
