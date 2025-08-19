class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long out = 0;
        int n = nums.size();
        int l = 0;
        int r = 0;
        for (int r = 0;r < n; r++) {
            if (nums[r] == 0) {
                l = r;
                while (r + 1 < n and nums[r+1] == 0) {
                    r++;
                }
                long long length = r - l + 1 + 1; 
                // cout << r << " " << l << endl;
                out += ((length) * (length-1))/2;
            }
        }
        return out;
    }
};