class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>> (2, vector<int> (k+1)));
        for (int i = 0; i < k; i++) {
            dp[n-1][1][i] = prices[n-1];
        }
        // dp[n-1][1][0] = prices[n-1];
        // dp[n-1][1][1] = prices[n-1];

        
        for (int x = n - 2; x > -1; x--) {
            for (int t = 0; t < k; t++) {
                dp[x][0][t] = max(dp[x+1][0][t], dp[x+1][1][t] - prices[x]);
                dp[x][1][t] = max(dp[x+1][1][t], dp[x+1][0][t+1] + prices[x]);
            }
            dp[x][0][k] = dp[x+1][0][k];
        }

        return dp[0][0][0];
    }
};