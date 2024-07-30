class Solution {
public:
    int maxProduct(vector<int>& nums) {
        double res = nums[0];
        double curMin = 1, curMax = 1;

        for (int n : nums) {
            double tmp = curMax * n;
            curMax = max(max(tmp, n * curMin), (double)n);
            curMin = min(min(tmp, n * curMin), (double)n);
            res = max(res, curMax);
        }
        return (int)res;
    }
};
