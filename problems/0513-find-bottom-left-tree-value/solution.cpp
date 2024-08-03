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
    int findBottomLeftValue(TreeNode* root) {
        int d = depth(root);
        cout << d << endl;
        queue<TreeNode*> q;
        int level = 1;
        q.push(root);
        while (!q.empty()) {
            int s = q.size();
            for (int x = 0; x < s; x++) {
                TreeNode* t = q.front();
                cout << t->val << endl;
                if (level == d) {
                    return t->val;
                }
                q.pop();
                if (t->left) {
                    q.push(t->left);
                }
                if (t->right) {
                    q.push(t->right);
                }

            }
            level++;
        }
        return -1;
    }

    int depth(TreeNode* root) {
        if (!root) {
            return 0;
        }
        return 1 + max(depth(root->left), depth(root->right));
    }
};