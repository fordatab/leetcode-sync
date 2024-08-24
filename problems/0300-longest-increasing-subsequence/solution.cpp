class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        int n = nums.size();
        for (int x = n-1; x > -1; x--) {
            for (int y = x + 1; y < n; y++) {
                if (nums[x] < nums[y]) {
                    dp[x] = max(dp[x], 1 + dp[y]);
                }
            }
        }
        return *max_element(begin(dp), end(dp));
    }
};
