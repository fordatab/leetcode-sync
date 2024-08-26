class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size() + 1, vector<int> (amount + 1));
        for (int x = 0; x <= coins.size(); x++) {
            dp[x][0] = 1;
        }
        for (int x = 1; x < amount + 1; x++) {
            for (int i = coins.size()-1; i > -1; i--) {
                dp[i][x] += dp[i+1][x];
                if (coins[i] <= x) {
                    dp[i][x] += dp[i][x-coins[i]];

                }
            }
        }

        return dp[0][amount];
    }
};
