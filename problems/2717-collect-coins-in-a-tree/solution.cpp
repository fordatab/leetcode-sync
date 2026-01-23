class Solution {
public:
    int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) {
        int n = (int)coins.size();
        vector<vector<int>> adj(n);
        vector<int> deg(n, 0);

        for (auto& e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            deg[u]++; deg[v]++;
        }

        queue<int> q;

        // 1) prune leaves with no coins (iteratively)
        for (int i = 0; i < n; i++) {
            if (deg[i] == 1 && coins[i] == 0) q.push(i);
        }
        while (!q.empty()) {
            int u = q.front(); q.pop();
            deg[u] = 0; // removed
            for (int v : adj[u]) {
                if (deg[v] == 0) continue;
                deg[v]--;
                if (deg[v] == 1 && coins[v] == 0) q.push(v);
            }
        }

        // 2) remove two layers of leaves (regardless of coin)
        for (int i = 0; i < n; i++) {
            if (deg[i] == 1) q.push(i);
        }

        int rounds = 2;
        while (rounds--) {
            int sz = (int)q.size();
            while (sz--) {
                int u = q.front(); q.pop();
                if (deg[u] == 0) continue;
                deg[u] = 0;
                for (int v : adj[u]) {
                    if (deg[v] == 0) continue;
                    deg[v]--;
                    if (deg[v] == 1) q.push(v);
                }
            }
        }

        // 3) count remaining edges
        long long remainingEdges = 0;
        for (int i = 0; i < n; i++) {
            remainingEdges += deg[i];
        }
        remainingEdges /= 2;

        return (int)(remainingEdges * 2);
    }
};
