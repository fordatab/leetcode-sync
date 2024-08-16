class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int, int> m;
        int ga = 0;
        for (int x : nums) {
            m[x]++;
            ga = max(ga, m[x]);
        }
        vector<vector<int>> out(ga);
        for (int x = 0; x < ga; x++) {
            for (auto &[a, b] : m) {
                if (b) {
                    out[x].push_back(a);
                    b--;
                }
            }
        }
        return out;
    }
};