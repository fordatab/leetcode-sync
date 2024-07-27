class Solution {
    private:
        const int dx[4] = {0, 1, 0, -1};  // right, down, left, up
        const int dy[4] = {1, 0, -1, 0};

    public:
        vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {
            vector<vector<int>> result;
            int totalCells = R * C;
            int i = r0, j = c0, dir = 0;
            int steps = 1;

            result.push_back({i, j});
            
            while (result.size() < totalCells) {
                for (int d = 0; d < 4; d++) { // Each direction
                    for (int s = 0; s < steps; s++) {
                        i += dx[dir];
                        j += dy[dir];
                        if (i >= 0 && i < R && j >= 0 && j < C) {
                            result.push_back({i, j});
                        }
                    }
                    dir = (dir + 1) % 4;
                    if (d == 1 || d == 3) steps++;
                }
            }

            return result;
        }
};