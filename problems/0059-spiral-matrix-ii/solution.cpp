class Solution {
private:
    const int dx[4] = {0, 1, 0, -1};  // right, down, left, up
    const int dy[4] = {1, 0, -1, 0};

public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> out(n, vector<int> (n, 0));
        int i = 0, j = 0, dir = 0;
        for (int x = 1; x <= n*n; x++) {
            out[i][j] = x;
            int ni = i + dx[dir];
            int nj = j + dy[dir];

            if (ni < 0 || ni >= n || nj < 0 || nj >= n || out[ni][nj]) {
                dir = (dir + 1) % 4;  // Change direction
                ni = i + dx[dir];
                nj = j + dy[dir];
            }

            i = ni;
            j = nj;
        }
        return out;
    }
};


// class Solution {


// public:
//     vector<int> spiralOrder(vector<vector<int>>& matrix) {
//         int m = matrix.size();
//         int n = matrix[0].size();
//         vector<int> out (m*n);
//         vector<vector<bool>> visited(m, vector<bool>(n, false));
        
//         int i = 0, j = 0, dir = 0;
        
//         for (int x = 0; x < m * n; x++) {
//             out[x] = matrix[i][j];
//             visited[i][j] = true;
            
//             // int a = i + dx[dir];
//             // int ni = a;
//             j += dy[dir];
//             i += dx[dir];
//             if (i < 0 || i >= m || j < 0 || j >= n || visited[i][j]) {
//                 dir = (dir + 1) % 4;
//                 i += dx[dir];
//                 j += dx[dir];
//             }
            
//             // i = ni;
//         }
        
//         return out;
//     }
// };