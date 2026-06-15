class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        vector<bool> dp(n);
        dp[0] = true;
        int l = 0;
        int r = 0;
        int reachable = 0;
        for (int i = 1; i < n; i++) {
            if (i - l > maxJump) {
                if (dp[l++]) reachable--;
            }
            if (i - r >= minJump) {
                if (dp[r++]) reachable++;
            }
            if ((s[i] == '0') and reachable) dp[i] = true;
        }
        return dp[n-1];
    }
};