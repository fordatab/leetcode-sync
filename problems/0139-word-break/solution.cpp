class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> dp(n + 1);
        dp[n] = true;
        for (int x = n-1; x > -1; x--) {
            for (auto w : wordDict) {
                if (x + w.size() <= n && s.substr(x, w.size()) == w) {
                    if (dp[x + w.size()]) {
                        dp[x] = true;
                        break;
                    }
                }
            }
        }
        return dp[0];
    }
};
