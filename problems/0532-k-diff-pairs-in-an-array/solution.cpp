class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int l = 0, r = 0;
        int n = nums.size();
        int out = 0;

        while (r < n) {
            while (r < n && nums[r] - nums[l] < k) {
                r++;
            }
            while (l < r && nums[r] - nums[l] > k) {
                l++;
            }
            if (r < n && nums[r] - nums[l] == k && r != l) {
                out++;
                int val = nums[r];
                // skip duplicates for r
                while (r < n && nums[r] == val) r++;
                continue; // don’t r++ again at bottom
            }
            r++;
        }
        return out;
    }
};
