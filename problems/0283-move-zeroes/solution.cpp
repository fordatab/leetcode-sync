class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int l = 0;
        for (int x = 0; x < nums.size(); x++) {
            if (nums[x] == 0) {
                l++;
            } else {
                int tmp = nums[x];
                nums[x] = 0; 

                nums[x-l] = tmp;
            }
        }
    }
};