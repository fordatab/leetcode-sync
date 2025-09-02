class Solution {
public:
    int brightestPosition(vector<vector<int>>& lights) {
        vector<pair<int, int>> e;
        for (auto v : lights) {
            e.push_back({v[0] - v[1], 1});
            e.push_back({v[0] + v[1] + 1, -1});
        } 
        sort(e.begin(), e.end());
        int pos = -1;
        int m = 0;
        int cur = 0;
        for (auto p : e) {
            cur += p.second;
            m = max(cur, m); 
        }
        cur = 0;
        for (auto p : e) {
            cur += p.second;

            if (cur == m) {
                return p.first;
            }
        }
        return -1;
    }
};