class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int j = nums[0];
        for (int x = 1; x < nums.size(); x++) {
            j ^= nums[x];
        }
        return j;
    }
};