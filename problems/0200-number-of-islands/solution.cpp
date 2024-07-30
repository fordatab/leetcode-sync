class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int out = 0;
        int r = grid.size();
        int c = grid[0].size();
        for (int x = 0; x < r; x++) {
            for (int y = 0; y < c; y++) {
                if (grid[x][y] == '1') {
                    dfs(grid, x, y, r, c);
                    out++;
                }
            }
        }
        return out;
    }
private:
    void dfs(vector<vector<char>>& grid, int i, int j, int m, int n) {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == '0') {
            return;
        }
        grid[i][j] = '0';
        
        dfs(grid, i - 1, j, m, n);
        dfs(grid, i + 1, j, m, n);
        dfs(grid, i, j - 1, m, n);
        dfs(grid, i, j + 1, m, n);
    }
};
