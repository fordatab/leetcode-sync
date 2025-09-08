class Solution {
public:
    void dfs(int x, int y, vector<vector<int>>& grid, vector<pair<int, int>>& coord, int& sz) {
        if (x < 0 or y < 0 or x >= grid.size() or y >= grid[0].size() or grid[x][y] != 1) {
            return;
        }
        coord.push_back({x, y});
        grid[x][y] = 2;
        sz++;
        dfs(x + 1, y, grid, coord, sz);
        dfs(x - 1, y, grid, coord, sz);
        dfs(x, y + 1, grid, coord, sz);
        dfs(x, y - 1, grid, coord, sz);
    } 
    int largestIsland(vector<vector<int>>& grid) {
        // map coords to idx, size
        map<pair<int, int>, pair<int, int>> coords;
        int idx = 0;
        for (int x = 0; x < grid.size(); x++) {
            for (int y = 0; y < grid[0].size(); y++) {
                if (grid[x][y] == 1) {
                    idx++;
                    int sz = 0;
                    vector<pair<int, int>> coord;
                    dfs(x, y, grid, coord, sz);
                    for (auto p : coord) {
                        coords[p] = {idx, sz};
                    }
                }
            }
        }
        int max_value = INT_MIN; // or some appropriate initial value
        for (const auto& pair : coords) {
            max_value = max(max_value, pair.second.second);
        }
        int out = max_value;
        vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (int x = 0; x < grid.size(); x++) {
            for (int y = 0; y < grid[0].size(); y++) {
                if (grid[x][y] == 0) {
                    set<pair<int, int>> neigh;
                    for (int d = 0; d < 4; d++) {
                        int nx = dir[d][0] + x;
                        int ny = dir[d][1] + y;
                        if (nx < 0 or ny < 0 or nx >= grid.size() or ny >= grid[0].size() or coords.count({nx, ny}) == 0) {
                            continue;
                        } 
                        neigh.insert(coords[{nx, ny}]);
                    }
                    int s = 0;
                    for (auto p : neigh) {
                        s += p.second; 
                    }
                    out = max(out, 1 + s);
                }
            }
        }
        return out;
    }
};