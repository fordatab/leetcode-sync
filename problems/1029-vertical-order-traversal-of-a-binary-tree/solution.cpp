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
    void dfs(TreeNode* root, map<int, vector<pair<int, int>>>& cols, int col, int row) {
        if (!root) return;
        cols[col].push_back({row, root->val});
        dfs(root->left, cols, col - 1, row + 1);
        dfs(root->right, cols, col + 1, row + 1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, vector<pair<int, int>>> cols;
        dfs(root, cols, 0, 0);
        vector<vector<int>> out;
        for (auto& p : cols) {
            sort(p.second.begin(), p.second.end());
            vector<int> colVals;
            for (auto& node : p.second) {
                colVals.push_back(node.second);
            }
            out.push_back(colVals);
        }

        return out;
    }
};