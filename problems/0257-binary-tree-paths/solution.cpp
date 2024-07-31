class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> out;
        vector<string> path;
        dfs(root, path, out);
        return out;
    }
    
    void dfs(TreeNode* root, vector<string>& path, vector<string>& out) {
        if (!root) return;
        
        path.push_back(to_string(root->val));
        
        if (!root->left && !root->right) {
            out.push_back(join(path, "->"));
        } else {
            dfs(root->left, path, out);
            dfs(root->right, path, out);
        }
        
        path.pop_back();
    }
    
    string join(const vector<string>& v, string delimiter) {
        string result;
        for (size_t i = 0; i < v.size(); ++i) {
            if (i > 0) result += delimiter;
            result += v[i];
        }
        return result;
    }
};