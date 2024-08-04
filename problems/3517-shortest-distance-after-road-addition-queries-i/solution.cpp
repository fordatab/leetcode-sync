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


class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> out;
        unordered_map<int, Node*> m;

        Node* root = new Node(0);
        m[0] = root;
        for (int x = 1; x < n; x++) {
            // cout << root->val << endl;
            root->neighbors.push_back(new Node(x));
            root = root->neighbors[0];
            m[x] = root;
        }
        // cout << root->val << endl;
        // cout << m.size() << endl;
        for (vector<int> v : queries) {
            Node* node = m[v[0]];
            node->neighbors.push_back(m[v[1]]);
            // cout << node->val << " " << node->neighbors.size() << endl;
            out.push_back(bfs(m[0], m[n-1], n));
        }
        return out;
    }

    int bfs(Node* begin, Node* end, int n) {
        queue<Node*> q;
        q.push(begin);
        int dist = 0;
        int out = -1;
        vector<int> visited(n, -1); 
        visited[0] = 0;
        while (!q.empty()) {
            Node* t = q.front();
            // cout << t->val << endl;
            q.pop();
            dist++;
            for (auto nei : t->neighbors) {
                // cout << nei->val << " nei vals\n";

                if (visited[nei->val] == -1) {
                    if (nei->val == n-1) {
                        out = dist;
                    }
                    visited[nei->val] = visited[t->val] + 1;
                    q.push(nei);
                }
            }
        }
        return visited[n-1];
    }

};

