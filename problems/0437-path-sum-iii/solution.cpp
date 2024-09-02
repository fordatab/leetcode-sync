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
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long, int> m;
        m[0] = 1;
        int out = 0;
        dfs(root, targetSum, out, m, 0);
        return out;

    }

    void dfs(TreeNode* root, int target, int& out, unordered_map<long, int>& m, long prefix) {
        if (!root) {
            return;
        }
        prefix += root->val;
        out += m[prefix-target];
        m[prefix]++;
        dfs(root->left, target, out, m, prefix);
        dfs(root->right, target, out, m, prefix);
        m[prefix]--;
    }

    
};