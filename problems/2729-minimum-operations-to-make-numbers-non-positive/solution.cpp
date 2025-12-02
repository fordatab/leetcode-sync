class Solution {
public:
    bool check(vector<int>& nums, int x, int y, int ct) {
        long long needed = 0;
        for (int i = 0; i < nums.size(); i++) {
            long long remain = nums[i] - ct * (long long)y;
            if (remain > 0) {
                needed += ceil(remain / (1.0 * (x - y)));
            }
        }
        return needed <= ct;
    }

    int minOperations(vector<int>& nums, int x, int y) {
        int l = 0;
        int r = INT_MAX;
        while (l < r) {
            int mid = (r - l) /2 + l;
            if (check(nums, x, y, mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return r;
    }
};