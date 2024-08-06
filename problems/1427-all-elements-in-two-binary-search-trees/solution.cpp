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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> first;
        vector<int> second;
        dfs(root1, first);
        dfs(root2, second);
        int i = first.size()-1;
        int j = second.size()-1;
        int idx = i + j + 1;
        first.resize(idx + 1);
        while (j > -1) {
            if (i > -1 && first[i] > second[j]) {
                first[idx--] = first[i--];
            } else {
                first[idx--] = second[j--];
            }
        }
        return first;
    }

    void dfs(TreeNode* root, vector<int>& out) {
        if (!root) {
            return;
        }
        dfs(root->left, out);
        out.push_back(root->val);
        dfs(root->right, out);
    }
};