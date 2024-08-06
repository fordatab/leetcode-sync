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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> m;
        for (vector<int> v : descriptions) {
            if (m.find(v[0]) == m.end()) {
                m[v[0]] = new TreeNode(v[0]);
            }
            if (m.find(v[1]) == m.end()) {
                    m[v[1]] = new TreeNode(v[1]);
                }
        }
        unordered_map<int, TreeNode*> cpy = m;
        for (vector<int> v : descriptions) {
            if (v[2]) {
                m[v[0]]->left = m[v[1]];
            } else {
                m[v[0]]->right = m[v[1]];
            }
            if (cpy.find(v[1]) != cpy.end()) {
                cpy.erase(v[1]);
            }
        }
        return cpy.begin()->second;
    }
};