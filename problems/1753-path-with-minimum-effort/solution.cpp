class Solution {
private:
    const int dx[4] = {1, 0, -1, 0};
    const int dy[4] = {0, 1, 0, -1};

public:
    int minimumEffortPath(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m));
        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<>> pq;
        
        pq.push({0, 0, 0});
        // visited[0][0] = true;

        while (!pq.empty()) {
            auto [time, x, y] = pq.top();
            // cout << time << " " << x << " " << y << endl;
            pq.pop();

            if (x == n-1 && y == m-1) return time;
            if (visited[x][y]) continue;
            visited[x][y] = true;

            for (int d = 0; d < 4; ++d) {
                int nx = x + dx[d], ny = y + dy[d];
                // cout << nx << " " << ny << endl;
                if (nx >= 0 && ny >= 0 && nx < n && ny < m && !visited[nx][ny]) {

                    // cout << nx << " " << ny << endl;
                    pq.push({max(abs(grid[nx][ny]-grid[x][y]), time), nx, ny});
                }
            }
        }
        
        return -1;
    }
};