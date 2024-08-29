class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool> (n + 1));
        dp[m][n] = true;
        for (int i = m; i > -1; i--) {
            for (int j = n - 1; j > -1; j--) {
                bool match = (i < m && (s[i] == p[j] || p[j] == '.'));
                if (j + 1 < n && p[j+1] == '*') {
                    dp[i][j] = dp[i][j+2];
                    if (match) {
                        dp[i][j] = dp[i][j] || dp[i+1][j];
                    }
                } else if (match) {
                    dp[i][j] = dp[i+1][j+1];
                }
            }
        }
        return dp[0][0];
    }
};
