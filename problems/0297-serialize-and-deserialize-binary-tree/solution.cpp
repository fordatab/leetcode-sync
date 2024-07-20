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
#define DELIM ','
#define NUL "N"
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string str = "";
        dfs(root, str);
        return str;
    }

    void dfs(TreeNode* root, string& str) {
        if (!root) {
            str += NUL;
            str += DELIM;
            return;
        }
        str += to_string(root->val) + DELIM;
        dfs(root->left, str);
        dfs(root->right, str);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> vals = split(data, ',');
        int i = 0;
        return dfd(vals, i);
    }

    TreeNode* dfd(vector<string>& vals, int& i) {
        if (vals[i] == NUL) {
            i++;
            return nullptr;
        }
        TreeNode* node = new TreeNode(stoi(vals[i]));
        i++;
        node->left = dfd(vals, i);
        node->right = dfd(vals, i);
        return node;
    }

    vector<string> split(const string &s, char delim) {
        vector<string> elems;
        stringstream ss(s);
        string item;
        while (getline(ss, item, delim)) {
            elems.push_back(item);
        }
        return elems;
    }

};
