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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> out;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            vector<int> o;
            int size = q.size();
            for (int x = 0; x < size; x++) {
                TreeNode* a = q.front();
                if (a->left) {
                    q.push(a->left);
                } 
                if (a->right) {
                    q.push(a->right);
                }
                o.push_back(a->val);
                q.pop();
            }
            out.push_back(o);
        }
        return out;
    }
};
