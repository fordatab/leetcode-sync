class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<long, int> dp;
        return bt(0, 0, nums, target, dp);
    }

    int bt(int i, int t, vector<int>& nums, int target, unordered_map<long, int>& dp) {
        if (i == nums.size()) {
            if (t == target) {
                return 1;
            } else {
                return 0;
            }
        }
        long key = static_cast<long>(i) << 32 | (t & 0xffffffffL);
        if (dp.find(key) != end(dp)) {
            return dp[key];
        }
        int ways = bt(i + 1, t + nums[i], nums, target, dp) + 
                bt(i + 1, t - nums[i], nums, target, dp);
        dp[key] = ways;
        return ways;
    }
};
