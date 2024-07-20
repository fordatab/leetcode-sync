class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> subset;
        vector<vector<int>> out;
        dfs(nums, out, subset, 0);
        return out;
    }

    void dfs(vector<int>& nums, vector<vector<int>>& out, vector<int>& subset, int i) {
        if (i >= nums.size()) {
            out.push_back(subset);
            return;
        }
        subset.push_back(nums[i]);
        dfs(nums, out, subset, i + 1);
        subset.pop_back();
        dfs(nums, out, subset, i + 1);
    }
};
