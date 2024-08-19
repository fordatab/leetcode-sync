class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        int out = 0;
        vector<vector<pair<int, bool>>> adj(n);
        for (auto c : connections) {
            adj[c[0]].push_back({c[1], true});
            adj[c[1]].push_back({c[0], false});
        }
        vector<int> v(n);
        v[0] = 1;
        return dfs(adj, {0, false}, v);
    
    }

    int dfs(vector<vector<pair<int, bool>>>& adj, pair<int, bool> p, vector<int>& v) {
        int out = 0;
        if (p.second == true) {
            out = 1;
        }
        cout << p.first << " " << p.second << endl;
        for (auto [a, b] : adj[p.first]) {
            if (!v[a]) {
                v[a] = 1;
                out += dfs(adj, {a, b}, v);
            }
        }
        return out;

    }
};