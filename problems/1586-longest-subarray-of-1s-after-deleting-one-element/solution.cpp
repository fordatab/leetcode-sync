class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int l = 0;
        int m = 0;
        int z_ct = 0;
        int out = 0;
        for (int r = 0; r < nums.size(); r++) {
            if (nums[r] == 0) {
                cout << "jew" << endl;
                z_ct++;
            } else {
                m++;
            }
            while (z_ct > 1 && l <= r) {
                cout << l << endl;
                if (nums[l] == 0) {
                    z_ct--;
                } else {
                    m--;
                }
                l++;
            }
            cout << m << endl;
            out = max(m, out);
        }
        if (out == nums.size()) {
            out--;
        }
        return out;
    }
};