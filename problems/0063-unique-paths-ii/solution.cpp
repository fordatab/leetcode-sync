class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& g) {
        int m = g.size();
        int n = g[0].size();
        int dp[m][n];
        dp[0][0] = 1;
        for (int x = 0; x < m; x++) {
            for (int y = 0; y < n; y++) {
                if (g[x][y] == 1) {
                    dp[x][y] = 0;
                } else if (x && y) {
                    dp[x][y] = dp[x][y-1] + dp[x-1][y];
                } else if (!x && y) {
                    dp[x][y] = dp[x][y-1];
                } else if (x) {
                    dp[x][y] = dp[x-1][y];
                }
            }
        }
        return dp[m-1][n-1];
    }
};