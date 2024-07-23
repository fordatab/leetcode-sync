class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;
        sort(begin(nums), end(nums));
        b(0, subset, nums, res);
        return res;
    }

    void b(int start, vector<int>& subset, vector<int>& nums, vector<vector<int>>& res) {
        if (start == nums.size()) {
            res.push_back(subset);
            return;
        }
        subset.push_back(nums[start]);
        b(start + 1, subset, nums, res);
        subset.pop_back();
        while (start + 1 < nums.size() && nums[start] == nums[start+1]) {
            start++;
        }
        b(start + 1, subset, nums, res);
    }
};
