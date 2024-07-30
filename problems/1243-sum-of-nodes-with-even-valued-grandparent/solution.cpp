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
    int sumEvenGrandparent(TreeNode* root) {
        return dfs(root, false, false);
    }
    
    int dfs(TreeNode* root, bool p, bool gp) {
        if (!root) {
            return 0;
        }
        int out = 0;
        if (gp) {
            out += root->val;
        }
        if (root->val % 2 == 0) {
            if (p) {
                return out + dfs(root->left, true, true) + dfs(root->right, true, true);
            } else {
                return out + dfs(root->left, true, false) + dfs(root->right, true, false);
            }
        } else {
            if (p) {
                return out + dfs(root->left, false, true) + dfs(root->right, false, true);
            } else {
                return out + dfs(root->left, false, false) + dfs(root->right, false, false);
            }
        }
    }
};