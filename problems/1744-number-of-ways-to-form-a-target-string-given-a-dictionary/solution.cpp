class Solution {
public:
    int numWays(vector<string>& words, string target) {
        vector<vector<int>> freq(words[0].size(), vector<int>(26));

        for (int y = 0; y < words[0].size(); y++) {
            for (int x = 0; x < words.size(); x++) {
                freq[y][words[x][y] - 'a']++;
            } 
        } 

        const int MOD = 1e9 + 7;
        int m = words[0].size();
        int n = target.size();

        vector<vector<long long>> dp(m + 1, vector<long long>(n + 1, 0));
        dp[0][0] = 1;

        for (int i = 0; i < m; ++i) {            // use first i columns to build dp[i][*]
            for (int j = 0; j <= n; ++j) {
                // Option 1: skip column i
                dp[i+1][j] = (dp[i+1][j] + dp[i][j]) % MOD;
            }
            for (int j = 0; j < n; ++j) {
                // Option 2: use column i to match target[j]
                long long ways = freq[i][ target[j] - 'a' ];
                if (ways > 0 && dp[i][j] > 0) {
                    dp[i+1][j+1] = (dp[i+1][j+1] + dp[i][j] * ways) % MOD;
                }
            }
        }

        return dp[m][n];

    }
};