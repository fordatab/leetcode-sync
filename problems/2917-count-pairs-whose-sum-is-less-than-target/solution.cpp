class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        sort(begin(nums), end(nums));
        int l = 0;
        int r = nums.size() - 1;
        int x = 0;
        while (l < r) {
            if (nums[l] + nums[r] < target) {
                x += r - l;
                l++;
            } else {
                r--;
            }
        }
        return x;
    }
};