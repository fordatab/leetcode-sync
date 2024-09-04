class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<int>> g(n, vector<int> (n, 1));
        for (const auto & v : mines) {
            g[v[0]][v[1]] = 0;
        }
        vector<vector<vector<int>>> dp(n + 2, vector<vector<int>> (n + 2, vector<int> (4)));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (g[i-1][j-1] != 0) {
                    dp[i][j][0] = dp[i-1][j][0] + 1;
                }
            }
        }
        for (int i = n; i > 0; i--) {
            for (int j = 1; j <= n; j++) {
                if (g[i-1][j-1] != 0) {
                    dp[i][j][1] = dp[i+1][j][1] + 1;
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = n; j > 0; j--) {
                if (g[i-1][j-1] != 0) {
                    dp[i][j][2] = dp[i][j+1][2] + 1;
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (g[i-1][j-1] != 0) {
                    dp[i][j][3] = dp[i][j-1][3] + 1;
                }
            }
        }
        int m = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (g[i][j] != 0) {
                    int order = min({dp[i+1][j+1][0], dp[i+1][j+1][1], dp[i+1][j+1][2], dp[i+1][j+1][3]});
                    m = max(m, order);
                }
            }
        }
        return m;



    }
};