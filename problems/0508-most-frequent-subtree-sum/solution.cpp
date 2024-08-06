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
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int, int> m;
        vector<int> out;
        cout << dfs(root, m) << endl;
        int mx = INT_MIN;
        for (auto [a, b] : m) {
            mx = max(mx, b);
        }
        for (auto [a, b] : m) {
            if (b == mx) {
                out.push_back(a);
            }
        }
        return out;
    }

    int dfs(TreeNode* root, unordered_map<int, int>& freq) {
        if (!root) {
            return 0;
        }
        int l = dfs(root->left, freq);
        int r = dfs(root->right, freq);
        // cout << l + r << " " << root->val << endl;
        freq[l + r + root->val]++;
        return l + r + root->val;
    } 
};