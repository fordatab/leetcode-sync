class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>> (2, vector<int> (3)));//
        dp[n-1][0][0] = 0;
        dp[n-1][1][0] = prices[n-1];
        dp[n-1][0][1] = 0;
        dp[n-1][1][1] = prices[n-1];
        dp[n-1][0][2] = 0;
        dp[n-1][1][2] = 0;
        
        for (int x = n - 2; x > -1; x--) {
            for (int t = 0; t < 3; t++) {
                // do nothing
                if (t == 2) {
                    dp[x][0][2] = dp[x+1][0][2];
                }
                if (t == 1) {
                    dp[x][0][1] = max(dp[x+1][0][1], dp[x+1][1][1] - prices[x]);
                    dp[x][1][1] = max(dp[x+1][1][1], dp[x+1][0][2] + prices[x]);
                }   

                if (t == 0) {
                    dp[x][0][0] = max(dp[x+1][0][0], dp[x+1][1][0] - prices[x]);
                    dp[x][1][0] = max(dp[x+1][1][0], dp[x+1][0][1] + prices[x]);
                }

                // do something
            }
        }

        return dp[0][0][0];
    }
};