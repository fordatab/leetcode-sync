class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(rbegin(nums), rend(nums));
        int out = 0;
        for (int x = 0; x < nums.size()/2; x++) {
            out += min(nums[2*x], nums[2*x+1]);
        }
        return out;
    }
};