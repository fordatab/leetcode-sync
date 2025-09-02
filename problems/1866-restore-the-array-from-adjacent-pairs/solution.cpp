class Solution {
public:
    void dfs(unordered_map<int, vector<int>>& adj, unordered_map<int, bool>& vis, vector<int>& out, int s) {
        vis[s] = true;
        out.push_back(s);
        for (auto a : adj[s]) {
            if (!vis[a]) {
                dfs(adj, vis, out, a);
            }
        }
    }


    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>> adj;
        unordered_map<int, bool> vis;
        for (auto v : adjacentPairs) {
            vis[v[0]] = false;
            vis[v[1]] = false;
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        int start;
        for (auto [a, b] : adj) {
            if (b.size() == 1) {
                start = a;
            }
        }
        vector<int> out;
        dfs(adj, vis, out, start);
        return out;
        

    }
};