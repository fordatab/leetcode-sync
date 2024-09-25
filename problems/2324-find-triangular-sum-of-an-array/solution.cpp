class Solution {
public:
    int triangularSum(vector<int>& nums) {
        while (nums.size() != 1) {
            vector<int> tmp; 
            for (int x = 0; x < nums.size() - 1; x++) {
                tmp.push_back((nums[x] + nums[x+1])%10);
            }
            nums = tmp;
        }
        return nums[0];
    }
};