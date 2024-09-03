class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int max_kadane = kadane(nums);  // Max sum of the normal subarray
        int total_sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            total_sum += nums[i];
            nums[i] = -nums[i];  // Inverting the array for minimum subarray sum
        }
        
        int max_wrap = total_sum + kadane(nums);  // Total sum minus the minimum subarray sum
        
        if (max_wrap == 0) return max_kadane;  // Handle edge case where all elements are negative
        
        return max(max_kadane, max_wrap);
    }
    
    int kadane(vector<int>& nums) {
        int max_sum = INT_MIN, curr_sum = 0;
        for (int num : nums) {
            curr_sum = max(curr_sum + num, num);
            max_sum = max(max_sum, curr_sum);
        }
        return max_sum;
    }
};
