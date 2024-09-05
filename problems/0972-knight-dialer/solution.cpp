class Solution {
public:
    int knightDialer(int n) {
        const int mod = 1000000007;
        vector<vector<long long>> dp(n+1, vector<long long>(10, 0));
        
        // Initialize the dp array for the first step
        for (int x = 0; x < 10; x++) {
            dp[1][x] = 1;
        }
        
        // For each step from 2 to n, calculate the possible dialings
        for (int x = 2; x <= n; x++) {
            dp[x][0] = (dp[x-1][4] + dp[x-1][6]) % mod;
            dp[x][1] = (dp[x-1][6] + dp[x-1][8]) % mod;
            dp[x][2] = (dp[x-1][7] + dp[x-1][9]) % mod;
            dp[x][3] = (dp[x-1][4] + dp[x-1][8]) % mod;
            dp[x][4] = ((dp[x-1][3] + dp[x-1][9]) % mod + dp[x-1][0]) % mod;
            dp[x][6] = ((dp[x-1][1] + dp[x-1][7]) % mod + dp[x-1][0]) % mod;
            dp[x][7] = (dp[x-1][2] + dp[x-1][6]) % mod;
            dp[x][8] = (dp[x-1][1] + dp[x-1][3]) % mod;
            dp[x][9] = (dp[x-1][2] + dp[x-1][4]) % mod;
        }
        
        // Sum up all possibilities from the last step
        long long result = 0;
        for (int x = 0; x < 10; x++) {
            result = (result + dp[n][x]) % mod;
        }
        return static_cast<int>(result);
    }
};