/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> out;
        dfs(out, root);
        return out;
    }

    void dfs(vector<int>& out, Node* root) {
        if (!root) {
            return;
        }
        out.push_back(root->val);
        for (Node* n : root->children) {
            dfs(out, n);
        }
    }
};