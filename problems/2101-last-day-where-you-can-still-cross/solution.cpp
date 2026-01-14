class Solution {
public:
    vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int row;
    int col;
    bool check(vector<vector<int>>& matrix) {
        queue<pair<int, int>> q;
        vector<vector<int>> visited(row, vector<int>(col));

        for (int x = 0; x < col; x++) {
            if (matrix[0][x] != 1) {
                q.push({0, x});
                visited[0][x] = 1;

            }
        }

        while (q.size()) {
            auto front = q.front();
            q.pop();
            if (front.first == row - 1) {
                return true;
            }
            for (int d = 0; d < 4; d++) {
                int nx = front.first + dirs[d][0];
                int ny = front.second + dirs[d][1];
                if (nx >= 0 and nx < row and ny >= 0 and ny < col and !visited[nx][ny] and !matrix[nx][ny]) {
                    visited[nx][ny] = 1;
                    q.push({nx, ny});
                }
            } 
        }
        return false;
    }

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        this->row = row;
        this->col = col;
        int ct = 0;

        int l = 0;
        int r = cells.size() - 1;
        int out = 0; 
        while (l <= r) {
            int mid = l + (r - l)/2;
            vector<vector<int>> matrix(row, vector<int>(col));

            for (int i = 0; i <= mid; i++) {
                matrix[cells[i][0] - 1][cells[i][1] - 1] = 1;
            }  
            if (check(matrix)) {
                out = max(mid, out); 
                l = mid + 1; 
            } else {
                r = mid - 1;
            }
        }
        return out + 1;

        // return ct;
    }
};