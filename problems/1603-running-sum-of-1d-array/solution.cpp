class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int a = 0;
        for (int x = 0; x < nums.size(); x++) {
            nums[x] = nums[x] + a;
            a = nums[x];
        }
        return nums;
    }
};