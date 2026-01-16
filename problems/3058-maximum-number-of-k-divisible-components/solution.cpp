class Solution {
public:


    int dfs(int node, vector<vector<int>>& adj, vector<int>& values, int k, int& ct, vector<int>& vis) {
        // add to visited
        vis[node] = 1;
        // leaf
        int remain = values[node] % k;
        for (int n : adj[node]) {
            if (!vis[n]) {
                remain = (remain + dfs(n, adj, values, k, ct, vis)) % k;
            }
        }
        if (remain % k == 0) {
            ct++;
            return 0;
        } else {
            return remain;

        }
    }

    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> adj(n);
        for (auto e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        int ct = 0;
        vector<int> vis(n);
        dfs(0, adj, values, k, ct, vis);
        return ct;
    }
};