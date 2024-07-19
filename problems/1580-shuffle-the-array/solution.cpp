class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> out (2*n);
        for (int x = 0; x < n; x++) {
            out[2*x] = nums[x];
            out[2*x+1] = nums[x+n];
        }
        return out;
    }
};