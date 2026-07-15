class Solution {
public:
    long long maximumOr(vector<int>& nums, int k) {
        vector<int> prefixOR = {0};
        vector<int> suffixOR = {0};
        int prefix = 0;
        for (int n : nums) {
            prefix |= n;
            prefixOR.push_back(prefix);  
        }
        int suffix = 0; 
        for (int i = nums.size() - 1; i >= 0; i--) {
            suffix |= nums[i];
            suffixOR.push_back(suffix);
        }
        reverse(suffixOR.begin(), suffixOR.end());
        long long out = 0;
        for (int i = 0; i < nums.size(); i++) {
            out = max(out, prefixOR[i] | (long long)nums[i] << k | suffixOR[i+1]);
        }
        return out;
    }
};