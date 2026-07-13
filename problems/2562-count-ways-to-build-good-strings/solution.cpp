class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high + 1);
        dp[0] = 1;
        int MOD = 1e9 + 7;
        for (int i = 1; i <= high; i++) {
            if (i - zero >= 0) {
                dp[i]+= dp[i - zero]; 
            }
            if (i - one >= 0) {
                dp[i]+=dp[i-one];
            }
            dp[i] %= MOD;
        }
        int sum = 0;
        for (int i = low; i <= high; i++) {
            sum += dp[i];
            sum %= MOD;
        }
        return sum;
    }
};