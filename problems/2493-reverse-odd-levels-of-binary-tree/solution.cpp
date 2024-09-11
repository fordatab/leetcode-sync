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
    TreeNode* reverseOddLevels(TreeNode* root) {
        level_order(root->left, root->right, 1);
        return root;
    }

    void level_order(TreeNode* l, TreeNode* r, int lvl) {
        if (!l) {
            return;
        }
        if (lvl %2 ) {
            swap(l->val, r->val);
        }
        level_order(l->left, r->right, lvl + 1);
        level_order(l->right, r->left, lvl + 1);
    }
};