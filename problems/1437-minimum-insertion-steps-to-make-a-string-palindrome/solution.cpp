class Solution {
public:
    int minInsertions(string s) {
        int N = s.size();
        vector<vector<int>> dp(N, vector<int>(N));
        for (int len = 2; len <= N; len++) {
            for (int l = 0; l + len - 1 < N; l++) {
                int r = l + len - 1;
                if (s[l] == s[r]) {
                    dp[l][r] = dp[l+1][r-1];
                } else {
                    dp[l][r] = 1 + min(dp[l+1][r], dp[l][r-1]);
                }
            }
        }
        return dp[0][N-1]; 
    }
};