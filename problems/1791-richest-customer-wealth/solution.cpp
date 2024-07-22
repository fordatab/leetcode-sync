class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int m = 0;
        for (auto a : accounts) {
            int t = 0;
            for (auto b : a) {
                t+=b;
            }
            m = max(t, m);
        }
        return m;
    }
};