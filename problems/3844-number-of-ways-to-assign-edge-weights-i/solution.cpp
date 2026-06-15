class Solution {
public:
    int dfs(int node, vector<vector<int>>& adj, int parent) {

        int depth = 0; 
        for (auto n : adj[node]) {

            if (n != parent) {
            depth = max(depth, dfs(n, adj, node));

            }
        }
        return depth + 1;

    }


    long long power(long long base, long long exp) {
    long long res = 1;
    long long mod = 1e9 + 7;
    base %= mod;
    while (exp > 0) {
        // If the current exponent bit is odd, multiply the base with the result
        if (exp % 2 == 1) res = (res * base) % mod;
        // Square the base and halve the exponent
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}


    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>> adj(n + 1, vector<int>());
        for (auto e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        } 
        int max_depth = dfs(1, adj, -1);

        return power(2, max_depth-2);

    }
};