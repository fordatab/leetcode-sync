class Solution {
public:
    int dfs(vector<vector<int>>& g, vector<int>& memo, int n, vector<int>& time) {
        if (memo[n] != -1) {
            return memo[n];
        }
        // base case time[n]
        int base = time[n];
        int out = 0;
        for (int neigh : g[n]) {
            out = max(out, dfs(g, memo, neigh, time));
        }
        memo[n] = base + out;
        return memo[n];
    }

    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> g(n);
        for (auto v : relations) {
            g[v[0]-1].push_back(v[1]-1); 
        }
        vector<int> memo(n, -1);
        int out = 0;
        for (int x = 0; x < n; x++) {
            out = max(out, dfs(g, memo, x, time));

        }
        return out;
    }
};