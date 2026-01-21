class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ct = 0;
        int cur = 0;
        for (int i : nums) {
            if (i == 1) {
                cur++;
            } else {
                cur = 0;
            }
            ct = max(ct, cur);
        }
        return ct;
    }
};