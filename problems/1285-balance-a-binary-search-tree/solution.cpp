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
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> v;
        inorder(root, v);
        return create(v, 0, v.size() - 1);
    }

    void inorder(TreeNode* root, vector<int>& v) {
        if (!root) {
            return;
        }
        inorder(root->left, v);
        v.push_back(root->val);
        inorder(root->right, v);
        return;
    }

    TreeNode* create(vector<int>& v, int l, int r) {
        if (l > r) {
            return nullptr;
        }
        int mid = (r - l)/2 + l;
        TreeNode* root = new TreeNode(v[mid]);
        root->left = create(v, l, mid - 1);
        root->right = create(v, mid + 1, r);
        return root;
    }
};