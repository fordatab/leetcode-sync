class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        const int dx[4] = {1, 0, -1, 0};
        const int dy[4] = {0, 1, 0, -1};
        int m = grid.size();
        int n = grid[0].size();
        int t = 0;

        for (int x = 0; x < m; x++) {
            for (int y = 0; y < n; y++) {
                if (grid[x][y] == 2) {
                    q.push({x, y});
                }
                if (grid[x][y] == 1) {
                    t++;
                }
            }
        }

        int time = 0;
        while (t && !q.empty()) {
            int s = q.size();
            for (int l = 0; l < s; l++) {
                auto p = q.front();
                q.pop();
                for (int d = 0; d < 4; d++) {
                    int x = p.first + dx[d];
                    int y = p.second + dy[d];
                    if (x >= 0 && y >= 0 && x < m && y < n && grid[x][y] == 1) {
                        t--;
                        grid[x][y] = 2;
                        q.push({x, y});
                    }
                }
            }               
            time++;
        }
        return !t ? time : -1;
    }
};
