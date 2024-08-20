class Solution {
public:
    bool divisorGame(int n) {
        vector<int> dp(n+1);
        for (int x = 1; x < n + 1; x++) {
            for (int y = 1; y <= x/2; y++) {
                if (x % y == 0) {
                    dp[x] |= !dp[x-y];
                }
            }
        }
        return dp[n];
    }
};