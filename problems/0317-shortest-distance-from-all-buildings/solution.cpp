class Solution {
public:
    void bfs(vector<vector<int>>& grid, int m, int n, vector<vector<int>>& total, vector<vector<int>>& reach, int x, int y) {
        vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        vector<vector<int>> di(m, vector<int>(n));
        queue<pair<int, int>> q;
        q.push({x, y});

        int level = 1;
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto p = q.front();
                q.pop();

                for (int d = 0; d < 4; d++) {
                    int nx = p.first + dirs[d][0];
                    int ny = p.second + dirs[d][1];
                    if (nx >= 0 and nx < m and ny >= 0 and ny < n and di[nx][ny] == 0 and grid[nx][ny] == 0) {
                        reach[nx][ny]++;
                        total[nx][ny] += level;
                        di[nx][ny] = level;
                        q.push({nx, ny});
                    }
                } 
            }
            level++;
        }
    }
    
    int shortestDistance(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> reach(m, vector<int>(n));
        vector<vector<int>> total(m, vector<int>(n));
        int ct = 0;
        for (int x = 0; x < m; x++) {
            for (int y = 0; y < n; y++) {
                if (grid[x][y] == 1) {
                    bfs(grid, m, n, total, reach, x, y);
                    ct++;
                }

            }
        }
        int out = INT_MAX;
        for (int x = 0; x < m; x++) {
            for (int y = 0; y < n; y++) {
                if (reach[x][y] == ct) {
                    out = min(out, total[x][y]);
                }
            }
        }
        return out == INT_MAX ? - 1: out;
    }
};