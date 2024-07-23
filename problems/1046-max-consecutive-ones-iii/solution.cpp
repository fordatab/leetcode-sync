class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0;
        int z_ct = 0;
        int o_ct = 0;
        int out = 0;
        for (int r = 0; r < nums.size(); r++) {
            if (!nums[r]) {
                z_ct++;
            } else {
                o_ct++;
            }
            while (z_ct > k) {
                if (!nums[l]) {
                    z_ct--;
                } else {
                    o_ct--;
                }
                l++;
            }
            out = max(o_ct, out);
        }
        return out + k > nums.size() ? nums.size() : out + k;
    }
};