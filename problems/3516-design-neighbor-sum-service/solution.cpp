class neighborSum {
private:
    vector<vector<int>> grid;
    const int dx[4] = {1, 0, -1, 0};
    const int dy[4] = {0, 1, 0, -1}; 
    const int dxz[4]= {1, 0, -1, 0};
    const int dyz[4]= {0, -1, 0, 1};

public:
    neighborSum(vector<vector<int>>& grid) {
        this->grid = grid;
    }
    
    int adjacentSum(int value) {
        int i = -1;
        int j = -1;
        for (int x = 0; x < grid.size(); x++) {
            for (int y = 0; y < grid[0].size(); y++) {
                if (grid[x][y] == value) {
                    i = x;
                    j = y;
                    break;
                }
            }
        }
        int t = 0;
        for (int f = 0; f < 4; f++) {
            int n_i = i + dx[f];
            int n_j = j + dy[f];
            if (n_i >= 0 && n_i < grid.size() && n_j >=0 && n_j <grid[0].size()) {
                t += grid[n_i][n_j];
            }
        }
        return t;
    }
    
    int diagonalSum(int value) {
        int i = -1;
        int j = -1;
        for (int x = 0; x < grid.size(); x++) {
            for (int y = 0; y < grid[0].size(); y++) {
                if (grid[x][y] == value) {
                    i = x;
                    j = y;
                    break;
                }
            }
        }
        int t = 0;
        cout << i << " " << j << endl;
        cout << endl;
        for (int f = 0; f < 4; f++) {
            int n_i = i + dx[f] + dyz[f];
            int n_j = j + dy[f] + dxz[f];
            cout << n_i << " " << n_j << endl;
            if (n_i >= 0 && n_i < grid.size() && n_j >=0 && n_j <grid[0].size()) {
                t += grid[n_i][n_j];
            }
        }
        return t;
    }
};

/**
 * Your neighborSum object will be instantiated and called as such:
 * neighborSum* obj = new neighborSum(grid);
 * int param_1 = obj->adjacentSum(value);
 * int param_2 = obj->diagonalSum(value);
 */