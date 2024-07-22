class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        unordered_set<int> s(begin(nums), end(nums));
        vector<int> res;
        vector<vector<int>> out;
        d(out, s, res);
        return out;
    }
    void d(vector<vector<int>>& out, unordered_set<int>& s, vector<int>& res) {
        if (s.size() == res.size()) {
            out.push_back(res);
            return;
        }
        for (int a : s) {
            bool g = true;
            for (int b : res) {
                if (a == b) {
                    g = false;
                }
            }
            if (!g) {
                continue;
            }
            res.push_back(a);
            d(out, s, res);
            res.pop_back();
        }
        return;
    }
};
