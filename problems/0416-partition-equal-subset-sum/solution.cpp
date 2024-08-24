class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int target = accumulate(begin(nums), end(nums), 0);
        if (target % 2) {
            return false;
        }
        target /= 2;
        unordered_set<int> dp;
        dp.insert(0);
        for (int x = nums.size() - 1; x > -1; x--) {
            unordered_set<int> next;
            for (int i : dp) {
                if (i + nums[x] == target) {
                    return true;
                }
                next.insert(i + nums[x]);
                next.insert(i);
            }
            dp = next;
        }
        return false;
    }
};
