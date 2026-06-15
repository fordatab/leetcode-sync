class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        vector<bool> dp(n, false);
        dp[0] = true;
        int reachable = 0; // Start with 0 available jumps
        
        for (int i = 1; i < n; i++) {
            // A new index enters the valid jump window
            if (i >= minJump && dp[i - minJump]) {
                reachable++;
            }
            
            // An old index falls out of the back of the jump window
            if (i > maxJump && dp[i - maxJump - 1]) {
                reachable--;
            }
            
            // If current spot is '0' and we have at least 1 valid spot to jump from
            if (s[i] == '0' && reachable > 0) {
                dp[i] = true;
            }
        }
        
        return dp[n - 1];
    }
};