class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int out = 0;
        for (int x : nums) {
            if (x < k) {
                out++;
            }
        }
        return out;
    }
};