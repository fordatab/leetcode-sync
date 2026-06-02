class Solution {
public:
    long long minOperations(vector<int>& nums) {
        long long out = 0;
        int prev = nums[0];
        for (int n : nums) {
            if (n < prev) {
                out += prev - n; 
            }
            prev = n;
        }
        return out;
    }
};