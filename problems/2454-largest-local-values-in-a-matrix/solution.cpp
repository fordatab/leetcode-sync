class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> out(n-2, vector<int>(n-2));
        for (int x = 1; x < n-1; x++) {
            for (int y = 1; y < n-1; y++) {
                int m = 0;
                for (int i = x - 1; i < x + 2; i++) {
                    for (int j = y - 1; j < y + 2; j++) {
                        m = max(m, grid[i][j]);
                    }
                }
                out[x-1][y-1] = m;
            }
        }
        return out;
    }
};