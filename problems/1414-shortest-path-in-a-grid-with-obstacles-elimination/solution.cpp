class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size(); 
        vector<vector<vector<int>>> dist(m, vector<vector<int>> (n, vector<int> (k + 1, -1)));
        queue<tuple<int, int, int>> q;
        q.push({0, 0, 0});  
        dist[0][0][0] = 0;
        
        vector<vector<int>> dirs = {{-1,0}, {1,0}, {0,1}, {0,-1}};
        int steps = 0;
        
        while (!q.empty()) {
            int s = q.size();
            while (s--) {
                auto [x, y, broken] = q.front(); q.pop();
                
                if (x == m-1 && y == n-1) return steps;
                
                for (auto& d : dirs) {
                    int nx = x + d[0], ny = y + d[1];
                    if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
                    
                    if (grid[nx][ny] == 0 && dist[nx][ny][broken] == -1) {
                        dist[nx][ny][broken] = steps + 1;
                        q.push({nx, ny, broken});
                    }
                    else if (grid[nx][ny] == 1 && broken < k && dist[nx][ny][broken+1] == -1) {
                        dist[nx][ny][broken+1] = steps + 1;
                        q.push({nx, ny, broken+1});
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};
