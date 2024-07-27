class Solution {
private:
    // Direction arrays
    const int dx[4] = {0, 1, 0, -1};  // right, down, left, up
    const int dy[4] = {1, 0, -1, 0};

public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> out (m*n);
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        int i = 0, j = 0, dir = 0;
        
        for (int x = 0; x < m * n; x++) {
            out[x] = matrix[i][j];
            visited[i][j] = true;
            
            int ni = i + dx[dir];
            int nj = j + dy[dir];
            
            if (ni < 0 || ni >= m || nj < 0 || nj >= n || visited[ni][nj]) {
                dir = (dir + 1) % 4;
                ni = i + dx[dir];
                nj = j + dy[dir];
            }
            
            i = ni;
            j = nj;
        }
        
        return out;
    }
};