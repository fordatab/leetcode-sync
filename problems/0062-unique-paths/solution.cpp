class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = 1;
        for (int x = 0; x < m; x++) {
            for (int y = 0; y < n; y++) {
                if (x > 0) {
                    dp[x][y] += dp[x-1][y];
                }
                if (y > 0) {
                    dp[x][y] += dp[x][y-1];
                }
            }
        }
        return dp[m-1][n-1];
    }
};
