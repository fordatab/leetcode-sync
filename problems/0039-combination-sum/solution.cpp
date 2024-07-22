class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> curr;
        h(res, curr, nums, target, 0);
        return res;
    }

    void h(vector<vector<int>>& res, vector<int>& curr, vector<int>& nums, int target, int i) {
        if (target == 0) {
            res.push_back(curr);
            return;
        }
        if (i >= nums.size() || target < 0) {
            return;
        }
        curr.push_back(nums[i]);
        h(res, curr, nums, target - nums[i], i);
        curr.pop_back();
        h(res, curr, nums, target, i + 1);
        return;
    }
};
