class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int prefix = 0;
        unordered_map<int, int> pre;
        for (int i = 0; i < n; i++) {
            prefix += nums[i];
            prefix %= k;
            pre[prefix] = i;
        }

        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (pre[sum] - i > 0) {
                return true;                 
            }
            sum += nums[i];
            sum %= k;
        }
        return false;
        
    }
};