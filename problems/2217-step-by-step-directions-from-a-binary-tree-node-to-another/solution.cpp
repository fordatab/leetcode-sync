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
    TreeNode* lowestCommonAncestor(TreeNode* root, int p, int q) {
        if (!root) {
            return nullptr;
        }
        if (root->val == p) {
            return root;
        }
        if (root->val == q) {
            return root;
        }
        auto l = lowestCommonAncestor(root->left, p, q);
        auto r = lowestCommonAncestor(root->right, p, q);
        if (l && r) {
            return root;
        }
        return l ? l : r;
    }
    void path(string& out, TreeNode* root, int find, string& p) {
        if (!root) {
            return;
        }
        if (root->val == find) {
            out = p; 
            return;
        }
        p.push_back('L');
        path(out, root->left, find, p);
        p.pop_back();
        p.push_back('R');
        path(out, root->right, find, p);
        p.pop_back();
    
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* lca = lowestCommonAncestor(root, startValue, destValue);
        cout << lca->val << endl;
        string p;
        string out;
        path(out, root, startValue, p);
        string out1;
                path(out1, root, destValue, p);

        cout << out << endl;
        int i = 0;
        while (i < out.size() and i < out1.size() and out[i] == out1[i]) {
            i++;
        }
        return string(out.size() - i, 'U') + out1.substr(i);
        return "";
    }
};