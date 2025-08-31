class Solution {
public:

    void dfs(int i, int j, int m, int n, vector<pair<int, int>>& shape, vector<vector<int>>& grid, char prev) {
        if (m < 0 or n < 0 or m >= grid.size() or n >= grid[0].size() or grid[m][n] == 0) {
            return;
        }
        grid[m][n] = 0;
        shape.push_back({m - i, n - j});
        dfs(i, j, m + 1, n, shape, grid, 'r');
        dfs(i, j, m - 1, n, shape, grid, 'l');
        dfs(i, j, m, n + 1, shape, grid, 'd');
        dfs(i, j, m, n - 1, shape, grid, 'u');

    }
    int numDistinctIslands(vector<vector<int>>& grid) {
        set<vector<pair<int, int>>> shapes;
        for (int x = 0; x < grid.size(); x++) {
            for (int y = 0; y < grid[0].size(); y++) {
                if (grid[x][y] == 1) {
                    vector<pair<int, int>> shape;
                    dfs(x, y, x, y, shape, grid, 's');
                    shapes.insert(shape);
                }
            }
        }
        return shapes.size();
    }
};