class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int> (n));
        // dp[0][0] = grid[0][0];
        for (int x = 0; x < m; x++) {
            for (int y = 0; y < n; y++) {
                if (!x && !y) {
                } else if (!x) {
                    dp[x][y] = dp[x][y-1];
                } else if (!y) {
                    dp[x][y] = dp[x-1][y];
                } else {
                    dp[x][y] = min(dp[x-1][y], dp[x][y-1]);
                }
                dp[x][y] += grid[x][y];
            }
        }
        return dp[m-1][n-1];
    }
};