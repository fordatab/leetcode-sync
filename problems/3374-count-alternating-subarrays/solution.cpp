class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        long long out = 0;
        int l = 0;
        int prev = -1;
        for (int r = 0; r < nums.size(); r++) {
            if (nums[r] == prev) {
                l = r;
                // continue;
            }
            prev = nums[r];
            out += r - l + 1; 
        }
        return out; 
    }
};