class Solution {
public:
    int helper(vector<int>& nums, int k) {
        int l = 0;
        unordered_map<int, int> freq;
        int out = 0;
        // int sz = 0; 
        for (int r = 0; r < nums.size(); r++) {
            freq[nums[r]]++;

            while (freq.size() > k) {
                freq[nums[l]]--;
                if (freq[nums[l]] == 0) {
                    freq.erase(nums[l]);
                    // sz--;
                }
                l++;
            }
            out += r - l + 1;
            
        }
        return out;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return helper(nums, k) - helper(nums, k - 1);
    }
};