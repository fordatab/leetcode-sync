class Solution {
    
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int out = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    dfs(grid, out, m, n, i, j);
                    return out;
                }
            }
        }
        return -1;
    }

    void dfs(vector<vector<int>>& grid, int & res, int m, int n, int i, int j) {
        if (i < 0 || j < 0 || i > m - 1 || j > n - 1 || grid[i][j] != 1) {
            return;
        }
        grid[i][j] = -1;
        res +=  (j + 1 >= n || grid[i][j+1] == 0) + 
                (i - 1 < 0  || grid[i-1][j] == 0) + 
                (j - 1 < 0  || grid[i][j-1] == 0) +
                (i + 1 >= m || grid[i+1][j] == 0);
        dfs(grid, res, m, n, i, j+1 );
        dfs(grid, res, m, n, i + 1, j);
        dfs(grid, res, m, n, i-1, j);
        dfs(grid, res, m, n, i, j-1);

    }
};