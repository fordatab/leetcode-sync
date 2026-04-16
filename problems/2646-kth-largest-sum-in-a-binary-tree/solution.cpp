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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long> levels;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int ct = q.size();
            long long sum = 0;
            while (ct--) {
                TreeNode* f = q.front(); q.pop();
                sum += f->val;
                if (f->right != nullptr) q.push(f->right);
                if (f->left != nullptr) q.push(f->left);
            }
            levels.push_back(sum);
        }
        sort(levels.rbegin(), levels.rend());
        for (int l : levels) {
            // cout << l << endl;
        }
        return k > levels.size() ? -1 : levels[k-1];
    }
};