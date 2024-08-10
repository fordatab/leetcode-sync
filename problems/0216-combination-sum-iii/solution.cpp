class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> out;
        vector<int> res;
        dfs(out, res, 1, n, k);
        return out;
    }

    void dfs(vector<vector<int>>& out, vector<int>& res, int x, int sum, int k) {
        if (res.size() == k && sum == 0) {
            out.push_back(res);
            return;
        }
        if (res.size() == k || sum < 0) {
            return;
        }
        for (int i = x; i <= 9; i++) {
            res.push_back(i);
            dfs(out, res, i + 1, sum - i, k);
            res.pop_back();
        }
    }
};