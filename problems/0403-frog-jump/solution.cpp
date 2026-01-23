class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        
        // Check if first jump is possible
        if (stones[1] != 1) return false;
        
        // dp[i][k] = can reach stones[i] with last jump of k units
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        dp[1][1] = true;
        
        for (int i = 2; i < n; i++) {
            for (int j = 0; j < i; j++) {
                int jump = stones[i] - stones[j];
                if (jump > n) continue; // impossible to have jump > n
                
                // Check if we can reach stones[j] with jump-1, jump, or jump+1
                if (jump < n && dp[j][jump]) {
                    dp[i][jump] = true;
                }
                if (jump - 1 >= 0 && jump - 1 < n && dp[j][jump - 1]) {
                    dp[i][jump] = true;
                }
                if (jump + 1 < n && dp[j][jump + 1]) {
                    dp[i][jump] = true;
                }
            }
        }
        
        // Check if we can reach the last stone with any jump size
        for (int k = 0; k < n; k++) {
            if (dp[n-1][k]) return true;
        }
        return false;
    }
};