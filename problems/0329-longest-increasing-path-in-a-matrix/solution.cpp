class Solution {
private:
    pair<int, int> d[4] = {{1, 0}, {0, 1}, {-1, 0},  {0, -1}};
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int out = 0;
        vector<vector<int>> dp(m, vector<int> (n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                out = max(out, dfs(dp, matrix, i, j, m, n));
            }
        }
        return out;
    }


    int dfs(vector<vector<int>>& dp, vector<vector<int>>& matrix, int x, int y, int m, int n) {
        if (dp[x][y]) {
            return dp[x][y];
        }
        int res = 1;
        for (auto [dx, dy] : d) {
            int n_x = x + dx;
            int n_y = y + dy;
            if (n_x > -1 && n_x < m && n_y > -1 && n_y < n) {
                if (matrix[n_x][n_y] > matrix[x][y]) {
                    res = max(res, 1 + dfs(dp, matrix, n_x, n_y, m, n));
                }
            }
        }
        dp[x][y] = res;
        return res;
    }
};
