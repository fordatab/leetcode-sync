class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        queue<pair<int, int>> q;
        for (int x = 0; x < rooms.size(); x++) {
            for (int y = 0; y < rooms[0].size(); y++) {
                if (rooms[x][y] == 0) {
                    q.push({x, y});
                }
            }
        }
        int level = 0;
        vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}; 
        while (q.size()) {
            int sz = q.size(); 
            for (int x = 0; x < sz; x++) {
                auto [a, b] = q.front();
                // cout << "start " << a << " " << b << endl;

                q.pop();
                if (rooms[a][b] and rooms[a][b] != INT_MAX) {
                    continue;
                }
                rooms[a][b] = level;
                for (int d = 0; d < 4; d++) {
                    int nx = a + dirs[d][0];
                    int ny = b + dirs[d][1];
                    // cout << nx << " " << ny << " " << level << endl; 
                    if (nx >= 0 and ny >= 0 and nx < rooms.size() and ny < rooms[0].size() and rooms[nx][ny] == INT_MAX) {
                        q.push({nx, ny});
                    }
                }
            }
            level++;
        }
        
    }
};