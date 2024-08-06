class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> res;
        vector<vector<int>> out;
        unordered_map<int, int> used;
        for (int a : nums) {
            used[a]++;
        }
        d(out, used, res, nums);
        return out;
    }

private:
    void d(vector<vector<int>>& out, unordered_map<int, int>& used, vector<int>& res, const vector<int>& nums) {
        if (res.size() == nums.size()) {
            out.push_back(res);
            return;
        }
        for (auto [a, b] : used) {
            if (b == 0) {
                continue;
            }
            res.push_back(a);
            used[a]--;
            d(out, used, res, nums);
            res.pop_back();
            used[a]++;
        }
    }
};
