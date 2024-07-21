class Solution {
public:
    int tribonacci(int n) {
        vector<int> dp(n+3);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;
        for (int x = 3; x < n + 1; x++) {
            dp[x] = dp[x-1] + dp[x-2] + dp[x-3];
        }
        return dp[n];
    }
};