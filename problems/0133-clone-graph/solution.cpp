/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> old;
        return dfs(node, old);
    }

    Node* dfs(Node* node, unordered_map<Node*, Node*>& old) {
        if (!node) {
            return nullptr;
        }
        if (old.count(node)) {
            return old[node];
        }
        Node* copy = new Node(node->val);
        old[node] = copy;
        for (Node* nei : node->neighbors) {
            copy->neighbors.push_back(dfs(nei, old));
        }

        return copy;
    }
};
