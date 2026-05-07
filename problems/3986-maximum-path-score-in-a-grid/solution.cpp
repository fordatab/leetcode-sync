class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k + 1, INT_MIN)));

        int dest_cost = (grid[m-1][n-1] > 0) ? 1 : 0;
        
        // OUTER LOOP: Remaining budget counting UP
        for (int c = 0; c <= k; c++) {
            
            // INNER LOOPS: Grid coordinates counting DOWN
            for (int x = m - 1; x >= 0; x--) {
                for (int y = n - 1; y >= 0; y--) {
                    
                    // Base case initialization directly inside the loop
                    if (x == m - 1 && y == n - 1) {
                        if (c >= dest_cost) dp[x][y][c] = grid[x][y];
                        continue;
                    }
                    
                    int cost = (grid[x][y] > 0) ? 1 : 0;
                    
                    // Only process if we have enough budget to step on this cell
                    if (c >= cost) {
                        int max_next = INT_MIN;
                        
                        if (x + 1 < m) max_next = max(max_next, dp[x + 1][y][c - cost]);
                        if (y + 1 < n) max_next = max(max_next, dp[x][y + 1][c - cost]);
                        
                        if (max_next != INT_MIN) {
                            dp[x][y][c] = grid[x][y] + max_next;
                        }
                    }
                }
            }
        }

        return dp[0][0][k] == INT_MIN ? -1 : dp[0][0][k];
    }
};