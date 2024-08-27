class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size();
        int n = s2.size();
        if (m + n != s3.size()) {
            return false;
        }
        vector<vector<bool>> dp(m + 1, vector<bool> (n+1));
        dp[m][n] = true;
        for (int x = m; x > -1; x--) {
            for (int y = n; y > -1; y--) {
                if (x < m && s1[x] == s3[x+y] && dp[x+1][y]) {
                    dp[x][y] = true;
                }
                if (y < n && s2[y] == s3[x+y] && dp[x][y+1]) {
                    dp[x][y] = true;
                }
            }
        }
        return dp[0][0];
    }
};
