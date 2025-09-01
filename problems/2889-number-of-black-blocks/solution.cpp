class Solution {
public:
    vector<long long> countBlackBlocks(int m, int n, vector<vector<int>>& coordinates) {
        vector<long long> out(5);
        set<pair<int, int>> black;
        for (auto p : coordinates) {
            black.insert({p[0], p[1]});
        }
        map<pair<int, int>, int> blocks;
        for (auto it = black.begin(); it != black.end(); ++it) {
            auto p = *it;
            int x = p.first;
            int y = p.second;
            for (int i = 0; i < 0 + 2; i++) {
                for (int j = 0; j < 0 + 2; j++) {
                        int a = x - i;
                        int b = y - j;
                        if (a >= 0 && b >= 0 && a < m - 1 && b < n - 1) {
                            blocks[{a, b}]++;
                        }
                }
            }                       
        } 
        for (auto it = blocks.begin(); it != blocks.end(); ++it) {
            out[it->second]++;
        }
        long long total = (long long)(m -1)*(n-1);
        long long zero = total - accumulate(out.begin(), out.end(), 0LL);
        out[0] = zero;
        return out;
    }
};