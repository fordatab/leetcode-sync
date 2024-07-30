class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int out = 0;
        for (int x = 0; x < r; x++) {
            for (int y = 0; y < c; y++) {
                if (grid[x][y] == 1) {
                    out = max(dfs(grid, x, y, r, c), out);
                }
            }
        }
        return out;
    }

    int dfs(vector<vector<int>>& grid, int x, int y, int r, int c) {
        if (x < 0 || y < 0 || x >= r || y >= c || grid[x][y] == 0) {
            return 0;
        }
        grid[x][y] = 0;
        return 1 + 
                dfs(grid, x + 1, y, r, c) +
                dfs(grid, x - 1, y, r, c) +
                dfs(grid, x, y + 1, r, c) +
                dfs(grid, x, y - 1, r, c);
    }
};
