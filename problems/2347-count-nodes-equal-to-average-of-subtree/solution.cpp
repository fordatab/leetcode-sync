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
    int averageOfSubtree(TreeNode* root) {
        int t = 0;
        auto a = avg(root, t);
        return t;
    }

    pair<int, int> avg(TreeNode* root, int& t) {
        if (!root) {
            return {0, 0};
        }
        auto l = avg(root->left, t);
        auto r = avg(root->right, t);
        int s = l.first + r.first + root->val;
        int n = l.second + r.second + 1;
        if (s/n == root->val) {
            t++;
        }
        return {s, n};
    }
};