class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int out = 0;
        int n = nums.size();
        for (int x = 0; x < nums.size(); x++) {
            if (n % (x+1) == 0) {
                out += nums[x] * nums[x];
            }
        }
        return out;
    }
};