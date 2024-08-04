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
    int sumNumbers(TreeNode* root) {
        int total = 0;
        dfs(0, total, root);
        return total;
    }

    void dfs(int cur, int& total, TreeNode* root) {
        if (!root) {
            return;
        }
        if (!root->left && !root->right) {
            cur *= 10;
            cur += root->val;
            total += cur;
            return;
        }
        cur *= 10;
        cur += root->val;
        cout << cur << endl;
        dfs(cur, total, root->left);
        dfs(cur, total, root->right);
    }
};