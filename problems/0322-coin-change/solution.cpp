class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int x = 0; x < amount + 1; x++) {
            for (int c : coins) {
                if (c <= x) {
                    dp[x] = min(dp[x], 1 + dp[x - c]);
                }
            }
        }
        return dp[amount] > amount ? -1 : dp[amount]; 
    }
};
