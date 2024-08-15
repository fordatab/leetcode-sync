class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> c(n);
        vector<int> r(n);
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < n; y++) {
                c[y] = max(c[y], grid[x][y]);
                r[x] = max(r[x], grid[x][y]);
            }
        }
        int o = 0;
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < n; y++) {
                o += min(r[x], c[y]) - grid[x][y];
            }
        }
        return o;
    }
};