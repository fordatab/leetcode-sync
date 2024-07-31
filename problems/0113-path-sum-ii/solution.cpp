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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> out;
        vector<int> path;
        dfs(root, targetSum, 0, out, path);
        return out;
    }

    void dfs(TreeNode* root, int targetSum, int sum, vector<vector<int>>& out, vector<int>& path) {
        if (!root) {
            return;
        }
        cout << root->val << endl;
        sum += root->val;
        path.push_back(root->val);
        if (!root->left && !root->right) {
            if (sum == targetSum) {
                out.push_back(path);
            }
        } else {
            dfs(root->left, targetSum, sum, out, path);
            dfs(root->right, targetSum, sum, out, path);
        }
        path.pop_back();
    }
};