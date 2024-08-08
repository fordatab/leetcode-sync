class Solution {
private:
    const int dx[4] = {1, 0, -1, 0};
    const int dy[4] = {0, 1, 0, -1};
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        return bfs(maze, entrance[0], entrance[1], maze.size(), maze[0].size());
    }

    int bfs(vector<vector<char>>& maze, int x, int y, int m, int n) {
        queue<pair<int, int>> q;
        q.push({x, y});
        vector<vector<bool>> v(m, vector<bool>(n));
        v[x][y] = true;
        int level = 0;
        while(!q.empty()) {
            int s = q.size();
            level++;
                        cout << endl;
           //  cout << a << " top " <<b << endl;
            cout << level << endl;
            while(s--) {
                            auto [a, b] = q.front();

                            q.pop();

                for (int d = 0; d < 4; d++) {
                    int i = a + dx[d];
                    int j = b + dy[d];
                    cout << i << " " << j << endl;
                    if (i < 0 || j < 0 || i >= m || j >= n) {
                        continue;
                    }
                    if (maze[i][j] == '+') {
                        continue;
                    }

                    if (!v[i][j]) {
                        if (i == 0 || j == 0 || i == m-1 || j == n-1) {
                            return level;
                        }
                        q.push({i, j});
                        v[i][j] = true;
                    }
                }
            }
        }
        return -1;
    }
};