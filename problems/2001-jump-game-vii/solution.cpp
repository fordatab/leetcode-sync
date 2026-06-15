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
            // cout << i << " " <<  l << endl;
            if (i - l > maxJump) {
                if (dp[l]) {
                    reachable--;
                }
                l++;
            }
            if (i - r >= minJump) {
                if (dp[r]) {
                    reachable++;
                }
                r++;
            }
            // cout << reachable << endl;
            if ((s[i] == '0') and reachable) {
                dp[i] = true;
            }
        }
        // cout << endl;
        // for (auto b : dp) {
        //     cout << b << endl;
        // }
        return dp[n-1];
    }
};