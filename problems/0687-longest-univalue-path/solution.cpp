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
    int dfs(TreeNode* root, int& out) {
        if (!root) return 0;

        int l = dfs(root->left, out);
        int r = dfs(root->right, out);

        int leftPath = 0, rightPath = 0;

        if (root->left && root->left->val == root->val) {
            leftPath = l + 1;   // one more EDGE: root -> left
        }
        if (root->right && root->right->val == root->val) {
            rightPath = r + 1;  // one more EDGE: root -> right
        }

        out = max(out, leftPath + rightPath);  // path through root
        return max(leftPath, rightPath);       // best single branch downward
    }

    int longestUnivaluePath(TreeNode* root) {
        int out = 0;
        dfs(root, out);
        return out;
    }
};