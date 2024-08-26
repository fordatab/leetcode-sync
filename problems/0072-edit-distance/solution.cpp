class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> dp(m+1, vector<int> (n+1));
        for (int x = 0; x <= m; x++) {
            dp[x][n] = m-x;
        }        
        for (int x = 0; x <= n; x++) {
            dp[m][x] = n-x;
        }
        for (int i = m-1; i > -1; i--) {
            for (int j = n-1; j > -1; j--) {
                if (word1[i] == word2[j]) {
                    dp[i][j] = dp[i+1][j+1];
                } else {
                    dp[i][j] = 1 + min(dp[i][j+1], min(dp[i+1][j], dp[i+1][j+1]));
                }
            }
        }
        return dp[0][0];
    }
};
