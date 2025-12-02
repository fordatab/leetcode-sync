class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        const int NEG_INF = -1000000000; // -1e9

        // maxSteps = total moves from (0,0) to (n-1,n-1): 2*(n-1)
        int maxSteps = 2 * (n - 1);

        // dp[t][r1][r2]
        vector<vector<vector<int>>> dp(
            maxSteps + 1,
            vector<vector<int>>(n, vector<int>(n, NEG_INF))
        );

        if (grid[0][0] == -1) return 0;  // start blocked: no path
        dp[0][0][0] = grid[0][0];        // both at (0,0)

        for (int t = 1; t <= maxSteps; ++t) {
            for (int r1 = 0; r1 < n; ++r1) {
                int c1 = t - r1;
                if (c1 < 0 || c1 >= n) continue;
                if (grid[r1][c1] == -1) continue; // thorn

                for (int r2 = 0; r2 < n; ++r2) {
                    int c2 = t - r2;
                    if (c2 < 0 || c2 >= n) continue;
                    if (grid[r2][c2] == -1) continue; // thorn

                    int bestPrev = NEG_INF;

                    // (r1-1, c1) / (r2-1, c2)
                    if (r1 > 0 && r2 > 0)
                        bestPrev = max(bestPrev, dp[t - 1][r1 - 1][r2 - 1]);
                    // (r1-1, c1) / (r2, c2-1)
                    if (r1 > 0)
                        bestPrev = max(bestPrev, dp[t - 1][r1 - 1][r2]);
                    // (r1, c1-1) / (r2-1, c2)
                    if (r2 > 0)
                        bestPrev = max(bestPrev, dp[t - 1][r1][r2 - 1]);
                    // (r1, c1-1) / (r2, c2-1)
                    bestPrev = max(bestPrev, dp[t - 1][r1][r2]);

                    if (bestPrev == NEG_INF) continue; // impossible state

                    int gain = grid[r1][c1];
                    if (r1 != r2 || c1 != c2) {
                        // don’t double-count if they’re on the same cell
                        gain += grid[r2][c2];
                    }

                    dp[t][r1][r2] = max(dp[t][r1][r2], bestPrev + gain);
                }
            }
        }

        int ans = dp[maxSteps][n - 1][n - 1];
        return max(ans, 0); // if no valid path, return 0
    }
};
