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
    int maxLevelSum(TreeNode* root) {
        if (!root) return {};
        int l = 1;
        int out = 1;
        queue<TreeNode*> q;
        q.push(root);
        int m = INT_MIN;
        while (!q.empty()) {
            int sum = 0;
            int size = q.size();
            for (int x = 0; x < size; x++) {
                TreeNode* a = q.front();
                if (a->left) {
                    q.push(a->left);
                } 
                if (a->right) {
                    q.push(a->right);
                }
                sum += a->val;
                q.pop();
            }
            if (sum > m) {
                m = sum;
                out = l;
            }
            l++;
        }
        return out;
    }
};