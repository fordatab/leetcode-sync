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
    int sumRootToLeaf(TreeNode* root) {
        vector<int> path;
        int total = 0;
        dfs(root, path, total);
        return total;
    }

    void dfs(TreeNode* root, vector<int>& path, int& total) {
        if (!root) {
            return;
        }
        path.push_back(root->val);
        if (!root->left && !root->right) {
            int t = 0;
            for (int a : path) {
                cout << a << " ";
                t *= 2;
                if (a) {
                    t++;
                }
            }
            cout << t << endl;
            total += t;
        } else {
        dfs(root->left, path, total);
        dfs(root->right, path, total);
        }

        path.pop_back();
    }
};