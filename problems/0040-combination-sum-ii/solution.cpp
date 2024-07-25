class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> out;
        vector<int> cur;
        sort(begin(candidates), end(candidates));
        dfs(out, 0, target, candidates, cur);
        return out;
    }
    void dfs(vector<vector<int>>& out, int idx, int target, vector<int>& candidates, vector<int>& cur) {
        if (target == 0) {
            out.push_back(cur);
            return;
        }
        if (target < 0) {
            return;
        }
        int prev = -1;
        for (int x = idx; x < candidates.size(); x++) {
            if (candidates[x] == prev) {
                continue;
            }
            cur.push_back(candidates[x]);
            dfs(out, x + 1, target - candidates[x], candidates, cur);
            cur.pop_back();
            prev = candidates[x];
        }
    }
};
