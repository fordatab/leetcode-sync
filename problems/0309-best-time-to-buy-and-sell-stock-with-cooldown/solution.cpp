class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2));
        dp[n-1][0] = 0;
        dp[n-1][1] = prices[n-1];
        for (int x = n-2; x > -1; x--) {
            dp[x][0] = max(dp[x+1][0], -prices[x] + dp[x+1][1]);
            dp[x][1] = max(dp[x+1][1], prices[x] + dp[x+2][0]);
        }


        return dp[0][0];
    }
};
