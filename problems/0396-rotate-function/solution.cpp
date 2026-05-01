class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int cur = 0;
        for (int i = 0; i < nums.size(); i++) {
            cur += nums[i] * i;
        }  
        int out = cur;
        for (int i = nums.size() - 1; i > 0; i--) {
            cur -= nums[i] * nums.size();
            cur += sum;
            out = max(out, cur); 
        }
        return out;
    }
};