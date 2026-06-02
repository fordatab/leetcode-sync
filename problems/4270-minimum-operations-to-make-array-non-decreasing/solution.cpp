class Solution {
public:
    long long minOperations(vector<int>& nums) {
        long long out = 0;
        int prev = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < prev) {
                out += prev - nums[i]; 
            }
            prev = nums[i];
        }
        return out;
    }
};