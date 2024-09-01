class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 2) return nums.size();
        
        int l = 2;  // Start from the third element
        for (int r = 2; r < nums.size(); r++) {
            if (nums[r] != nums[l-2]) {
                nums[l++] = nums[r];
            }
        }
        return l;
    }
};