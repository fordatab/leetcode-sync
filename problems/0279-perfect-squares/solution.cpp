class Solution {
public:
    int numSquares(int n) {
        // vector<int> squares;
        // for (int x = 1; x <= 100; x++) {
        //     squares.push_back(x*x);
        // }
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
        dp[1] = 1;
        // dp[2] = 2;
        // dp[3] = 3;
        // dp[4] = 1;
        for (int x = 2; x <= n; x++) {
            for (int y = 1; y * y <= x; y++) {
                dp[x] = min(dp[x], dp[x-y*y] + 1);
            }
        }

        return dp[n];
    }
};