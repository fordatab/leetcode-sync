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
    vector<vector<int>> levelOrder(Node* root) {
        if (!root) return {};
        vector<vector<int>> out;
        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            vector<int> o;
            int size = q.size();
            for (int x = 0; x < size; x++) {
                Node* a = q.front();
                for (Node* a : a->children) {
                    q.push(a);
                }
                o.push_back(a->val);
                q.pop();
            }
            out.push_back(o);
        }
        return out;
    }
};

