class Solution {
public:
    int returnToBoundaryCount(vector<int>& nums) {
        partial_sum(begin(nums), end(nums), begin(nums));
        return count(begin(nums), end(nums), 0);
    }
};