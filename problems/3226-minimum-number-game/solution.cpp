class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {

        vector<int> out(nums.size());
        sort(begin(nums), end(nums));
        for (int x = 0; x < nums.size(); x+=2) {
            out[x] = nums[x+1];
            out[x+1] = nums[x];
        }
        return out;
    }
};