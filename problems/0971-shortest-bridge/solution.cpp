class Solution {
public:
    void dfs(vector<vector<int>>& grid, int x, int y, vector<pair<int,int>>& q, int n) {
        if (x < 0 || y < 0 || x >= n || y >= n || grid[x][y] != 1)
            return;
        grid[x][y] = 2;  // mark first island as 2
        q.push_back({x, y});
        dfs(grid, x + 1, y, q, n);
        dfs(grid, x - 1, y, q, n);
        dfs(grid, x, y + 1, q, n);
        dfs(grid, x, y - 1, q, n);
    }

    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<pair<int,int>> q;
        bool found = false;

        // Color the first island and add all its cells to queue
        for (int i = 0; i < n && !found; i++) {
            for (int j = 0; j < n && !found; j++) {
                if (grid[i][j] == 1) {
                    dfs(grid, i, j, q, n);
                    found = true;
                }
            }
        }

        vector<vector<int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
        int steps = 0;
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                auto [x, y] = q[i];
                for (auto &d : dirs) {
                    int nx = x + d[0], ny = y + d[1];
                    if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                    if (grid[nx][ny] == 1) return steps; // reached second island
                    if (grid[nx][ny] == 0) {
                        grid[nx][ny] = 2;
                        q.push_back({nx, ny});
                    }
                }
            }
            q.erase(q.begin(), q.begin() + sz);
            steps++;
        }

        return -1;
    }
};
