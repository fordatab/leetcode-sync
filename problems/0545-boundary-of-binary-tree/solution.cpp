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
    void left(TreeNode* root, vector<int>& v) {
        if (!root) {
            return;
        }
        // has child
        if (root->right or root->left) {
            if (!root->left) {
                // no left, right is added
                v.push_back(root->val);
                left(root->right, v);

            } else {
                v.push_back(root->val);
                left(root->left, v); 
            }
        }

    }
    void right(TreeNode* root, vector<int>& v) {
        if (!root) {
            return;
        }
        // has child
        if (root->right or root->left) {
            if (!root->right) {
                // no right, left is added
                v.push_back(root->val);
                right(root->left, v);

            } else {
                v.push_back(root->val);
                right(root->right, v); 
            }
        }

    }
    void leaves(TreeNode* root, vector<int>& v) {
        if (!root) {
            return; 
        }
        cout << root->val << endl;
        if (!root->left and !root->right) {
            v.push_back(root->val);

        }
        leaves(root->left, v);
        leaves(root->right, v);
    }
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        vector<int> l;
        vector<int> r;
        vector<int> lvs;
        left(root->left, l);
        right(root->right, r);
        leaves(root->left, lvs);
        leaves(root->right, lvs);
        cout << lvs.size() << " size " << endl;
        reverse(r.begin(), r.end());
        vector<int> out = {root->val};
        for (int x : l) {
            out.push_back(x);
        }
        for (int x : lvs) {
            out.push_back(x);
        }
        for (int x : r) {
            out.push_back(x);
        }
        return out; 
    }
};