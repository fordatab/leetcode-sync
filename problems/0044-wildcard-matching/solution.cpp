class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        vector<vector<bool>> dp(n + 1, vector<bool> (m + 1));
        dp[0][0] = true;
        for (int x = 1; x <= n; x++) {
            if (p[x-1] == '*') {
                int y = 1;
                // find first index where dp is true
                while ((!dp[x - 1][y - 1]) and (y < m + 1)) {
                    y++;
                }
                // ignore the * case 
                dp[x][y - 1] = dp[x-1][y-1];

                // match all subsequent case
                while (y < m + 1) {
                    dp[x][y++] = true;
                }

            } else if (p[x-1] == '?') {
                // single wild, match one
                for (int y = 1; y <= m; y++) {
                    dp[x][y] = dp[x-1][y-1];
                } 
            } else {
                // no wild, need to match 
                for (int y = 1; y <= m; y++) {
                    dp[x][y] = dp[x-1][y-1] and (p[x-1] == s[y-1]);
                } 
            }
        }
        return dp[n][m];
    }
};