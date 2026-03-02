class Solution {
public:
    long long maximumMedianSum(vector<int>& nums) {
        long long out = 0;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = n - 2; i >= n / 3; i -= 2) {
            out += nums[i];
        }
        return out;
    }
};