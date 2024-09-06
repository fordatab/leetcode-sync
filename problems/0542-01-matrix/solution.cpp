class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> dp(m, vector<int> (n, 10000));
        for (int x = 0; x < m; x++) {
            for (int y = 0; y < n; y++) {
                if (mat[x][y]) {
                    if (x < m -1) {
                        dp[x][y] = min(dp[x][y], dp[x+1][y] + 1);        
                    }
                    if (x > 0) {
                        dp[x][y] = min(dp[x][y], dp[x-1][y] + 1);        
                    }
                    if (y < n -1) {
                        dp[x][y] = min(dp[x][y], dp[x][y+1] + 1);        
                    }
                    if (y > 0) {
                        dp[x][y] = min(dp[x][y], dp[x][y-1] + 1);        

                    }

                } else {
                    dp[x][y] = 0;
                }
            }
        }
        for (int x = m-1; x >= 0; x--) {
            for (int y = 0; y < n; y++) {
                if (mat[x][y]) {
                    if (x < m -1) {
                        dp[x][y] = min(dp[x][y], dp[x+1][y] + 1);        
                    }
                    if (x > 0) {
                        dp[x][y] = min(dp[x][y], dp[x-1][y] + 1);        
                    }
                    if (y < n -1) {
                        dp[x][y] = min(dp[x][y], dp[x][y+1] + 1);        
                    }
                    if (y > 0) {
                        dp[x][y] = min(dp[x][y], dp[x][y-1] + 1);        

                    }

                } else {
                    dp[x][y] = 0;
                }
            }
        }
        for (int x = 0; x < m; x++) {
            for (int y = n-1; y >= 0; y--) {
                if (mat[x][y]) {
                    if (x < m-1) {
                        dp[x][y] = min(dp[x][y], dp[x+1][y] + 1);        
                    }
                    if (x > 0) {
                        dp[x][y] = min(dp[x][y], dp[x-1][y] + 1);        
                    }
                    if (y < n-1) {
                        dp[x][y] = min(dp[x][y], dp[x][y+1] + 1);        
                    }
                    if (y > 0) {
                        dp[x][y] = min(dp[x][y], dp[x][y-1] + 1);        

                    }

                } else {
                    dp[x][y] = 0;
                }
            }
        }
        for (int x = m-1; x >= 0; x--) {
            for (int y = n-1; y >= 0; y--) {
                if (mat[x][y]) {
                    if (x < m-1) {
                        dp[x][y] = min(dp[x][y], dp[x+1][y] + 1);        
                    }
                    if (x > 0) {
                        dp[x][y] = min(dp[x][y], dp[x-1][y] + 1);        
                    }
                    if (y < n-1) {
                        dp[x][y] = min(dp[x][y], dp[x][y+1] + 1);        
                    }
                    if (y > 0) {
                        dp[x][y] = min(dp[x][y], dp[x][y-1] + 1);        

                    }

                } else {
                    dp[x][y] = 0;
                }
            }
        }
        return dp;
    }
};