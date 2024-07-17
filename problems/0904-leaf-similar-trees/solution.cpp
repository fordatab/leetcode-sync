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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> a;
        vector<int> b;
        leaves(root1, a);
        leaves(root2, b);
        return a == b;
    }

    void leaves(TreeNode* root, vector<int> &v) {
        if (!root) {
            return;
        }
        if (!root->left && !root->right) {
            v.push_back(root->val);
            return;
        }
        leaves(root->left, v);
        leaves(root->right, v);
    }
};