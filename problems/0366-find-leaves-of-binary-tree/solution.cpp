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

    int height(TreeNode* root, vector<vector<int>>& leaves) {
        if (!root) {
            return -1;
        }
        int r = height(root->right, leaves);
        int l = height(root->left, leaves);
        int h = max(l, r) + 1;
        if (h == leaves.size()) {
            leaves.push_back({});
        }
        leaves[h].push_back(root->val);
        return h;
    }
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> out;
        height(root, out);
        return out;
    }
};