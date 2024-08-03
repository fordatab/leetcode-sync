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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> out;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int s = q.size();
            double t = 0;
            for (int x = 0; x < s; x++) {
                TreeNode* top = q.front();
                q.pop();
                t += top->val;
                if (top->left) {
                    q.push(top->left);
                }
                if (top->right) {
                    q.push(top->right);
                }
            }
            out.push_back(t/s);
        }
        return out;
    }
};