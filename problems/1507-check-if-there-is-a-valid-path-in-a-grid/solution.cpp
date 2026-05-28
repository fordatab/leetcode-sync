class Solution {
    const vector<vector<bool>> streets = {
        {false, false, false, false}, // 0 (1-indexed padding)
        {false, true,  false, true},  // 1: left, right
        {true,  false, true,  false}, // 2: top, bottom
        {false, false, true,  true},  // 3: left, bottom
        {false, true,  true,  false}, // 4: right, bottom
        {true,  false, false, true},  // 5: left, top
        {true,  true,  false, false}  // 6: right, top
    };

    vector<vector<int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
<<<<<<< HEAD

    void dfs(int r, int c, vector<vector<int>>& grid, vector<vector<bool>>& vis) {
        vis[r][c] = true;
        int m = grid.size();
        int n = grid[0].size();
        
        vector<bool> type = streets[grid[r][c]];
        
        // Check all 4 directions from the current cell
        for (int b = 0; b < 4; b++) {
            int nx = r + dirs[b][0];
            int ny = c + dirs[b][1]; 
            
            // If the current street points in this direction and the neighbor is within bounds
            if (type[b] && nx >= 0 && nx < m && ny >= 0 && ny < n) {
                // If the neighbor points back to us and we haven't visited it yet
                if (streets[grid[nx][ny]][(b + 2) % 4] && !vis[nx][ny]) {
                    dfs(nx, ny, grid, vis);
                }
            }
        } 
=======
    
    // Union-Find parent array
    vector<int> parent;

    // Find with path compression
    int find(int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]);
    }

    // Union two components
    void unite(int i, int j) {
        int rootI = find(i);
        int rootJ = find(j);
        if (rootI != rootJ) {
            parent[rootI] = rootJ;
        }
>>>>>>> 3440cedbebbd4694a83e579928aecd0b6ec10f2d
    }

public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
<<<<<<< HEAD
        // Use a 2D vector instead of a map for O(1) lookups
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        
        // Start DFS from the top-left corner
        dfs(0, 0, grid, vis);
        
        // Return whether we were able to reach the bottom-right corner
        return vis[m - 1][n - 1];
=======
        // Initialize Union-Find array (each cell is its own parent)
        parent.resize(m * n);
        iota(parent.begin(), parent.end(), 0);
        
        // Traverse the entire grid to build the graph
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                vector<bool> type = streets[grid[r][c]];
                
                // Check all 4 directions from the current cell
                for (int b = 0; b < 4; b++) {
                    int nx = r + dirs[b][0];
                    int ny = c + dirs[b][1]; 
                    
                    // If the current street points in this direction and neighbor is within bounds
                    if (type[b] && nx >= 0 && nx < m && ny >= 0 && ny < n) {
                        // If the neighbor points back to us, union them
                        if (streets[grid[nx][ny]][(b + 2) % 4]) {
                            // Convert 2D coordinates to 1D IDs
                            int id1 = r * n + c;
                            int id2 = nx * n + ny;
                            unite(id1, id2);
                        }
                    }
                } 
            }
        }
        
        // Check if top-left (0) and bottom-right (m*n - 1) are in the same component
        return find(0) == find(m * n - 1);
>>>>>>> 3440cedbebbd4694a83e579928aecd0b6ec10f2d
    }
};