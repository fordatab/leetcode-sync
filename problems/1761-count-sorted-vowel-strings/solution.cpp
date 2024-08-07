class Solution {
public:
    int countVowelStrings(int n) {
        vector<vector<int>> dp(5, vector<int> (n + 1));
        dp[0][1] = 1; //a
        dp[1][1] = 1; //e
        dp[2][1] = 1; //i
        dp[3][1] = 1; //o    
        dp[4][1] = 1; //u
        for (int x = 2; x < n + 1; x++) {
            dp[0][x] = dp[0][x-1];
            dp[1][x] = dp[0][x-1] + dp[1][x-1];
            dp[2][x] = dp[0][x-1] + dp[1][x-1] + dp[2][x-1];
            dp[3][x] = dp[0][x-1] + dp[1][x-1] + dp[2][x-1] + dp[3][x-1];
            dp[4][x] = dp[0][x-1] + dp[1][x-1] + dp[2][x-1] + dp[3][x-1] + dp[4][x-1];
        }
        int out = 0;
        for (int x = 0; x < 5; x++) {
            out += dp[x][n];
        }
        return out;
    }
};