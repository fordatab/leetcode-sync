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
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> v;
        if (!root) return v;
        
        stack<TreeNode *> s;
        s.push(root);
        
        TreeNode *p = NULL;
        while(!s.empty()) {
            p = s.top();
            s.pop();
            v.insert(v.begin(), p->val);
            if (p->left) s.push(p->left);
            if (p->right) s.push(p->right);
        }
        
        return v;
    }
};