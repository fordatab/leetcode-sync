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
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};
        vector<int> out;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            int o = 0;
            for (int x = 0; x < size; x++) {

                TreeNode* a = q.front();
                if (x == size-1) {
                    o = a->val;
                }
                if (a->left) {
                    q.push(a->left);
                } 
                if (a->right) {
                    q.push(a->right);
                }
                
                q.pop();
            }
            out.push_back(o);
        }
        return out;
    }
};
