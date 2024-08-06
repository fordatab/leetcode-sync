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
    bool isCousins(TreeNode* root, int x, int y) {
        string px;
        string py;
        string a = "";
        string b = "";
        dfs(root, x, a, px);
        dfs(root, y, b, py);
        cout << px << endl;
        cout << py << endl;
        if (px.size() != py.size()) {
            return false;
        }
        px.pop_back();
        py.pop_back();
        return px != py;
    }

    void dfs(TreeNode* root, int target, string& p, string& out) {
        if (!root) {
            return;
        }
        if (root->val == target) {
            out = p;
            cout << p << endl;
            return;
        }
        p.push_back('0');
        dfs(root->left, target, p, out);
        p.pop_back();
        p.push_back('1');
        dfs(root->right, target, p, out);
        p.pop_back();
    }

    // string findPath(TreeNode* root, int target) {
    //     if (!root) return "";
        
    //     if (root->val == target) return "";
        
    //     string leftPath = findPath(root->left, target);
    //     if (!leftPath.empty()) return "0" + leftPath;
        
    //     string rightPath = findPath(root->right, target);
    //     if (!rightPath.empty()) return "1" + rightPath;
        
    //     return "";
    // }
};