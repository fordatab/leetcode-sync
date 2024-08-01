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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if (nums.size() == 0) {
            return nullptr;
        }
        int idx = 0;
        int m = 0;
        for (int x = 0; x < nums.size(); x++) {
            if (nums[x] > m) {
                idx = x;
                m = nums[x];
            }
        }
        TreeNode* root = new TreeNode(m);
        vector<int> l(begin(nums), begin(nums) + idx);
        root->left = constructMaximumBinaryTree(l);
        vector<int> r(begin(nums) + idx + 1, end(nums));
        root->right = constructMaximumBinaryTree(r);
        return root;
    }
};